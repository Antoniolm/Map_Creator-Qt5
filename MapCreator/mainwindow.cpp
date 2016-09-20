 ///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QGraphicsView>
#include <database.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->line_section->setContentsMargins(0,0,0,0);
    ui->line_section->setFixedWidth(5);

    //Creamos la sección del mapa
    createMapSection();

    //Creamos la sección de las texturas
    createTextureSection();

    DataBase db();


}

MainWindow::~MainWindow()
{
    delete ui;
}

//////////////
/// \brief MyMainWindow::resizeEvent
/// \param event
/// Reimplementación del evento resize para que cuando se realice un cambio de
/// tamaño de la ventana principal se realice un ajuste de las imagenes de nuestro mapa
//////////////////////////////////
void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   qDebug()<< "Use the event";

   //Actualizamos el tamaño de las texturas de nuestro mapa visible
   for(int i=0;i<visibleMap.size();i++)
       for(int j=0;j<visibleMap[i].size();j++)
           visibleMap[i][j]->loadTexture();
}

///////////////////
/// \brief MainWindow::createMapSection
/// Método para la creación de la sección del mapa
/////////////////
void MainWindow::createMapSection(){
    AdvancedQLabel *label;
    QList<AdvancedQLabel*> auxList; //lista auxiliar para rellenar visibleMap

    QHBoxLayout *HBoxAllSection=new QHBoxLayout(); //Layout que contendra el mapa y los botones de navegación

    //Añadimos el qlabel para indicar la sección actual en el mapa
    nameSection=new QLabel("Section <-,->");
    nameSection->setAlignment(Qt::AlignCenter);
    nameSection->setStyleSheet("QLabel {border:1px solid black; background:#A78CC3; font-size:20px}");
    ui->map_section->addWidget(nameSection);


    //Creamos los botones para el movimiento por el mapa y vamos añadiendolos al
    //layout principal
    buttonLeft= new QPushButton("left");
    buttonLeft->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    buttonLeft->setStyleSheet("QPushButton {max-width:35px;}");
    connect(buttonLeft,SIGNAL(clicked(bool)),this,SLOT(on_buttonLeft()));
    buttonLeft->setEnabled(false);
    buttonLeft->setFocusPolicy(Qt::NoFocus);
    HBoxAllSection->addWidget(buttonLeft);

    QHBoxLayout *hBox;
    QVBoxLayout *vBoxMap = new QVBoxLayout();
    buttonUp= new QPushButton("up");
    connect(buttonUp,SIGNAL(clicked(bool)),this,SLOT(on_buttonUp()));
    buttonUp->setEnabled(false);
    buttonUp->setFocusPolicy(Qt::NoFocus);
    vBoxMap->addWidget(buttonUp);

    //Creamos la estructura principal del mapa
    //30x50 de AdvancedQLabel
    for(int i=0;i<30;i++){
        hBox = new QHBoxLayout();
        auxList.clear();
        for(int j=0;j<50;j++){
           label=new AdvancedQLabel("",15,15,30,30);
           connect(label,SIGNAL(clicked()),this,SLOT(onClicked()));
           connect(label,SIGNAL(move()),this,SLOT(onClicked()));
           auxList.append(label);
           hBox->addWidget(label);
        }
        visibleMap.append(auxList);
        vBoxMap->addLayout(hBox);
    }

    buttonDown= new QPushButton("down");
    connect(buttonDown,SIGNAL(clicked(bool)),this,SLOT(on_buttonDown()));
    buttonDown->setEnabled(false);
    buttonDown->setFocusPolicy(Qt::NoFocus);
    vBoxMap->addWidget(buttonDown);



    //Los añadimos
    //vBoxLabel->addWidget(nameSection);
    //vBoxLabel->addLayout(vBoxMap);
    HBoxAllSection->addLayout(vBoxMap);

    buttonRight= new QPushButton("right");
    buttonRight->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    buttonRight->setStyleSheet("QPushButton {max-width:35px;}");
    connect(buttonRight,SIGNAL(clicked(bool)),this,SLOT(on_buttonRight()));
    buttonRight->setEnabled(false);
    buttonRight->setFocusPolicy(Qt::NoFocus);

    HBoxAllSection->addWidget(buttonRight);
    ui->map_section->addLayout(HBoxAllSection);
    ui->map_section->setAlignment(Qt::AlignCenter);
    ui->map_section->setSpacing(0);
    ui->map_section->setMargin(0);
    ui->map_section->setContentsMargins(-5,-5,-5,-5);

}

