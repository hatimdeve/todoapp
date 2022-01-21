#include "view.h"
#include "ui_view.h"
#include"QMessageBox"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include"dialog.h"
#include"QTextStream"
view::view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view)
{
    Dialog F;
    ui->setupUi(this);

//    auto model =new QSqlQueryModel;
//    auto query= QSqlQuery(F.getdata());
//    QString view{"select *from tasks"};
//    query.exec(view);
//    model->setQuery(query);
//    ui->tableView->setModel(model);
}

view::~view()
{
    delete ui;
}
QTableView* view::getview(){
    return ui->tableView;
}

