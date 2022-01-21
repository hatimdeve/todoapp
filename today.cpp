#include "today.h"
#include "ui_today.h"
#include"dialog.h"
#include"QMessageBox"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"dialog.h"
#include"QTextStream"
today::today(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::today)
{
    ui->setupUi(this);
     makeconnexion();

}

today::~today()
{
    delete ui;
}
QTableView* today::getview(){
    return ui->tableView;
}
QTableView* today::getview1(){
    return ui->tableView_2;
}
void today::makeconnexion(){
    connect(ui->tableView,&QTableView::clicked,this,&today::afficher);

}
void today::afficher(){
    Dialog F;

//    QString finished;
     QTextStream out(stdout);
//      auto model =new QSqlQueryModel;
      auto query= QSqlQuery(F.getdata());
//      QString view{"select finished from tasks where id ='%1'"};
       QString upadate{"UPDATE  tasks set finished='%1'where id='%2' "};
       QModelIndexList indexList = ui->tableView->selectionModel()->selectedIndexes();
       int row;
       foreach (QModelIndex index, indexList) {
           row = index.row();

       }
  int i=ui->tableView->model()->index(row,0).data().toInt();
    out<<i;
//  query.exec(view.arg(i));
//  while (query.next()) {
//   finished = query.value(0).toString();
//  }
//  if(finished=='1'){
     QMessageBox msgBox;
     msgBox.setText("The document has been modified.");
     msgBox.setInformativeText("Do you want to set  your task to finished?");
     msgBox.setStandardButtons(QMessageBox::Save |  QMessageBox::Cancel);
     int ret = msgBox.exec();

     switch (ret) {
       case QMessageBox::Save:

        query.exec(upadate.arg(0).arg(i));
           break;

       case QMessageBox::Cancel:

           break;
       default:

           break;
     }
//  }
  out<<i;
//    out<<finished;
}
