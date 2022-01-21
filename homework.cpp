#include "homework.h"
#include "ui_homework.h"
#include"QCalendarWidget"
#include"QPainter"
#include"QTextCharFormat"
#include"dialog.h"
#include"QTextStream"
#include"QMessageBox"
#include"view.h"
#include"today.h"
#include"QSqlQueryModel"
#include"QStandardItemModel"
homework::homework(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::homework)
{
//    makeconnexion();
     QTextStream out(stdout);
    ui->setupUi(this);
   Dialog F;
     makeconnexion();
   QTextCharFormat fmt,fmt1,fmt2;
   fmt.setBackground(Qt::red);
   fmt1.setBackground(Qt::green);
   fmt2.setBackground(Qt::blue);
    auto model =new QSqlQueryModel;
    QString cell1=QDate::currentDate().toString("yyyy-MM-dd");
//    QString cell1=QDate::currentDate().toString("yyyy-MM-dd");
    auto query= QSqlQuery(F.getdata());
    QString view{"select  finished,datework from tasks"};
    query.exec(view);

    while (query.next()) {
           QString finished = query.value(0).toString();
            QString datework = query.value(1).toString();
           QDate Date = QDate::fromString(datework,"yyyy-MM-dd");
           QString d=Date.toString("yyyy-MM-dd");
           if( finished=="0" && datework<cell1)
        ui->calendarWidget->setDateTextFormat(Date, fmt1);

           if( finished=="2" && datework>cell1)
        ui->calendarWidget->setDateTextFormat(Date, fmt);

             if( finished=="1" || datework==cell1)
             ui->calendarWidget->setDateTextFormat(Date, fmt2);

             if(finished=="2" && datework==cell1 ){
           ui->calendarWidget->setDateTextFormat(Date, fmt2);
           QString upadate{"UPDATE  tasks set  finished=1 where finished=2"};
           query.exec(upadate);
             }
             if( finished=="1" && datework<cell1){
                 ui->calendarWidget->setDateTextFormat(Date, fmt1);
                 QString upadate{"UPDATE  tasks set  finished=0 where finished=1 "};
                 query.exec(upadate);
             }
out<<d;

       }

}

homework::~homework()
{
    delete ui;
}



void homework::on_actionnew_triggered()
{
    Dialog F;
 QTextStream out(stdout);
auto reply=F.exec();
    QTextCharFormat fmt,fmt1,fmt2;
    fmt.setBackground(Qt::red);
    fmt1.setBackground(Qt::green);
    fmt2.setBackground(Qt::blue);
    QString cell=F.getdate().toString("yyyy-MM-dd");
     QString cell1=QDate::currentDate().toString("yyyy-MM-dd");
//      auto query= QSqlQuery(F.getdata());
//     QString view{"select  finished,datework from tasks"};
//     query.exec(view);

    if(reply== QDialog::Accepted)
    {

        if(F.getcheck() && cell<cell1 )
     ui->calendarWidget->setDateTextFormat(F.getdate(), fmt1);
        if( F.getcheck()==false && cell==cell1)
     ui->calendarWidget->setDateTextFormat(F.getdate(), fmt2);
          if( F.getcheck()==false && cell>cell1)
          ui->calendarWidget->setDateTextFormat(F.getdate(), fmt);


          out<<F.getdate().toString("yyyy-MM-dd");
    }
}


void homework::on_actionfinished_2_triggered()
{
    view F;
    Dialog V;
 QTextStream out(stdout);

   QString b=ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
   out<<b;
   auto model =new QSqlQueryModel;
   auto query= QSqlQuery(V.getdata());
   QString view{"select description,tag,datework from tasks WHERE finished=0"};
   query.exec(view.arg(b));
   QPixmap newIcon(":/icons/hatim/today.png");
   QIcon icon(newIcon);


   model->setQuery(query);

  F.getview()->setModel(model);
  auto reply=F.exec();
}
void homework::makeconnexion(){
    view F;
    connect(ui->calendarWidget,&QCalendarWidget::clicked,this,&homework::afficher);

}

void homework::afficher(){
    view F;
    today T;
    Dialog V;
 QTextStream out(stdout);

   QString b=ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
    QString cell1=QDate::currentDate().toString("yyyy-MM-dd");
   out<<b;
   auto model =new QSqlQueryModel;
   auto model1 =new QSqlQueryModel;
   auto model2 =new QSqlQueryModel;
   auto query= QSqlQuery(V.getdata());
   auto query1= QSqlQuery(V.getdata());
   auto query2= QSqlQuery(V.getdata());
   QString view{"select description,tag,datework from tasks WHERE datework='%1' "};
 QString view1{"select  id,description,tag,datework,finished from tasks WHERE datework='%1' and finished=1"};
 QString view2{"select description,tag,datework,finished from tasks WHERE datework='%1' and finished=0"};
   if(b==cell1){

   query1.exec(view1.arg(b));
   query2.exec(view2.arg(b));
   model1->setQuery(query1);
 model2->setQuery(query2);

  T.getview()->setModel(model1);
  T.getview1()->setModel(model2);
   auto reply=T.exec();
   }
else{
query.exec(view.arg(b));
   model->setQuery(query);

  F.getview()->setModel(model);
  auto reply=F.exec();
   }
}

void homework::on_actionpending_triggered()
{
    view F;
    Dialog V;
 QTextStream out(stdout);

   QString b=ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
   out<<b;
   auto model =new QSqlQueryModel;
   auto query= QSqlQuery(V.getdata());
   QString view{"select description,tag,datework from tasks WHERE finished=2"};
   query.exec(view.arg(b));
   QPixmap newIcon(":/icons/hatim/today.png");
   QIcon icon(newIcon);


   model->setQuery(query);

  F.getview()->setModel(model);
  auto reply=F.exec();
}


void homework::on_actiontoday_triggered()
{
    view F;
    today T;
    Dialog V;
 QTextStream out(stdout);

   QString b=ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
    QString cell1=QDate::currentDate().toString("yyyy-MM-dd");
   out<<b;
   auto model =new QSqlQueryModel;
   auto model1 =new QSqlQueryModel;
   auto model2 =new QSqlQueryModel;
   auto query= QSqlQuery(V.getdata());
   auto query1= QSqlQuery(V.getdata());
   auto query2= QSqlQuery(V.getdata());
   QString view{"select description,tag,datework from tasks WHERE datework='%1' "};
 QString view1{"select  description,tag,datework from tasks WHERE datework='%1' and finished=1"};
 QString view2{"select description,tag,datework from tasks WHERE datework='%1' and finished=0"};
   if(b==cell1){


   query1.exec(view1.arg(b));
   query2.exec(view2.arg(b));
   model1->setQuery(query1);
 model2->setQuery(query2);

  T.getview()->setModel(model1);
  T.getview1()->setModel(model2);
   auto reply=T.exec();
   }
else{
query.exec(view.arg(b));
   model->setQuery(query);

  F.getview()->setModel(model);
  auto reply=F.exec();
   }
}


void homework::on_actionquit_triggered()
{
     QApplication::quit();
}

