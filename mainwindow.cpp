#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDateTime>
#include<QDebug>
#include<QFile>
#include<DialogChooseNew.h>
#include <fstream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);
    m_re = new RecordSelection();
    mDialog = new talkDialog(this);
    mDialog->hide();
    connect(mDialog,&talkDialog::SigCloseDialog,this,&MainWindow::on_startBtn_clicked);
    connect(this,&MainWindow::sigSentEventId,mDialog,&talkDialog::sltGetEventId);
    mJData5 =  m_re->OpenJsonToObj("5");
    mJDataPlayer = m_re->OpenJsonToObj("player");
    if(!mJDataPlayer.empty())
    {
        ui->startBtn->setText("continue");
    }
    else
    {
        ui->startBtn->setText("new");
    }
    qDebug()<< findEligibleEvent();

//    m_re->setDataTo5();
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

QList<int> MainWindow::findEligibleEvent()
{
    QJsonObject dataValues = mJDataPlayer["data"].toObject();
    QJsonArray rulesArray = m_re->OpenJsonToObj("rule")["data"].toArray();
    // 存储符合条件的"eventNum"
    QList<int> eventNums;
    // 遍历每个规则
    for (int i = 0; i < rulesArray.size(); ++i) {
        QJsonObject ruleObj = rulesArray[i].toObject();
        // 获取"dataRule"字段的值
        QJsonObject ruleValues = ruleObj["dataRule"].toObject();
        // 检查"data"字段
        bool condition = true;
        for (auto it = ruleValues.begin(); it != ruleValues.end(); ++it) {

            if(dataValues.contains(it.key()))
            {
                if (dataValues[it.key()].type() == QVariant::Int && ruleValues[it.key()].type() == QVariant::Int) {
                    if (dataValues[it.key()].toInt() < ruleValues[it.key()].toInt()) {
                        condition = false;
                        break;
                    }
                } else if (dataValues[it.key()].type() == QVariant::String && ruleValues[it.key()].type() == QVariant::String) {
                    if (dataValues[it.key()].toString() != ruleValues[it.key()].toString()) {
                        condition = false;
                        break;
                    }
                } else {
                    // 数据类型不匹配，根据实际需求进行处理
                    // 这里假设当数据类型不匹配时，条件为 false
                    condition = false;
                    break;
                }
            }
            if(mJDataPlayer.contains(it.key()))
            {
                qDebug()<<mJDataPlayer[it.key()]<<it.value()<<it.key();
                if (mJDataPlayer[it.key()].type() == QVariant::Int && ruleValues[it.key()].type() == QVariant::Int) {
                    if (mJDataPlayer[it.key()].toInt() < ruleValues[it.key()].toInt()) {
                        condition = false;
                        break;
                    }
                } else if (dataValues[it.key()].type() == QVariant::String && ruleValues[it.key()].type() == QVariant::String) {
                    if (mJDataPlayer[it.key()].toString() != ruleValues[it.key()].toString()) {
                        condition = false;
                        break;
                    }
                } else {
                    // 数据类型不匹配，根据实际需求进行处理
                    // 这里假设当数据类型不匹配时，条件为 false
                    condition = false;
                    break;
                }
            }
        }
        // 如果所有值都满足条件，记录该规则的"eventNum"
        if (condition) {
            eventNums.append(ruleObj["eventNum"].toInt());
        }
    }
    emit sigSentEventId(eventNums);
    // 返回所有符合条件的"eventNum"
    return eventNums;

}

void MainWindow::CheckCurrentStatus()
{
    if(mJDataPlayer["date"].toInt() == 1 && mJDataPlayer["ActionPoints"].toInt() == 0)
    {

    }
    else if(mJDataPlayer["date"].toInt() >> 1 && mJDataPlayer["ActionPoints"].toInt() == 0)
    {
        findEligibleEvent();

    }else if(mJDataPlayer["AdditionalActionPoints"].toInt() == 1)
    {
    }
    else if(mJDataPlayer["ActionPoints"].toInt() << 3)
    {
        findEligibleEvent();
    }
    else if(mJDataPlayer["ActionPoints"].toInt() == 3)
    {

    }

}

void MainWindow::on_startBtn_clicked()
{
    if(ui->startBtn->text()=="new")
    {
       DialogChooseNew *dlg = new DialogChooseNew();
       connect(dlg,&DialogChooseNew::sigChosen,this,&MainWindow::sltCreateNewPlayer);
       dlg->show();

    }
    else
    {
    if (mDialog->isHidden()) {
        // 如果新窗口当前为隐藏状态，则切换到新窗口
        mDialog->show();
        hide();  // 隐藏主窗口
    } else {
        // 如果新窗口当前为显示状态，则切换回主窗口
        show();  // 显示主窗口
        mDialog->hide();
    }
    CheckCurrentStatus();
    }

}



void MainWindow::updateRecord()
{
//    m_re->getDataBy5();
//    m_re->saveDataToJson("5");
    
//    m_re->getDataByPlayer();
//    m_re->saveDataToJson("player");
}

void MainWindow::sltSaveSelection()
{
    mJsonHistoryData["time"] =  QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString filePath = qApp->applicationDirPath();
    QString strFile = filePath +"/JsonData/"+ historyName + ".json";
    QFile file(strFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "can't open error!";
        return;
    }
    QJsonDocument jsonDoc(mJsonHistoryData);
    QByteArray jsonDataBytes = jsonDoc.toJson();

    QTextStream stream(&file);
    stream.setCodec("UTF-8");    // 设置写入编码为UTF-8
    stream << jsonDataBytes;     // 将JSON数据写入文件
    file.close();
}

void MainWindow::sltCreateNewPlayer(QString str, bool type)
{
    qDebug()<<str<<type;
    if(type==true)
    {
        QJsonObject obj = m_re->OpenJsonToObj(str);
        m_re->saveDataToJson("player",obj);
        mDialog->show();
        hide();  // 隐藏主窗口
    }
    else
    {
        QJsonObject obj = m_re->OpenJsonToObj("character");
        obj["name"] = str;
        m_re->saveDataToJson("player",obj);
        mDialog->show();
        hide();  // 隐藏主窗口
    }
    ui->startBtn->setText("continue");

}

void MainWindow::on_closeBtn_clicked()
{
    close();
}

void MainWindow::on_newBtn_clicked()
{
    QString filePath = qApp->applicationDirPath();
    QString strFile = filePath +"/JsonData/player.json";

    std::ofstream ofs(strFile.toStdString(), std::ios::out | std::ios::trunc);
    ofs.close();
    ui->startBtn->setText("new");

}
