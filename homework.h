#ifndef HOMEWORK_H
#define HOMEWORK_H
#include"QCalendarWidget"
#include"QPen"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class homework; }
QT_END_NAMESPACE

class homework : public QMainWindow
{
    Q_OBJECT

public:
    homework(QWidget *parent = nullptr);
    ~homework();
    void makeconnexion();


private slots:
    void on_actionnew_triggered();
        void afficher();

    void on_actionfinished_2_triggered();

    void on_actionpending_triggered();

    void on_actiontoday_triggered();

    void on_actionquit_triggered();

private:
    Ui::homework *ui;
//    QDate m_currentDate;
//   QPen m_outlinePen;
//     QBrush m_transparentBrush;
};
#endif // HOMEWORK_H
