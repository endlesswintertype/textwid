#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDateTime>
#include<QDebug>
#include<QFile>
#include<QMessageBox>

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
    //关闭对话框回到主界面
    connect(mDialog, &talkDialog::SigCloseDialog, this, &MainWindow::on_startBtn_clicked);
    //状态检查
    connect(mDialog, &talkDialog::sigCheckCurrentStatus, this, &MainWindow::CheckCurrentStatus);
    //事件id列表
    connect(this, &MainWindow::sigSentEventId, mDialog, &talkDialog::sltGetEventId);
    //保存事件历史
    connect(mDialog, &talkDialog::sigEventLog, this, &MainWindow::saveEventLog);
    QString path = "/../../play/";
    //初始化5
    mJData5 = m_re->OpenJsonToObj(path + "5");
    //初始化player
    mJDataPlayer = m_re->OpenJsonToObj(path + "player");
    if (!mJDataPlayer.empty())//如果已存在player，显示继续，否则显示新开始
    {
        ui->startBtn->setText("continue");
        //加载事件列表
        mJDataEvent = m_re->OpenJsonToObj(path + "event");
        //初始化本日信息。
        mJsonHistoryData = m_re->OpenJsonToObj(path + "history");
        mDay.date = mJsonHistoryData["date"].toInt();

        //传递player姓名到talkdialog
        mDialog->setPlayerName(mJDataPlayer["name"].toString());
        //CheckCurrentStatus();
        //findEligibleEvent();
    }
    else
    {
        ui->startBtn->setText("new");
        ui->newBtn->setEnabled(false);//无旧player，删除不可用


    }
    //    m_re->setDataTo5();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//随机选取符合条件的事件
QList<EventInfo>  MainWindow::findEligibleEvent()
{
    QJsonObject dataValues = mJDataPlayer["data"].toObject();
    QJsonArray eventArray = mJDataEvent["data"].toArray();
    // 存储符合条件的"eventNum"和简介
    QList<EventInfo> eventInfos;
    // 遍历每个规则
    for (int i = 0; i < eventArray.size(); ++i) {
        QJsonObject eventObj = eventArray[i].toObject();
        // 获取"eventData"字段的值

        QJsonObject eventValues = eventObj["eventData"].toObject();
        // 检查"data"字段
        //qDebug()<<eventValues;
        bool condition = true;
        for (auto it = eventValues.begin(); it != eventValues.end(); ++it) {

            if (eventValues.contains(it.key()))
            {//和player的数据对比
                //qDebug()<<eventValues[it.key()]<<it.key();
                //数值对比
                if (eventValues[it.key()].type() != QVariant::String &&
                        dataValues.contains(it.key())) {
                    if (eventValues[it.key()].toInt() > dataValues[it.key()].toInt()) {
                        condition = false;
                        break;
                    }
                    else if(it.key() == "date" &&
                            eventValues[it.key()].toInt()>mDay.date )
                    {
                        condition = false;
                        break;
                    }
                }//字符串对比
                else if (eventValues[it.key()].type() == QVariant::String) {
                    if (eventValues[it.key()].toString() !=
                            dataValues[it.key()].toString()) {
                        condition = false;
                        break;
                    }//每日限制单独处理
                    else if(it.key() == "weather" && eventValues[it.key()].toString()!=mDay.weather )
                    {
                        condition = false;
                        break;
                    }

                }
                else {
                    // 数据类型不匹配，根据实际需求进行处理
                    // 这里假设当数据类型不匹配时，条件为 false
                    //condition = false;
                    //break;
                }
            }

        }
        // 如果所有值都满足条件，记录该规则的"eventNum"
        if (condition) {
            EventInfo eventInfo;
            eventInfo.eventNum = eventObj["eventNum"].toInt();
            eventInfo.description = eventValues["info"].toString(); // 设置简介文字
            eventInfos.append(eventInfo);
            //qDebug()<<eventValues["info"].toString();

        }
    }

    emit sigSentEventId(eventInfos);
    // 返回所有符合条件的"eventNum"
    return eventInfos;

}

//当前玩家状态检查
void MainWindow::CheckCurrentStatus()
{
    //当日第一个行动开始前
    if ( mJsonHistoryData["ActionPoints"].toInt() == 0)
    {
        if(mDay.date == 1)//第一天特殊处理
        {
            mDialog->sltShowCut("CutFirst");

        }
        else{
            mDialog->sltShowCut("CutNormal");
        }
    updateJsonInt(mJsonHistoryData,"ActionPoints", mJsonHistoryData["ActionPoints"].toInt() + 1);

    }//当日第一个行动
    else if (mJsonHistoryData["ActionPoints"].toInt() == 1)
    {
        findEligibleEvent();

    }//当日第二个行动
    else if (mJsonHistoryData["ActionPoints"].toInt() == 2)
    {
        findEligibleEvent();

    }//当日结束
    else if (mJsonHistoryData["ActionPoints"].toInt() == 3)
    {
        if(mDay.date == 3)//流程结束
        {
            QJsonObject playerValue = mJDataPlayer["data"].toObject();
            QJsonObject gojoValue = mJData5["data"].toObject();
            if(playerValue["Favorability"].toInt()>=100 && gojoValue["Favorability"].toInt()>=100)
            {
                mDialog->sltShowCut("CutHe");
            }else{
                mDialog->sltShowCut("CutBe");
            }
            bTheEnd = true;

        }
        mDay.date++;
        updateJsonInt(mJsonHistoryData,"date",mDay.date);//日期更新
        updateJsonInt(mJsonHistoryData,"ActionPoints",0);//行动次数归零
        CheckCurrentStatus();//开始新一天
    }

}

