///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <advancedqlabel.h>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AdvancedQLabel *label=new AdvancedQLabel("");
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
    AdvancedQLabel *label;


    QPushButton * pushButton= new QPushButton("1-4");
    pushButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    ui->map_section->addWidget(pushButton);

    pushButton= new QPushButton("2-3");
    QVBoxLayout *vBox = new QVBoxLayout();;
    vBox->addWidget(pushButton);

    QHBoxLayout *hBox;


    for(int i=0;i<size.first;i++){
        hBox = new QHBoxLayout();
        for(int j=0;j<size.second;j++){
           label=new AdvancedQLabel("");
            hBox->addWidget(label);
        }
        vBox->addLayout(hBox);

    }

    pushButton= new QPushButton("3-2");
    vBox->addWidget(pushButton);
    ui->map_section->addLayout(vBox);
    pushButton= new QPushButton("1-4");
    pushButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    ui->map_section->addWidget(pushButton);

}
