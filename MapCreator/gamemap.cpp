///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////


#include "gamemap.h"

gameMap::gameMap()
{
    numPages.first=0;
    numPages.second=0;

    sizeMap.first=0;
    sizeMap.second=0;

    currentPage.first=0;
    currentPage.second=0;

    cellPerPages.first=30;
    cellPerPages.second=50;

    QList<Cell> auxList;
    Cell auxCell;

    for(int j=0;j<cellPerPages.second;j++)
        auxList.append(auxCell);

    for(int i=0;i<cellPerPages.first;i++)
        auxVisibleMap.append(auxList);


}

gameMap::~gameMap(){

}


///
/// \brief gameMap::setNumPages
/// \param aNumPages
///
void gameMap::setNumPages(pair<int,int> aNumPages){
    numPages=aNumPages;
}

///
/// \brief gameMap::setSizeMap
/// \param aSizeMap
///
void gameMap::setSizeMap(pair<int,int> aSizeMap){
    sizeMap=aSizeMap;
}

///
/// \brief gameMap::setCurrentPage
/// \param aCPage
///
void gameMap::setCurrentPage(pair<int,int> aCPage){
   currentPage=aCPage;
}

////////////////
/// \brief setCurrentVisibleMap
/// \param visibleMap
/// Método para guardar en nuestro mapa global las texturas almacenadas en el página
/////////////////////////
void gameMap::setCurrentVisibleMap(QList<QList<AdvancedQLabel*>> &visibleMap){
    Cell auxCell;
    int newKey;
    //qDebug()<< "Pagina<"+ QString::number(currentPage.first)+ ","+QString::number(currentPage.second)+">";

    //Bucle para recorrer el visibleMpa y guardarlo en nuestro mapa global
    for(int i=0;i<visibleMap.size();i++)
        for(int j=0;j<visibleMap[i].size();j++){
            if(visibleMap[i][j]->hasTexture()){ //Si tiene textura cargada
                auxCell.setPosition((cellPerPages.first*currentPage.first)+i,(cellPerPages.second*currentPage.second)+j);
                auxCell.setImgTexture(visibleMap[i][j]->getImgTexture());
                newKey= (cellPerPages.first*currentPage.first)+i;
                //qDebug()<< "Position<"+ QString::number((cellPerPages.first*currentPage.first)+i)+ ","+QString::number((cellPerPages.second*currentPage.second)+j)+">";
                textureMap.insert(newKey,auxCell);
            }
        }
}

///
/// \brief gameMap::getNumPages
/// \return
///
pair<int,int> gameMap::getNumPages(){
    return numPages;
}

///
/// \brief gameMap::getSizeMap
/// \return
///
pair<int,int> gameMap::getSizeMap(){
    return sizeMap;
}

///
/// \brief gameMap::getCurrentPage
/// \return
///
pair<int,int> gameMap::getCurrentPage(){
    return currentPage;
}

///////////////////
/// \brief getCurrentVisibleMap
/// \return
/// Método para devolver las texturas que contenta la página actual
//////////////////
QList<QList<Cell>> & gameMap::getCurrentVisibleMap(){

    cleanVisibleMap();
    int initHeight=currentPage.first*cellPerPages.first;
    int initWidth=currentPage.second*cellPerPages.second;
    int endHeight=initHeight+cellPerPages.first;
    int endWidth=initWidth+cellPerPages.second;

    pair<int,int> clave;
    int visibleHeight,visibleWidth; //variables usadas para convertira a posiciones de mapa visible la posiciones del mapa


    QMultiMap<int,Cell>::Iterator it =textureMap.lowerBound(initHeight);

    //Si encuentra un elemento que cumpla con estas condiciones entra al bucle
    while(it!=textureMap.end() && ((*it).getPosition()).first<endHeight){
        pair<int,int> clave=(*it).getPosition();
        //Comprobamos que el ancho es el correcto
        if(clave.second>=initWidth && clave.second<endWidth){
            visibleHeight=clave.first-(cellPerPages.first*currentPage.first);
            visibleWidth=clave.second-(cellPerPages.second*currentPage.second);
            auxVisibleMap[visibleHeight][visibleWidth].setImgTexture((*it).getImgTexture());
            qDebug()<< "Position<"+QString::number((*it).getPosition().first) +","+QString::number((*it).getPosition().second)+">";
        }

        it++;
    }
    return auxVisibleMap;
}

///
/// \brief cleanVisibleMap
///
void gameMap::cleanVisibleMap(){
    for(int i=0;i<cellPerPages.first;i++){
        for(int j=0;j<cellPerPages.second;j++)
            auxVisibleMap[i][j].clear();
    }

}