void MainWindow::updateJsonInt(QJsonObject& mJData,QString str, int n)
{
    QJsonValue jValue = mJData.value(str);

    if (jValue.isDouble()) {
        jValue = n;
        mJData[str] = jValue;
    } else {
        mJData[str] = n; // 如果不存在则直接设置新值
    }

}

void MainWindow::saveEventLog(int eventId)
{
    if(bTheEnd){//流程结束
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, QString::fromUtf8("确认"), "要留下这次的记录吗？",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            saveHistory();

        }

        cleanAll();
        bTheEnd = false;
        mDialog->hide();
        show();
        return;
    }
    if(eventId == 0){//非事件
        findEligibleEvent();//事件选择
        return;
    }
    QJsonObject eventValues;
    QJsonArray eventArray = mJDataEvent["data"].toArray();
    for (int i = 0; i < eventArray.size(); ++i) {
        QJsonObject eventObj = eventArray[i].toObject();
        if(eventObj["eventNum"].toInt() == eventId){
            eventValues = eventObj;
            break;
        }

    }
    //添加history记录
    QJsonObject eventLog;
    updateJsonInt(eventLog,"date", mDay.date);//日期
    updateJsonInt(eventLog,"ActionPoints", mJsonHistoryData["ActionPoints"].toInt());//第几次行动
    updateJsonInt(eventLog,"eventNum", eventValues["eventNum"].toInt());

    QJsonArray historyArray = mJsonHistoryData["history"].toArray();
    historyArray.append(eventLog);
    mJsonHistoryData["history"] = historyArray;
    m_re->saveDataToJson("/../../play/history", mJsonHistoryData);
    //跟新行动点数
    updateJsonInt(mJsonHistoryData,"ActionPoints", mJsonHistoryData["ActionPoints"].toInt() + 1);
    //更新event列表
    removeEventDataByNum(mJDataEvent,eventId);
    m_re->saveDataToJson("/../../play/event", mJDataEvent);
    //更新人物属性
    QJsonObject eventData = eventValues["eventData"].toObject();

    QJsonObject playerValues = mJDataPlayer["data"].toObject();
    if(eventData.contains("addFavorability")){
         QJsonArray data = eventData["addFavorability"].toArray();
        playerValues["Favorability"] = playerValues["Favorability"].toInt() + m_re->getRandomNumber(data[0].toInt(), data[1].toInt());
    }
    if(eventData.contains("addConfdence")){
         QJsonArray data = eventData["addConfdence"].toArray();
        playerValues["Confdence"] = playerValues["Confdence"].toInt() + m_re->getRandomNumber(data[0].toInt(), data[1].toInt());
    }
    if(eventData.contains("addRelax")){
         QJsonArray data = eventData["addRelax"].toArray();
        playerValues["Relax"] =playerValues["Relax"].toInt() + m_re->getRandomNumber(data[0].toInt(), data[1].toInt());
    }
    qDebug()<<playerValues;
    eventValues["eventData"] = playerValues;

    CheckCurrentStatus();//开始下一轮

}
void MainWindow::removeEventDataByNum(QJsonObject& mJDataEvent, int eventNum)
{
    QJsonArray dataArray = mJDataEvent["data"].toArray();

    for (int i = 0; i < dataArray.size(); ++i) {
        QJsonObject eventObj = dataArray[i].toObject();
        if (eventObj["eventNum"].toInt() == eventNum) {
            dataArray.removeAt(i);
            break;
        }
    }

    mJDataEvent["data"] = dataArray;
}

void MainWindow::on_startBtn_clicked()
{
    if (ui->startBtn->text() == "new")//新开始
    {
        DialogChooseNew *dlg = new DialogChooseNew();
        connect(dlg, &DialogChooseNew::sigChosen, this, &MainWindow::sltCreateNewPlayer);
        dlg->show();

    }
    else//继续
    {

        if (mDialog->isHidden()) {
            // 如果新窗口当前为隐藏状态，则切换到新窗口
            mDialog->show();
            hide();  // 隐藏主窗口
        }
        else {
            // 如果新窗口当前为显示状态，则切换回主窗口
            show();  // 显示主窗口
            mDialog->hide();
        }
        CheckCurrentStatus();
    }
}

