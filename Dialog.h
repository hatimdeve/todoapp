#ifndef DIALOG_H
#define DIALOG_H
#include"QDate"
#include <QDialog>
#include"connection_BD.h"
#include"QCheckBox"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
  QDate getdate() ;
bool getcheck();
  QSqlDatabase getdata();

private slots:

      void on_pushButton_clicked();

private:
QDate datee;
    Ui::Dialog *ui;
    QSqlDatabase db;

};

#endif // DIALOG_H
