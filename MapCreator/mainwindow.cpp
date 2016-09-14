///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AdvancedQLabel *label;

    //Creamos los botones para el movimiento por el mapa y vamos añadiendolos al
    //layout principal
    QPushButton * pushButton= new QPushButton("right");
    pushButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    pushButton->setStyleSheet("QPushButton {max-width:30px;}");
    pushButton->setEnabled(false);
    ui->map_section->addWidget(pushButton);

    QHBoxLayout *hBox;
    QVBoxLayout *vBox = new QVBoxLayout();
    pushButton= new QPushButton("up");
    pushButton->setEnabled(false);
    vBox->addWidget(pushButton);

    //Creamos la estructura principal del mapa
    //30x40 de AdvancedQLabel
    for(int i=0;i<30;i++){
        hBox = new QHBoxLayout();
        for(int j=0;j<40;j++){
           label=new AdvancedQLabel("");
           connect(label,SIGNAL(clicked()),this,SLOT(onClicked()));
           visibleMap.append(label);
           hBox->addWidget(label);
        }
        vBox->addLayout(hBox);
    }

    pushButton= new QPushButton("down");
    pushButton->setEnabled(false);
    vBox->addWidget(pushButton);
    ui->map_section->addLayout(vBox);
    pushButton= new QPushButton("left");
    pushButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    pushButton->setEnabled(false);
    pushButton->setStyleSheet("QPushButton {max-width:30px;}");
    ui->map_section->addWidget(pushButton);
    ui->map_section->setSpacing(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//////////////////////
/// \brief MainWindow::onChanged
///
//////////////////////
void MainWindow::onClicked(){

    QPoint p = this->mapFromGlobal(QCursor::pos());
    AdvancedQLabel* label= static_cast<AdvancedQLabel*>(this->childAt(p.x(),p.y()));
    label->setStyleSheet("QLabel {background: blue;}");
}

///////////////////////
/// \brief MainWindow::on_actionNew_File_triggered
///
//////////////////////
void MainWindow::on_actionNew_File_triggered()
{
    sizeMapDialog *sizeMapDia=new sizeMapDialog();
    sizeMapDia->exec();
    std::pair<int,int> size=sizeMapDia->getSize();

    map.setSizeMap(size);

    std::pair<int,int> numPage;
    numPage.first=size.first/30;
    numPage.second=size.second/40;

    if(size.first%30 != 0) numPage.first++;
    if(size.second%40 != 0) numPage.second++;

    map.setNumPages(numPage);

    delete sizeMapDia;
}
