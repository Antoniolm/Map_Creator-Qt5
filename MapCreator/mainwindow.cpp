///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *label=new QLabel("1");
    for(int i=0;i<40;i++){
        label=new QLabel("1");
        ui->map_section->addWidget(label);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