///////////////////
/// \brief MainWindow::createTextureSection
/// Método para la creación de la sección para las texturas
//////////////////
void MainWindow::createTextureSection(){
    AdvancedQLabel *textura;
    QListWidgetItem *item;

    //Configuramos nuestro textureListWidget y texture_Section
    ui->textureListWidget->setMinimumHeight(300);
    ui->textureListWidget->setMinimumWidth(250);
    ui->textureListWidget->setMaximumHeight(600);
    ui->textureListWidget->setMaximumWidth(300);
    connect(ui->textureListWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(on_SelectTexture()));

    ui->texture_section->setMargin(0);
    ui->texture_section->setContentsMargins(-5,-5,-5,-5);
    ui->texture_section->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    //Realizamos la carga de las texturas
    //for(int i=0;i<10;i++){
        textura=new AdvancedQLabel("default.png",30,30,30,30);
        item = new QListWidgetItem();
        item->setText("default");
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(0,40));
        ui->textureListWidget->addItem(item);
        ui->textureListWidget->setItemWidget(item,textura);

        textura=new AdvancedQLabel("tierra.png",30,30,30,30);
        item = new QListWidgetItem();
        item->setText("tierra");
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(0,40));
        ui->textureListWidget->addItem(item);
        ui->textureListWidget->setItemWidget(item,textura);

        textura=new AdvancedQLabel("BorderInfDch.png",30,30,30,30);
        item = new QListWidgetItem();
        item->setText("BorderInfDch");
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(0,40));
        ui->textureListWidget->addItem(item);
        ui->textureListWidget->setItemWidget(item,textura);

        textura=new AdvancedQLabel("BorderInfIzq.png",30,30,30,30);
        item = new QListWidgetItem();
        item->setText("BorderInfIzq");
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(0,40));
        ui->textureListWidget->addItem(item);
        ui->textureListWidget->setItemWidget(item,textura);

        textura=new AdvancedQLabel("BorderSupDch.png",30,30,30,30);
        item = new QListWidgetItem();
        item->setText("BorderSupDch");
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(0,40));
        ui->textureListWidget->addItem(item);
        ui->textureListWidget->setItemWidget(item,textura);

        textura=new AdvancedQLabel("BorderSupIzq.png",30,30,30,30);
        item = new QListWidgetItem();
        item->setText("BorderSupIzq");
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(0,40));
        ui->textureListWidget->addItem(item);
        ui->textureListWidget->setItemWidget(item,textura);

        textura=new AdvancedQLabel("tierraIzq.png",30,30,30,30);
        item = new QListWidgetItem();
        item->setText("tierraIzq");
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(0,40));
        ui->textureListWidget->addItem(item);
        ui->textureListWidget->setItemWidget(item,textura);

        textura=new AdvancedQLabel("tierraDch.png",30,30,30,30);
        item = new QListWidgetItem();
        item->setText("tierraDch");
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(0,40));
        ui->textureListWidget->addItem(item);
        ui->textureListWidget->setItemWidget(item,textura);

        textura=new AdvancedQLabel("tierraInf.png",30,30,30,30);
        item = new QListWidgetItem();
        item->setText("tierraInf");
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(0,40));
        ui->textureListWidget->addItem(item);
        ui->textureListWidget->setItemWidget(item,textura);

        textura=new AdvancedQLabel("tierraDeep.png",30,30,30,30);
        item = new QListWidgetItem();
        item->setText("tierraDeep");
        item->setTextAlignment(Qt::AlignCenter);
        item->setSizeHint(QSize(0,40));
        ui->textureListWidget->addItem(item);
        ui->textureListWidget->setItemWidget(item,textura);

    //}



}

////////////////////////////
/// \brief MainWindow::updateVisibleMap
/// \param auxMap
/// Método privado para actualizar nuestro mapa visible
////////////////////////////
void MainWindow::updateVisibleMap(QList<QList<Cell>> &auxMap){

    for(int i=0;i<visibleMap.size();i++){
        for(int j=0;j<visibleMap[i].size();j++){
            visibleMap[i][j]->clear(); //limpiamos las texturas anteriores
            if(auxMap[i][j].hasTexture()){
                visibleMap[i][j]->setImgTexture(auxMap[i][j].getImgTexture());
                visibleMap[i][j]->loadTexture();
            }
        }
    }
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

    if(!currentTexture.isEmpty() && currentTexture!=label->getImgTexture()){
        label->setImgTexture(currentTexture);
        label->loadTexture();
    }
}


