#include "recordselection.h"
#include<QDebug>
#include<QCoreApplication>
#include<QFile>
#include<random>
#include<QFileInfo>
RecordSelection::RecordSelection()
{

}
//打开给定目录的json文件
QJsonObject RecordSelection::OpenJsonToObj(QString path)
{
    QString filePath = qApp->applicationDirPath();
    QString strFile = filePath + path + ".json";

    QFileInfo fileInfo(strFile);
    QString absoluteFilePath = fileInfo.absoluteFilePath();
    qDebug()<<"OpenJsonToObj :"<<absoluteFilePath;
    QFile file(absoluteFilePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"could't open projects json"<< file.errorString();
        return QJsonObject();
    }

    QString value = file.readAll();
    file.close();
    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(), &parseJsonErr);
    if(!(parseJsonErr.error == QJsonParseError::NoError))
    {
        qDebug() <<"parseJsonErr"<< parseJsonErr.errorString();
        return QJsonObject();
    }
    mJsonObject = document.object();
    return document.object();
}

QJsonObject RecordSelection::OpenEventJsonToObj(QString path)
{
    QString filePath = qApp->applicationDirPath();
    QString strFile = filePath + path + ".json";

    QFileInfo fileInfo(strFile);
    QString absoluteFilePath = fileInfo.absoluteFilePath();
    qDebug() << "OpenJsonToObj :" << absoluteFilePath;

    QFile file(absoluteFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "could't open projects json" << file.errorString();
        return QJsonObject();
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseJsonErr;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseJsonErr);

    if (parseJsonErr.error != QJsonParseError::NoError)
    {
        qDebug() << "parseJsonErr" << parseJsonErr.errorString();
        return QJsonObject();
    }

    QJsonObject jsonObject = jsonDoc.object();

    // 获取"data"字段的值
//    QJsonArray dataArray = jsonObject["data"].toArray();

//    // 遍历每个事件数据
//    for (const QJsonValue& eventValue : dataArray)
//    {
//        QJsonObject eventObject = eventValue.toObject();
//        int eventNum = eventObject["eventNum"].toInt();
//        QJsonObject eventData = eventObject["eventData"].toObject();
//        // 在这里处理 eventNum 和 eventData 数据
//        jsonObject[QString::number(eventNum)] = eventData;
//    }

    return jsonObject;
}

QJsonArray RecordSelection::OpenJsonToArray(QString path)
{
    QString filePath = qApp->applicationDirPath();
    QString strFile = filePath +"/JsonData/"+path + ".json";
    qDebug()<<"OpenJsonToArray :"<<strFile;
    QFile file(strFile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"could't open projects json" <<file.errorString();
        return QJsonArray();
    }

    QString value = file.readAll();
    file.close();
    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(), &parseJsonErr);
    if(!(parseJsonErr.error == QJsonParseError::NoError))
    {
        qDebug() <<"OpenJsonToArray"<< parseJsonErr.errorString();
        return QJsonArray();
    }
    qDebug()<< document.object();
    return document.array();
}


void RecordSelection::setDataToPlayer()
{
    mJDataPlayer = mJsonObject;
}

void RecordSelection::getDataBy5()
{
    mJsonObject = mJData5;
}

void RecordSelection::getDataByPlayer()
{
    mJsonObject  = mJDataPlayer;
}

void RecordSelection::updateData5(QString name, int i)
{
     qDebug()<<mJData5;
     QJsonObject dataValue = mJData5.value("data").toObject();
     dataValue[name] = dataValue.value(name).toInt() + i;
     //qDebug()<<dataValue.value(name) <<dataValue.value(name).toInt() + i ;
     mJData5["data"] = dataValue;
     qDebug()<<mJData5;
}

void RecordSelection::updateDataPlayer(QString name, int i)
{
    QJsonObject dataValue = mJDataPlayer.value("data").toObject();
    dataValue[name] = dataValue.value(name).toInt() + i;
    mJDataPlayer["data"] = dataValue;
}

void RecordSelection::UpdateJson5(QString name, int i)
{
    mJData5[name] = i;
}

void RecordSelection::UpdateJsonPlayer(QString name, int i)
{
    mJDataPlayer[name] = i;
}

//写入json文件保存数据
void RecordSelection::saveDataToJson(QString path,QJsonObject obj)
{
    QString filePath = qApp->applicationDirPath();
    QString strFile = filePath + path + ".json";

    QFileInfo fileInfo(strFile);
    QString absoluteFilePath = fileInfo.absoluteFilePath();
    QFile file(absoluteFilePath);
    qDebug()<<"saveDataToJson path:"<<absoluteFilePath;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << "can't open error!";
        return;
    }
    QJsonDocument jsonDoc(obj);
    QByteArray jsonDataBytes = jsonDoc.toJson();

    QTextStream stream(&file);
    stream.setCodec("UTF-8");    // 设置写入编码为UTF-8
    stream << jsonDataBytes;     // 将JSON数据写入文件
    file.close();
}


int RecordSelection::getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}
