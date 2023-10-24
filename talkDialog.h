#ifndef TALKDIALOG_H
#define TALKDIALOG_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
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
signals:
    void SigCloseDialog();
public slots:
    void sltGetEventId(QList<int> idList);
    void sltShowEvent(QString eventName);

private slots:
    void on_nextBtn_clicked();

    void on_closeBtn_clicked();

    void on_hestoryBtn_clicked();

    void rightBtnClicked(int n);

    void on_optionBtn_clicked();

    void on_optionBtn2_clicked();

    void on_optionBtn3_clicked();

private:
    void widgetChange();

    Ui::talkDialog *ui;
    QJsonArray mText;
    QVector<Dialogue> mTextHistory;
    Dialogue mUe;
    QString mTextNow;
    int nTextListNum = 0;
    int nTextListSize = 0;
    QList<int> nIdChoose;
};

#endif // TALKDIALOG_H
