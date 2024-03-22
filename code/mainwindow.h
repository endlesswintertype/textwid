#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"recordselection.h"
#include <QJsonObject>
#include"talkDialog.h"
namespace Ui {
class MainWindow;
}
struct currentState{
   QString name;
   int eventNum;

};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QList<int> findEligibleEvent();
    void CheckCurrentStatus();

private slots:
    void on_startBtn_clicked();


    void updateRecord();
    void sltSaveSelection();
    void sltCreateNewPlayer(QString str,bool type);

    void on_closeBtn_clicked();

    void on_newBtn_clicked();
signals:
    void sigSentEventId(QList<int>);

private:
    Ui::MainWindow *ui;
    RecordSelection *m_re;
    QJsonObject mJsonHistoryData;
    talkDialog *mDialog;
    QString historyName="history";
    QJsonObject mJDataPlayer;
    QJsonObject mJData5;
};

#endif // MAINWINDOW_H
