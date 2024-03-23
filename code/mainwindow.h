#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"recordselection.h"
#include <QJsonObject>
#include"talkDialog.h"
#include "EventInfo.h"
namespace Ui {
class MainWindow;
}

struct thisDay{
    int date = 1;
    QString weather = "sunny";
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QList<EventInfo> findEligibleEvent();
    void CheckCurrentStatus();

    void updateJsonInt(QJsonObject& mJData,QString str,int n);
    void saveEventLog(int eventId);
    void removeEventDataByNum(QJsonObject& mJDataEvent, int eventNum);
    static bool compareHistoryItems(const QJsonValue& item1, const QJsonValue& item2) {
        const QJsonObject& obj1 = item1.toObject();
        const QJsonObject& obj2 = item2.toObject();
        if (obj1["date"].toInt() == obj2["date"].toInt()) {
            return obj1["ActionPoints"].toInt() < obj2["ActionPoints"].toInt();
        }
        return obj1["date"].toInt() < obj2["date"].toInt();
    }

private slots:
    void on_startBtn_clicked();

    void sltSaveSelection();
    //初始化player数据
    void sltCreateNewPlayer(QString str,bool type);

    QJsonObject generateRandomJson(const QJsonObject &inputJson);

    void on_closeBtn_clicked();

    void on_newBtn_clicked();
signals:
    void sigSentEventId(QList<EventInfo>);

private:
    void cleanAll();
    void saveHistory();
    //bool compareHistoryItems(const QJsonValue& item1, const QJsonValue& item2);
    Ui::MainWindow *ui;
    RecordSelection *m_re;
    //历史记录
    QJsonObject mJsonHistoryData;
    talkDialog *mDialog;
    QString historyName = "history";
    //角色数据
    QJsonObject mJDataPlayer;
    //5的数据
    QJsonObject mJData5;
    //事件列表
    QJsonObject mJDataEvent;
    thisDay mDay;

    bool bTheEnd = false;
};

#endif // MAINWINDOW_H
