#ifndef RECORDSELECTION_H
#define RECORDSELECTION_H
#include<QString>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#define qApp QCoreApplication::instance()

struct data{
    int confidence;
    int relax;
    int Favorability;

};

class RecordSelection
{
public:
    RecordSelection();
    //取人物数据
    QJsonObject OpenJsonToObj(QString path);
    //取事件数据
    QJsonObject OpenEventJsonToObj(QString path);
    QJsonArray OpenJsonToArray(QString path);
    void setDataToPlayer();
    void getDataBy5();
    void getDataByPlayer();

    void updateData5(QString name, int i);
    void updateDataPlayer(QString name, int i);
    void UpdateJson5(QString name, int i);
    void UpdateJsonPlayer(QString name, int i);
    void saveDataToJson(QString path, QJsonObject obj);
    int getRandomNumber(int min, int max);

    QJsonObject mJsonObject;
    QJsonObject mJDataPlayer;
    QJsonObject mJData5;

};


#endif // RECORDSELECTION_H
