<div id="top"></div>



<!-- PROJECT LOGO -->
<br />
<div align="center">
    <img src="images/logo.png" alt="Logo" width="500" height="360">
  <h2 align="center">Programming Widget Layout</h2>
  <h3 align="center">Use the gained knowledge to create forms</h3>
</div>



<!-- TABLE OF CONTENTS -->
<details>
 <ol class="list-group list-group-numbered">
     <li class="list-group-item"> <a href="#Experimenting-with-QHBOXLayout">Experimenting with QHBOXLayout </a></li>
  <li class="list-group-item"> <a href="#Nested-Layouts">Nested Layouts</a> </li>
  <li class="list-group-item"> <a href="#Bug-report-Form">Bug report Form</a> </li>
   <li class="list-group-item"> <a href="#Grid-Layout">Grid Layout</a> </li>
</ol>
</details>



<div id="Experimenting-with-QHBOXLayout">
  
<!-- ABOUT THE PROJECT -->
## Experimenting with QHBOXLayout
    
    Create a project called hbox with the following code:

```cpp
int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  QWidget* window = new QWidget();
  window->setWindowTitle("QHBoxLayout Test");

  window->show();

  return app.exec();
}
};
```
 This will show an empty window. my  goal was to modify the code in order to display the following form:   
      <p align="center">
     <img src="images/hbox.png">
   </p>  
  <h2 align="center"><i>A QHBoxLayout example.</i></h2>
</div>
now this is my code that i add to get this from.

**.Header**

```cpp
#ifndef DIALOG1_H
#define DIALOG1_H

#include <QWidget>
#include"QLineEdit"
#include"QLabel"
#include"QPushButton"
#include"QBoxLayout"
class dialog1 : public QWidget
{
protected:

public:
    explicit dialog1(QWidget *parent = nullptr);

protected:
void createwidgets();
void placewidgets();
protected:
QLineEdit *nameEdit;
QLabel *name;
QPushButton *button;


};

#endif // DIALOG1_H

```

**.cpp**

```cpp

#include "dialog1.h"

dialog1::dialog1(QWidget *parent) : QWidget(parent)
{
    createwidgets();
        placewidgets();
}
void dialog1::createwidgets(){
 nameEdit = new QLineEdit;
 name = new QLabel("name:");
 button = new QPushButton("search");
}
void dialog1::placewidgets(){
  QHBoxLayout *mainLayout = new QHBoxLayout;
  this->setLayout(mainLayout);
  mainLayout->addWidget(name);
  mainLayout->addWidget(nameEdit);
  mainLayout->addWidget(button);

}

```
 **main**
 

```cpp


#include "mainwindow.h"

#include <QApplication>
#include"dialog1.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    dialog1 *window=new dialog1;
      window->show();

      return app.exec();

}


```

this the interface of my code.

   <p align="center">
     <img src="images/imagee.png">
   </p>  
   
   <p align="right">(<a href="#top">back to top</a>)</p>
   
   <div id="Nested-Layouts">
  
<!-- ABOUT THE PROJECT -->
## Nested Layouts

The goal of the exercice is learn to analyse the construction of a form and thencode it using **Netsted layouts**.

Here we show you a classic dialog from the book **GB** to search for a user.