void MainWindow::sltSaveSelection()
{
    mJsonHistoryData["time"] = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString filePath = qApp->applicationDirPath();
    QString strFile = filePath + "/JsonData/" + historyName + ".json";
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

//创建新人物
void MainWindow::sltCreateNewPlayer(QString str, bool type)
{
    qDebug() << str << type;
    QString path = "/../../character/";
    if (type == true)//固定名称人物
    {
        mJDataPlayer = m_re->OpenJsonToObj(path + str);
        m_re->saveDataToJson("/../../play/player", mJDataPlayer);

        mJDataEvent = m_re->OpenEventJsonToObj(path + "event/" + str);//初始化事件
        m_re->saveDataToJson("/../../play/event", mJDataEvent);
    }
    else//自定义名称人物
    {
        mJDataPlayer = m_re->OpenJsonToObj(path + "mob");//初始化player
        mJDataPlayer["name"] = str;
        m_re->saveDataToJson("/../../play/player", mJDataPlayer);

        mJDataEvent = m_re->OpenEventJsonToObj(path + "event/mob");//初始化事件
        m_re->saveDataToJson("/../../play/event", mJDataEvent);

    }
    //初始化日期，历史
    mJsonHistoryData = m_re->OpenEventJsonToObj(path + "history");
    m_re->saveDataToJson("/../../play/history", mJsonHistoryData);
    mDay.date = mJsonHistoryData["date"].toInt();
    //初始化5
    mJData5 = generateRandomJson(m_re->OpenJsonToObj(path + "5"));
    m_re->saveDataToJson("/../../play/5", mJData5);
    //传递player姓名到talkdialog
    mDialog->setPlayerName(mJDataPlayer["name"].toString());
    CheckCurrentStatus();

    //findEligibleEvent();
    mDialog->show();//显示talk窗口
    hide();  // 隐藏主窗口
    ui->startBtn->setText("continue");
    ui->newBtn->setEnabled(true);

}
//从character里初始化新5的数据
QJsonObject MainWindow::generateRandomJson(const QJsonObject &inputJson) {
    QJsonObject outputJson;

    // 获取 data 字段
    QJsonObject data = inputJson["data"].toObject();

    // 生成随机数
    QJsonObject::iterator i;
    for (i = data.begin(); i != data.end(); ++i) {
        if (i.value().isArray() && i.value().toArray().size() == 2) {
            int minValue = i.value().toArray()[0].toInt();
            int maxValue = i.value().toArray()[1].toInt();
            int randomValue = m_re->getRandomNumber(minValue, maxValue);
            outputJson[i.key()] = randomValue;
        }
    }

    // 随机选择食物
    QJsonArray favoriteFoods = inputJson["favouriteFood"].toArray();
    int num = m_re->getRandomNumber(0, 3);
    QString randomFood = favoriteFoods.at(num).toString();
    outputJson["favouriteFood"] = randomFood;

    // 复制 name 字段
    outputJson["name"] = inputJson["name"];

    return outputJson;
}

void MainWindow::on_closeBtn_clicked()
{
    close();
}
//删除之前的存档
void MainWindow::on_newBtn_clicked()
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, QString::fromUtf8("确认"), tr("确定要执行操作吗？"),
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        cleanAll();
    }

}

void MainWindow::cleanAll()
{
    QString filePath = qApp->applicationDirPath();
    QString path = filePath + "/../../play/";
    QStringList fileNames = { "player.json", "5.json", "event.json", "history.json" };
    for (const QString& fileName : fileNames) {
        QString fullFilePath = path + fileName;

        QFile file(fullFilePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

            file.close();
        } else {
            qDebug()<<"清除异常:"<<file.errorString();// 处理文件打开失败的情况
        }
    }
    ui->startBtn->setText("new");
    ui->newBtn->setEnabled(false);
}

void MainWindow::saveHistory()
{
    QJsonArray history = mJsonHistoryData["history"].toArray();

       // 按照date和ActionPoints排序
       std::sort(history.begin(), history.end(), compareHistoryItems);
        QString currentTime = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
       // 将排序后的结果输出到txt文件
        QString fileName = "记录" + currentTime + ".txt";
       QFile file(fileName);
       if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
           QTextStream out(&file);
           for (const auto& item : history) {
               const QJsonObject& obj = item.toObject();
               out << "Date: " << obj["date"].toInt() << ", ActionPoints: " << obj["ActionPoints"].toInt()
                   << ", Num: " << obj["eventNum"].toInt() << "\n";
           }
           file.close();

           QMessageBox::information(nullptr, "File Saved", "File saved success! " );
       }
}
//bool MainWindow::compareHistoryItems(const QJsonValue& item1, const QJsonValue& item2) {
//    const QJsonObject& obj1 = item1.toObject();
//    const QJsonObject& obj2 = item2.toObject();
//    if (obj1["date"].toInt() == obj2["date"].toInt()) {
//        return obj1["ActionPoints"].toInt() < obj2["ActionPoints"].toInt();
//    }
//    return obj1["date"].toInt() < obj2["date"].toInt();
//}
