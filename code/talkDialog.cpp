#include "talkDialog.h"
#include "ui_talkDialog.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QJsonParseError>
#include<QJsonArray>
#include<QLabel>
#include<random>
talkDialog::talkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::talkDialog)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::FramelessWindowHint);
    ui->listWidget->hide();
    ui->widgetChoose->hide();
    ui->closeHistory->hide();

    //    connect(ui->optionBtn,&QPushButton::clicked,this,&talkDialog::rightBtnClicked);
    //  	connect(ui->optionBtn2,&QPushButton::clicked,this,&talkDialog::rightBtnClicked);
    //  	connect(ui->optionBtn3,&QPushButton::clicked,this,&talkDialog::rightBtnClicked);

}

talkDialog::~talkDialog()
{
    delete ui;
}


// 定义一个函数，接收一个名字和文件路径，并将文件中的对话读取出来返回
QJsonArray talkDialog::readDialogueFromFile( QString name, QString filePath)
{
    QFile file( qApp->applicationDirPath()+ filePath + name + ".json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << filePath+name+".json";

    }
    QString value = file.readAll();
    file.close();
    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(), &parseJsonErr);
    if(!(parseJsonErr.error == QJsonParseError::NoError))
    {
        qDebug() << parseJsonErr.errorString();
    }
    //qDebug()<<document;
    nTextListSize = document.array().size();

    return document.array();
}

Dialogue talkDialog::getDialogueFromJson(const QJsonObject& jsonObj)
{
    Dialogue dialogue;
    foreach (const QString& key, jsonObj.keys()) {
        if (key == "speaker") {
            dialogue.speaker = jsonObj.value(key).toString();
        } else if (key == "content") {
            dialogue.content = jsonObj.value(key).toString();
        }
    }
    return dialogue;
}

Dialogue talkDialog::getNthDialogueFromFile(int n)
{
    QJsonObject nthDialogueJson = mText.at(n).toObject();
    //qDebug()<<"getNthDialogueFromFile"<<nthDialogueJson<<n;
    return getDialogueFromJson(nthDialogueJson);
}

void talkDialog::on_nextBtn_clicked()
{
    if(nTextListNum<nTextListSize)
    {
    mUe =  getNthDialogueFromFile(nTextListNum);
    nTextListNum++;
    QString speaker;//姓名替换
    if(mUe.speaker == "player")
        speaker = mPlayerName;
    else
        speaker = mUe.speaker;
    QString str = speaker + "\n" + mUe.content;
    ui->textContent->setText(str);
    mTextHistory.append(str);
    qDebug()<<"nextBtn"<<str<<nTextListNum;
    }
    else
    {
        //对话完成，进行记录，重新查询当前状态
        nTextListNum = 0;
        ui->textContent->clear();
        mTextHistory.clear();
        if(nEventId!=0){//事件
            emit sigEventLog(nEventId);
            nEventId = 0;
        }else//非事件
        {
            emit sigEventLog(0);
            emit sigCheckCurrentStatus();
        }
    }

}

void talkDialog::on_closeBtn_clicked()
{
    if(b_ShowState == true)//已选择事件
    {//保存当前进度

    }
    emit SigCloseDialog();
}

void talkDialog::generateButtonsFromMap(const QMap<int, QString>& data, QWidget* parentWidget)
{
    // 创建一个透明背景的全屏窗口
    QWidget* overlayWidget = new QWidget(parentWidget);
    overlayWidget->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    overlayWidget->setAttribute(Qt::WA_TranslucentBackground);
    overlayWidget->setStyleSheet("background-color: rgba(0, 0, 0, 150);");
    overlayWidget->showFullScreen();

    // 计算按钮区域的大小和位置
    QSize overlaySize = overlayWidget->size();
    int buttonWidth = 200;
    int buttonHeight = 50;
    int buttonSpacing = 20;
    int totalButtonHeight = data.size() * (buttonHeight + buttonSpacing) - buttonSpacing;

    int x = (overlaySize.width() - buttonWidth) / 2;
    int y = (overlaySize.height() - totalButtonHeight) / 2;

    // 生成按钮
    for (const auto& key : data.keys()) {
        QPushButton* button = new QPushButton(data.value(key), overlayWidget);
        button->setFixedWidth(buttonWidth);
        button->setFixedHeight(buttonHeight);
        button->move(x, y);

        y += buttonHeight + buttonSpacing;
    }
}