>You do not have to code any **functinality**, just the form of the dialog.


   <p align="center">
     <img src="images/nesting.png">
   </p>  
   <h2 align="center"> Nested Layout.</h2>
   
   now this is my code that i add to get this from.
   
   **.header**
   
   ```cpp
   
   #ifndef DIALOG2_H
#define DIALOG2_H

#include <QWidget>
#include"QLineEdit"
#include"QLabel"
#include"QPushButton"
#include"QBoxLayout"
#include"QCheckBox"
class dialog2 : public QWidget
{

public:
    explicit dialog2(QWidget *parent = nullptr);
    virtual ~dialog2();
protected:
void createwidgets();
void placewidgets();
void makeconnexion();
protected:
QLineEdit *nameEdit;
QLabel *name;
QCheckBox *item1;
QCheckBox *item2;
QPushButton *button1;
QPushButton *button2;
};

#endif // DIALOG2_H

   ```
   **.cpp**
   
   ```cpp
   
   #include "dialog2.h"
#include"QApplication"
dialog2::dialog2(QWidget *parent) : QWidget(parent)
{
          createwidgets();
          placewidgets();
          makeconnexion();
}
dialog2::~dialog2(){
    delete nameEdit;
    delete  name;
    delete button1;
    delete  button2;
    delete item1;
    delete item2;
}
void dialog2::createwidgets(){
 nameEdit = new QLineEdit;
 name = new QLabel("name:");
 button1 = new QPushButton("search");
 button2 = new QPushButton("close");
 item1=new QCheckBox("matchcase");
  item2=new QCheckBox("searchbackward");

}
void dialog2::placewidgets(){

  QHBoxLayout *mainLayout = new QHBoxLayout;
  QVBoxLayout *leftlayout= new QVBoxLayout;
  QVBoxLayout *righlayout=new QVBoxLayout;

  QHBoxLayout *topteftlayout=new QHBoxLayout;

  this->setLayout(mainLayout);


    mainLayout->addLayout(leftlayout);
 mainLayout->addLayout(righlayout);

    leftlayout->addLayout(topteftlayout);

    topteftlayout->addWidget(name);
    topteftlayout->addWidget(nameEdit);

    leftlayout->addWidget(item1);
     leftlayout->addWidget(item2);

     righlayout->addWidget(button1);
      righlayout->addWidget(button2);
      righlayout->addSpacerItem(new QSpacerItem(10,10,QSizePolicy::Expanding));
//  mainLayout->addLayout(topteftlayout);
}
void dialog2::makeconnexion(){
    connect(button2,&QPushButton::clicked,qApp,&QApplication::exit);
}

   ```
   **main**
   
   ```cpp
   #include "mainwindow.h"

#include <QApplication>
#include"dialog2.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    dialog2 *d=new dialog2;

      d->show();

      return app.exec();

}

   ```
   
   this the interface of my code.

   <p align="center">
     <img src="images/imag.png">
   </p>  
   
   <p align="right">(<a href="#top">back to top</a>)</p>
   
      
<div id="Bug-report-Form">
    
<!-- ABOUT THE PROJECT -->
## Bug report Form
    
