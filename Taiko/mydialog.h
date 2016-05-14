#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QPushButton>
#include <QDialog>
#include  <QLabel>
#include  <QFont>
#include      <QtCore/QCoreApplication>
#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QListWidgetItem>
#include    <QComboBox>
namespace Ui {
class myDialog;
}

class myDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myDialog(QWidget *parent = 0);
    ~myDialog();
    QPushButton* restart;
    QPushButton* exit;
    QLabel * Score;
private:
    Ui::myDialog *ui;
};

#endif // MYDIALOG_H