void talkDialog::on_historyBtn_clicked()
{
//    if(ui->listWidget->isHidden())
//    {
        ui->listWidget->show();
        ui->historyBtn->hide();
        ui->closeHistory->show();
        ui->closeBtn->hide();
        ui->textContent->hide();
        ui->nextBtn->hide();
        ui->listWidget->clear(); // 清空列表控件

        for (const QString &text : mTextHistory) {
            QListWidgetItem *item = new QListWidgetItem(text);
            ui->listWidget->addItem(item);
        }
//    }
//    else{
//        ui->listWidget->hide();
//        ui->historyBtn->show();
//    }
}

void talkDialog::rightBtnClicked(int n)
{
    nEventId = nIdChoose.at(n-1);
    sltShowEvent(QString::number(nEventId));
    qDebug()<<n;
    if(b_ShowState == false)
    widgetChange();
}

void talkDialog::on_optionBtn_clicked()
{
    rightBtnClicked(1);
}

void talkDialog::on_optionBtn2_clicked()
{
    rightBtnClicked(2);
}

void talkDialog::on_optionBtn3_clicked()
{
    rightBtnClicked(3);
}

void talkDialog::widgetChange()
{
    qDebug()<<"widgetChange"<<b_ShowState;
    if(b_ShowState == false)
    {
        ui->widget->show();
        ui->widgetChoose->hide();
        b_ShowState = true;
    }
    else
    {
        ui->widget->hide();
        ui->widgetChoose->show();
        b_ShowState = false;
    }
}


//取3个随机数
QList<int> talkDialog::getThreeRandomNumbers( QList<int> nums)
{
    QList<int> res;
    if (nums.size() < 3) {
        return nums; // 数组长度小于3，返回目前所有的
    }
    std::random_device rd;
    // 使用 std::mt19937 引擎以获取更好的随机性
    std::mt19937 generator(rd());
    // 创建一个分布对象，指定生成整数的范围为 [0, 数组长度)
    std::uniform_int_distribution<int> distribution(0, nums.size() - 1);
    QSet<int> usedIndices; // 用于存储已使用的下标

    while (usedIndices.size() < 3) {
        int index = distribution(generator); // 生成一个随机下标
        if (!usedIndices.contains(index)) {
            usedIndices.insert(index);
            res.push_back(nums[index]);
        }
    }
    //    for (int i = 0; i < 3; ++i) { // 循环3次，每次随机选取一个数字
    //        int index = distribution(generator); // 生成一个随机下标
    //        res.push_back(nums[index]);
    //    }
    return res; // 返回包含三个随机数的向量
}

void talkDialog::setPlayerName(QString name)
{
    mPlayerName = name;
}

void talkDialog::sltGetEventId(QList<EventInfo> idList)
{
    QList<int> eventIdList;
    for (const EventInfo &eventInfo : idList) {
        eventIdList.append(eventInfo.eventNum);
    }
    nIdChoose = getThreeRandomNumbers(eventIdList);
    for (int i = 0; i < nIdChoose.size(); ++i) {
        int eventNum = nIdChoose.at(i);
        QString eventInfoStr;

        for (const EventInfo &eventInfo : idList) {
            if (eventInfo.eventNum == eventNum) {
                eventInfoStr = eventInfo.description;
            }
        }
        //qDebug()<<nIdChoose.size();
        switch (i) {
        case 0:
        {

            ui->eventName1->setText(eventInfoStr);
            break;
        }
        case 1:
        {
            ui->eventName2->setText(eventInfoStr);
            break;
        }
        case 2:
        {
            ui->eventName3->setText(eventInfoStr);
            break;
        }
        default:
        {
            qDebug()<<"sltGetEventId reeor";
            break;
        }
        }
    }
    if(b_ShowState == true)//切换到选择窗口
        widgetChange();

}

void talkDialog::sltShowEvent(QString eventName)
{
    if(b_ShowState == false)
        widgetChange();
    ui->historyBtn->show();
    ui->closeBtn->show();
    mText = readDialogueFromFile(eventName,"/../../text/");
    on_nextBtn_clicked();
}

void talkDialog::sltShowCut(QString cutName)
{//切换到文本窗口
    if(b_ShowState == false)
        widgetChange();
    ui->historyBtn->hide();
    ui->closeBtn->hide();
    mText = readDialogueFromFile(cutName,"/../../text/");
    on_nextBtn_clicked();
}



void talkDialog::on_closeHistory_clicked()
{
    ui->listWidget->hide();
    ui->historyBtn->show();
    ui->closeHistory->hide();
    ui->closeBtn->show();
    ui->textContent->show();
    ui->nextBtn->show();
}
