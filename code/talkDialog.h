#ifndef TALKDIALOG_H
#define TALKDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
#include "EventInfo.h"
namespace Ui {
class talkDialog;
}
struct Dialogue {
    QString speaker;
    QString content;
};
class talkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit talkDialog(QWidget *parent = 0);
    ~talkDialog();
    QJsonArray readDialogueFromFile( QString name,  QString filePath);
    Dialogue getDialogueFromJson(const QJsonObject& jsonObj);
    Dialogue getNthDialogueFromFile(int n);
    void generateButtonsFromMap(const QMap<int, QString>& data, QWidget* parentWidget);
    QList<int> getThreeRandomNumbers(QList<int> nums);
    void setPlayerName(QString name);
signals:
    void SigCloseDialog();
    void sigCheckCurrentStatus();
    void sigEventLog(int EventId);
public slots:
    void sltGetEventId(QList<EventInfo> idList);
    void sltShowEvent(QString eventName);
    void sltShowCut(QString cutName);


private slots:
    void on_nextBtn_clicked();

    void on_closeBtn_clicked();

    void on_historyBtn_clicked();

    void rightBtnClicked(int n);

    void on_optionBtn_clicked();

    void on_optionBtn2_clicked();

    void on_optionBtn3_clicked();

    void on_closeHistory_clicked();

private:
    void widgetChange();

    Ui::talkDialog *ui;
    QJsonArray mText;
    QVector<QString> mTextHistory;//历史记录
    QString mPlayerName = "";//当前player姓名
    Dialogue mUe;
    QString mTextNow;
    int nTextListNum = 0;
    int nTextListSize = 0;
    int nEventId = 0;//当前事件id。为0时无事件
    QList<int> nIdChoose;//事件编号列表
    bool b_ShowState = true;//true：对话文本界面，false：选择界面
};

#endif // TALKDIALOG_H
