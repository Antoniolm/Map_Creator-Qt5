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

///
/// \brief MainWindow::onChanged
///
void MainWindow::onChanged(){
    AdvancedQLabel *label=new AdvancedQLabel("2");
    connect(label,SIGNAL(clicked()),this,SLOT(onChanged()));
    ui->map_section->addWidget(label);

}

///
/// \brief MainWindow::on_actionNew_File_triggered
///
void MainWindow::on_actionNew_File_triggered()
{
    sizeMapDialog *sizeMapDia=new sizeMapDialog();
    sizeMapDia->exec();
    std::pair<int,int> size=sizeMapDia->getSize();

   // for(int i=0;i<size.first;i++)
    //    for(int j=0;j<size.second;j++)

}
