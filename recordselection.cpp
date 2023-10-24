#include "recordselection.h"
#include<QDebug>
#include<QCoreApplication>
#include<QFile>

RecordSelection::RecordSelection()
{

}

QJsonObject RecordSelection::OpenJsonToObj(QString path)
{
    QString filePath = qApp->applicationDirPath();
    QString strFile = filePath +"/JsonData/"+path + ".json";
    qDebug()<<strFile;
    QFile file(strFile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"could't open projects json";
        return QJsonObject();
    }

    QString value = file.readAll();
    file.close();
    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(), &parseJsonErr);
    if(!(parseJsonErr.error == QJsonParseError::NoError))
    {
        qDebug() << parseJsonErr.errorString();
        return QJsonObject();
    }
    mJsonObject=document.object();
    return document.object();
}

QJsonArray RecordSelection::OpenJsonToArray(QString path)
{
    QString filePath = qApp->applicationDirPath();
    QString strFile = filePath +"/JsonData/"+path + ".json";
    qDebug()<<strFile;
    QFile file(strFile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"could't open projects json";
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

void RecordSelection::setDataTo5()
{
    mJData5 = mJsonObject;
    qDebug()<<mJData5;
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
     qDebug()<<dataValue.value(name) <<dataValue.value(name).toInt() + i ;
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

void RecordSelection::saveDataToJson(QString path,QJsonObject obj)
{
    QString filePath = qApp->applicationDirPath();
    QString strFile = filePath +"/JsonData/"+path + ".json";
    QFile file(strFile);
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
