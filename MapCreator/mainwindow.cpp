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
    ui->line_section->setContentsMargins(0,0,0,0);
    ui->line_section->setFixedWidth(5);
    //QScrollArea* scrollArea = new QScrollArea;
    //scrollArea->setWidget(this);
    //Creamos la sección del mapa
    createMapSection();

    //Creamos la sección de las texturas
    createTextureSection();

}

MainWindow::~MainWindow()
{
    delete ui;
}

///////////////////
/// \brief MainWindow::createMapSection
/// Método para la creación de la sección del mapa
/////////////////
void MainWindow::createMapSection(){
    AdvancedQLabel *label;
    ui->map_section->setAlignment(Qt::AlignCenter);

    //Creamos los botones para el movimiento por el mapa y vamos añadiendolos al
    //layout principal
    buttonLeft= new QPushButton("left");
    buttonLeft->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    buttonLeft->setStyleSheet("QPushButton {max-width:35px;}");
    connect(buttonLeft,SIGNAL(clicked(bool)),this,SLOT(on_buttonLeft()));
    buttonLeft->setEnabled(false);
    buttonLeft->setFocusPolicy(Qt::NoFocus);
    ui->map_section->addWidget(buttonLeft);

    QHBoxLayout *hBox;
    QVBoxLayout *vBox = new QVBoxLayout();
    buttonUp= new QPushButton("up");
    connect(buttonUp,SIGNAL(clicked(bool)),this,SLOT(on_buttonUp()));
    buttonUp->setEnabled(false);
    buttonUp->setFocusPolicy(Qt::NoFocus);
    vBox->addWidget(buttonUp);

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

    buttonDown= new QPushButton("down");
    connect(buttonDown,SIGNAL(clicked(bool)),this,SLOT(on_buttonDown()));
    buttonDown->setEnabled(false);
    buttonDown->setFocusPolicy(Qt::NoFocus);
    vBox->addWidget(buttonDown);

    ui->map_section->addLayout(vBox);

    buttonRight= new QPushButton("right");
    buttonRight->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    buttonRight->setStyleSheet("QPushButton {max-width:35px;}");
    connect(buttonRight,SIGNAL(clicked(bool)),this,SLOT(on_buttonRight()));
    buttonRight->setEnabled(false);
    buttonRight->setFocusPolicy(Qt::NoFocus);

    ui->map_section->addWidget(buttonRight);
    ui->map_section->setSpacing(0);
    ui->map_section->setMargin(0);
    ui->map_section->setContentsMargins(-5,-5,-5,-5);

}

///////////////////
/// \brief MainWindow::createTextureSection
/// Método para la creación de la sección para las texturas
//////////////////
void MainWindow::createTextureSection(){
    QHBoxLayout *hBox=new QHBoxLayout();

    ui->texture_section->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    TextureQLabel *textura=new TextureQLabel();
    hBox->addLayout(textura);
    textura=new TextureQLabel();
    hBox->addLayout(textura);
    textura=new TextureQLabel();
    hBox->addLayout(textura);
    ui->texture_section->addLayout(hBox);
    ui->texture_section->setMargin(0);
    ui->texture_section->setContentsMargins(-5,-5,-5,-5);

}

//////////////////////
/// \brief MainWindow::onClicked
/// Método activado cuando se clickea una posicion del mapa
/// Realizara un cambio de imagen en la posicion del mapa teniendo en cuenta
/// la textura que se tenga seleccionada en el layout texture_setion
//////////////////////
void MainWindow::onClicked(){

    QPoint p = this->mapFromGlobal(QCursor::pos());
    AdvancedQLabel* label= static_cast<AdvancedQLabel*>(this->childAt(p.x(),p.y()));
    label->setStyleSheet("QLabel {background: blue;}");
}

//////////////////////////////////
/// \brief MainWindow::on_buttonUp
/// Método para la navegación del usuario por el mapa actual
/// Realizara un cambio de sección del mapa y mostrara la
/// sección de arriba de la sección anterior
///////////////////////////////////////
void MainWindow::on_buttonUp(){
    std::pair<int,int> size=map.getSizeMap();
    std::pair<int,int> numPages=map.getNumPages();
    std::pair<int,int> currPages=map.getCurrentPage();

    currPages.first--;

    if(currPages.first==0)
        buttonUp->setEnabled(false);

    buttonDown->setEnabled(true);

    map.setCurrentPage(currPages);

}

//////////////////////////////////
/// \brief MainWindow::on_buttonDown
/// Método para la navegación del usuario por el mapa actual
/// Realizara un cambio de sección del mapa y mostrara la
/// sección de abajo de la sección anterior
///////////////////////////////////////
void MainWindow::on_buttonDown(){
    std::pair<int,int> size=map.getSizeMap();
    std::pair<int,int> numPages=map.getNumPages();
    std::pair<int,int> currPages=map.getCurrentPage();

    currPages.first++;

    if(currPages.first==numPages.first-1)
        buttonDown->setEnabled(false);

    buttonUp->setEnabled(true);

    map.setCurrentPage(currPages);
}

//////////////////////////////////
/// \brief MainWindow::on_buttonLeft
/// Método para la navegación del usuario por el mapa actual
/// Realizara un cambio de sección del mapa y mostrara la
/// sección a la izquierda de la sección anterior
///////////////////////////////////////
void MainWindow::on_buttonLeft(){
    std::pair<int,int> size=map.getSizeMap();
    std::pair<int,int> numPages=map.getNumPages();
    std::pair<int,int> currPages=map.getCurrentPage();

    currPages.second--;

    if(currPages.second==0)
        buttonLeft->setEnabled(false);

    buttonRight->setEnabled(true);

    map.setCurrentPage(currPages);
}

//////////////////////////////////
/// \brief MainWindow::on_buttonRight
/// Método para la navegación del usuario por el mapa actual
/// Realizara un cambio de sección del mapa y mostrara la
/// sección a la derecha de la sección anterior
///////////////////////////////////////
void MainWindow::on_buttonRight(){
    std::pair<int,int> size=map.getSizeMap();
    std::pair<int,int> numPages=map.getNumPages();
    std::pair<int,int> currPages=map.getCurrentPage();

    currPages.second++;

    if(currPages.second==numPages.second-1)
        buttonRight->setEnabled(false);

    buttonLeft->setEnabled(true);

    map.setCurrentPage(currPages);

}

/////////////////////////
/// \brief MainWindow::on_actionNew_File_triggered
/// Método en el cual se crea un nuevo mapa y se realiza la configuración inicial
/// de nuestro objeto de la clase gameMap
/////////////////////////
void MainWindow::on_actionNew_File_triggered()
{
    sizeMapDialog *sizeMapDia=new sizeMapDialog();
    sizeMapDia->exec();
    std::pair<int,int> size=sizeMapDia->getSize();

    //Configuramos el tamaño del mapa
    if(size.first<100)size.first=100;
    if(size.second<100)size.second=100;
    map.setSizeMap(size);

    //Configuramos el numero de secciones del mapa
    std::pair<int,int> numPage;
    numPage.first=size.first/30;
    numPage.second=size.second/40;

    if(size.first%30 != 0) numPage.first++;
    if(size.second%40 != 0) numPage.second++;
    map.setNumPages(numPage);

    buttonRight->setEnabled(true);
    buttonDown->setEnabled(true);


    //Actualizamos el color de nuestro mapa visible
    for(int i=0;i<visibleMap.size();i++){
        visibleMap[i]->setStyleSheet("QLabel {background: white;border:1px solid gray;}");
    }

    delete sizeMapDia;
}