my task is to create the following form to report a problem,the purpuse of this exercice is the use of **The QFormLayout** which is a  class manages forms of input widgets and their associated labels [**more**](https://doc.qt.io/qt-5/qformlayout.html#details).

  <p align="center">
     <img src="images/form_report.png">
   </p>  
   <h2 align="center"> Dialog to report a form.</h2>
   
   now this is my code that i add to get this from.
   
   **.header**
   
   ```cpp
   #include"QTextEdit"
#include"QComboBox"
#include"QDialogButtonBox"
class dialog : public QWidget
{

public:
    explicit dialog(QWidget *parent = nullptr);

protected:
void createwidgets();
void placewidgets();
protected:
QLineEdit *nameEdit;
 QLineEdit *companyEdit;
 QLineEdit *phoneEdit;
 QLineEdit *emailEdit;
 QLineEdit *problemEdit;
 QTextEdit *summaryEdit;
 QComboBox *reproducibility;
 QDialogButtonBox *buttonBox;
};

#endif // DIALOG_H

   ```
   **.cpp**
   
   ```cpp
   #include "dialog.h"
#include"QFormLayout"
dialog::dialog(QWidget *parent) : QWidget(parent)
{
createwidgets();
    placewidgets();
}
void dialog::createwidgets(){

    nameEdit = new QLineEdit("joe Blow");
           companyEdit = new QLineEdit("ACME,Inc.");
           phoneEdit = new QLineEdit("(819)555-1212");
           emailEdit = new QLineEdit("joeb@acme.qc.ca");
           problemEdit = new QLineEdit("crash at startup");
           summaryEdit = new QTextEdit("trying to install");
           reproducibility = new QComboBox;
                   reproducibility->addItem("Always");
                   reproducibility->addItem("Sometimes");
                   reproducibility->addItem("Rarely");
                   buttonBox = new QDialogButtonBox;
                      buttonBox->addButton("Submit Bug Report",
                                           QDialogButtonBox::AcceptRole);
                      buttonBox->addButton("Don't Submit",
                                           QDialogButtonBox::RejectRole);
                      buttonBox->addButton(QDialogButtonBox::Reset);
}
void dialog:: placewidgets(){
      QFormLayout *layout = new QFormLayout;
      layout->addRow(tr("&Name:"), nameEdit);
             layout->addRow("&Company:", companyEdit);
             layout->addRow("&Phone:", phoneEdit);
             layout->addRow("&Email:", emailEdit);
             layout->addRow("Problem &Title:", problemEdit);
             layout->addRow("&Summary Information:",
                            summaryEdit);
             layout->addRow("&Reproducibility:",
                            reproducibility);

             QVBoxLayout *mainLayout = new QVBoxLayout;
             mainLayout->addLayout(layout);
             mainLayout->addWidget(buttonBox);
             this->setLayout(mainLayout);


}
   
   ```
   **main**
   
   ```cpp
   
   #include "mainwindow.h"

#include <QApplication>
#include"dialog.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    dialog *window=new dialog;

      window->show();

      return app.exec();

}
   ```
      
   this the interface of my code.

   <p align="center">
     <img src="images/image.png">
   </p>  
   
 <p align="right">(<a href="#top">back to top</a>)</p>
    
<div id="Grid-Layout">   
   
<!-- ABOUT THE PROJECT -->
  
## Grid Layout

For our final exercice, we will visit an imporant layout .

   * Check and read the documentation for the [**QGridLayout**](https://doc.qt.io/qt-5/qformlayout.html#details)
    
   * Once you’ve read it, try to construct the following calculator:
   
   <p align="center">
     <img src="images/keypad.png">
   </p>  
   
   * The component showing the number is called a [**LCDNumber**](https://doc.qt.io/qt-5/qformlayout.html#details) 
   
   * You may assume that at max it can contains **6 digits**.
   
   * Call the method setMinimumHeight on you LCDNumber to set a minimu height of **80** pixels.
  
   >Again we only want the form, in your next lab you will implement a functional calculator.
   

   
   <h2 align="center"> Calculator using the Grid Layout.</h2>
   
   now this is my code that i add to get this from.
      
   **.header**     
   
   ```cpp
   
  #ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include"QLineEdit"
#include"QLabel"
#include"QPushButton"
#include"QBoxLayout"
#include"QCheckBox"
#include"QLCDNumber"

class dialog : public QWidget
{

public:
    explicit dialog(QWidget *parent = nullptr);


protected:
void createwidgets();
void placewidgets();

protected:

QLCDNumber *afficheur;

     enum { NumDigitButtons = 10 };
     QPushButton *digitButtons[NumDigitButtons];
QPushButton *button;
};

#endif // DIALOG_H

   ```
**.cpp**

```cpp
#include "dialog.h"

dialog::dialog(QWidget *parent) : QWidget(parent)
{
    createwidgets();
    placewidgets();
}
void dialog::createwidgets(){

    afficheur=new QLCDNumber;
    afficheur->setDigitCount(6);
    afficheur->setMinimumHeight(80);


         for (int i = 0; i < NumDigitButtons; ++i) {
             digitButtons[i] = new QPushButton(QString::number(i));
         }
         button=new QPushButton("enter");
              }



void dialog::placewidgets(){
 QGridLayout *mainLayout = new QGridLayout;
 mainLayout->addWidget(afficheur, 0, 0, 1,3);


 int z=0;
       for (int i = 4; i >= 1; i--) {
          if(z==10)
           break;
           for (int j = 0; j < 3; j++){
               if(j>0 && i == 4)
                   break;
               else
            mainLayout->addWidget(digitButtons[z], i, j);
             z++;
           }
       }
   mainLayout->addWidget(button, 4, 1, 1, 2);
   this->setLayout(mainLayout);
}

```
 **main**
 
 ```cpp
 #include "mainwindow.h"

#include <QApplication>
#include"dialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   dialog *w=new dialog;
    w->show();
    return a.exec();
}

 ```
   this the interface of my code.

   <p align="center">
     <img src="images/ima.png">
   </p>  
       
   Our Team - [darkaoui hatim](https://github.com/hatimdeve) - [khaoula oularbi](https://github.com/Khawla1609)
 

Project Link: [https://github.com/hatimdeve/funwithlayout](https://github.com/hatimdeve/funwithlayout)

   <p align="right">(<a href="#top">back to top</a>)</p>
