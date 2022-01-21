#ifndef TODAY_H
#define TODAY_H

#include <QDialog>
#include"QTableView"
namespace Ui {
class today;
}

class today : public QDialog
{
    Q_OBJECT

public:
    explicit today(QWidget *parent = nullptr);
    ~today();
QTableView* getview();
QTableView* getview1();
void makeconnexion();
private slots:

        void afficher();
private:
    Ui::today *ui;
};

#endif // TODAY_H