//////////////////////
/// \brief MainWindow::on_SelectTexture
/// Método activado cuando se clickea una textura
/// Seleccionara la textura para usarla en nuestro mapa
//////////////////////
void MainWindow::on_SelectTexture(){
    QListWidgetItem *item=ui->textureListWidget->currentItem();
    qDebug()<< "El texto es : "+item->text();

    currentTexture=item->text()+".png";
}

//////////////////////////////////
/// \brief MainWindow::on_buttonUp
/// Método para la navegación del usuario por el mapa actual
/// Realizara un cambio de sección del mapa y mostrara la
/// sección de arriba de la sección anterior
///////////////////////////////////////
void MainWindow::on_buttonUp(){
    std::pair<int,int> currPages=map.getCurrentPage();

    map.setCurrentVisibleMap(visibleMap);
    currPages.first--;

    //Actualizamos los botones y el mapa
    if(currPages.first==0)
        buttonUp->setEnabled(false);

    buttonDown->setEnabled(true);
    nameSection->setText("Section <"+QString::number(currPages.first)+","+QString::number(currPages.second)+">");
    map.setCurrentPage(currPages);
    updateVisibleMap(map.getCurrentVisibleMap());
}

//////////////////////////////////
/// \brief MainWindow::on_buttonDown
/// Método para la navegación del usuario por el mapa actual
/// Realizara un cambio de sección del mapa y mostrara la
/// sección de abajo de la sección anterior
///////////////////////////////////////
void MainWindow::on_buttonDown(){
    std::pair<int,int> numPages=map.getNumPages();
    std::pair<int,int> currPages=map.getCurrentPage();

    map.setCurrentVisibleMap(visibleMap);
    currPages.first++;

    //Actualizamos los botones y el mapa
    if(currPages.first==numPages.first-1)
        buttonDown->setEnabled(false);

    buttonUp->setEnabled(true);
    nameSection->setText("Section <"+QString::number(currPages.first)+","+QString::number(currPages.second)+">");
    map.setCurrentPage(currPages);
    updateVisibleMap(map.getCurrentVisibleMap());
}

//////////////////////////////////
/// \brief MainWindow::on_buttonLeft
/// Método para la navegación del usuario por el mapa actual
/// Realizara un cambio de sección del mapa y mostrara la
/// sección a la izquierda de la sección anterior
///////////////////////////////////////
void MainWindow::on_buttonLeft(){
    std::pair<int,int> currPages=map.getCurrentPage();

    map.setCurrentVisibleMap(visibleMap);
    currPages.second--;

    //Actualizamos los botones y el mapa
    if(currPages.second==0)
        buttonLeft->setEnabled(false);

    buttonRight->setEnabled(true);
    nameSection->setText("Section <"+QString::number(currPages.first)+","+QString::number(currPages.second)+">");
    map.setCurrentPage(currPages);
    updateVisibleMap(map.getCurrentVisibleMap());
}

//////////////////////////////////
/// \brief MainWindow::on_buttonRight
/// Método para la navegación del usuario por el mapa actual
/// Realizara un cambio de sección del mapa y mostrara la
/// sección a la derecha de la sección anterior
///////////////////////////////////////
void MainWindow::on_buttonRight(){
    std::pair<int,int> numPages=map.getNumPages();
    std::pair<int,int> currPages=map.getCurrentPage();

    map.setCurrentVisibleMap(visibleMap);
    currPages.second++;


    //Actualizamos los botones y el mapa
    if(currPages.second==numPages.second-1)
        buttonRight->setEnabled(false);

    buttonLeft->setEnabled(true);
    nameSection->setText("Section <"+QString::number(currPages.first)+","+QString::number(currPages.second)+">");
    map.setCurrentPage(currPages);
    updateVisibleMap(map.getCurrentVisibleMap());
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
    numPage.second=size.second/50;

    if(size.first%30 != 0) numPage.first++;
    if(size.second%50 != 0) numPage.second++;
    map.setNumPages(numPage);

    buttonRight->setEnabled(true);
    buttonDown->setEnabled(true);


    //Actualizamos el color de nuestro mapa visible y el Qlabel de nuestra sección actual
    for(int i=0;i<visibleMap.size();i++)
        for(int j=0;j<visibleMap[i].size();j++)
            visibleMap[i][j]->setStyleSheet("QLabel {background: white;border:1px solid gray;}");

    nameSection->setText("Section <0,0>");
    delete sizeMapDia;
}
