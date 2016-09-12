///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <advancedqlabel.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AdvancedQLabel *label=new AdvancedQLabel("");
    for(int i=0;i<10;i++){
        label=new AdvancedQLabel("");
        connect(label,SIGNAL(clicked()),this,SLOT(onChanged()));
        ui->map_section->addWidget(label);
    }
    /*
QWidget *widget = new QWidget();
QHBoxLayout *hbox = new QHBoxLayout();
hbox->addWidget( label1 );
hbox->addWidget( label2 );
widget->setLayout( hbox );
mainwindow->setCentralWidget( widget );*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onChanged(){
    AdvancedQLabel *label=new AdvancedQLabel("2");
    connect(label,SIGNAL(clicked()),this,SLOT(onChanged()));
    ui->map_section->addWidget(label);

}
