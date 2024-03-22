#ifndef DIALOGCHOOSENEW_H
#define DIALOGCHOOSENEW_H

#include <QDialog>

namespace Ui {
class DialogChooseNew;
}

class DialogChooseNew : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChooseNew(QWidget *parent = 0);
    ~DialogChooseNew();
signals:
    void sigChosen(QString str,bool type=true);

private slots:
    void on_buttonBox_accepted();
    
private:
    Ui::DialogChooseNew *ui;
};

#endif // DIALOGCHOOSENEW_H
