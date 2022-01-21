#include "dialog.h"
#include "ui_dialog.h"
#include"QTextStream"
#include"QMessageBox"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    db=QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("C:\\wamp64\\bin\\mysql\\mysql5.7.31\\data\\hatimkhaoula");
    if(db.open())
         QMessageBox::information(this,"envoi vers bd","succes");
    else
       QMessageBox::information(this,"envoi vers bd","failed");
    auto query=new QSqlQuery(db);
    QString create{"create table if not exists tasks(id integer  not null  primary key AUTOINCREMENT  ,description varchar(80),tag varchar(80),datework varchar(80),finished int(50))"};
    if(!query->exec(create))
            QMessageBox::critical(this,"error","desole");
}

Dialog::~Dialog()
{
    delete ui;
}
QDate Dialog::getdate() {
    return ui->dateEdit->date();
}





void Dialog::on_pushButton_clicked()
{
    auto query=new QSqlQuery(db);
    QString a=ui->lineEdit->text();
   QString z=ui->comboBox->currentText();
   QString e=ui->dateEdit->date().toString("yyyy-MM-dd");
    QString cell1=QDate::currentDate().toString("yyyy-MM-dd");
    QString insert{"insert into  tasks(description,tag,datework,finished) values('%1','%2','%3','%4')"};
     QString upadate{"UPDATE  tasks set finished='%1'where description='%2'and tag='%3'and datework='%4' "};
     if(ui->checkBox->isChecked()&& e<cell1){
         int b=0;
      if(!query->exec(insert.arg(a).arg(z).arg(e).arg(b)))
                 QMessageBox::critical(this,"error","desole");
}
       if(ui->checkBox->isChecked()==false && e==cell1){
         int b=1;
         if(!query->exec(insert.arg(a).arg(z).arg(e).arg(b)))
                 QMessageBox::critical(this,"error","desole");
}

         if(ui->checkBox->isChecked()==false && e>cell1){
             int b=2;
             if(!query->exec(insert.arg(a).arg(z).arg(e).arg(b)))
                     QMessageBox::critical(this,"error","desole");
         }

       }



QSqlDatabase Dialog::getdata(){
    return db;
}
bool Dialog::getcheck(){
    return ui->checkBox->isChecked();
}

