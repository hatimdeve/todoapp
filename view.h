#ifndef VIEW_H
#define VIEW_H

#include <QDialog>
#include"dialog.h"
#include"QTableView"
namespace Ui {
class view;
}

class view : public QDialog
{
    Q_OBJECT

public:
    explicit view(QWidget *parent = nullptr);
    ~view();
QTableView* getview();




private:
    Ui::view *ui;
};

#endif // VIEW_H
