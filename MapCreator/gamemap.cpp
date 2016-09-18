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
///
/////////////////////////
void gameMap::setCurrentVisibleMap(QList<QList<AdvancedQLabel*>> &visibleMap){
    Cell auxCell;
    //qDebug()<< "Pagina<"+ QString::number(currentPage.first)+ ","+QString::number(currentPage.second)+">";
    for(int i=0;i<visibleMap.size();i++)
        for(int j=0;j<visibleMap[i].size();j++){
            if(visibleMap[i][j]->hasTexture()){ //Si tiene textura cargada
                auxCell.setImgTexture(visibleMap[i][j]->getImgTexture());
                //qDebug()<< "Position<"+ QString::number((cellPerPages.first*currentPage.first)+i)+ ","+QString::number((cellPerPages.second*currentPage.second)+j)+">";
                textureMap.insert(make_pair((cellPerPages.first*currentPage.first)+i,(cellPerPages.second*currentPage.second)+j),auxCell);
            }
        }
    /*pair<int,int> clave;
    QMap<pair<int,int>,Cell>::Iterator it;
    for(it=textureMap.begin();it!=textureMap.end();it++){
            pair<int,int> clave=it.key();
            qDebug()<<"Key<"+QString::number(clave.first)+","+QString::number(clave.second)+">"+"->"+(*it).getImgTexture();
    }*/
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

///
/// \brief getCurrentVisibleMap
/// \return
///
QList<QList<Cell>> & gameMap::getCurrentVisibleMap(){

    cleanVisibleMap();
    int initHeight=currentPage.first*cellPerPages.first;
    int initWidth=currentPage.second*cellPerPages.second;
    int endHeight=initHeight+cellPerPages.first;
    int endWidth=initWidth+cellPerPages.second;

    pair<int,int> clave;
    int visibleHeight,visibleWidth; //variables usadas para convertira a posiciones de mapa visible la posiciones del mapa
    QMap<pair<int,int>,Cell>::Iterator it;
    for(it=textureMap.begin();it!=textureMap.end();it++){
            pair<int,int> clave=it.key();
            visibleHeight=clave.first-(cellPerPages.first*currentPage.first);
            visibleWidth=clave.second-(cellPerPages.second*currentPage.second);

            if((clave.first>=initHeight && clave.first<endHeight)&& (clave.second>=initWidth && clave.second<endWidth)){
                auxVisibleMap[visibleHeight][visibleWidth].setImgTexture((*it).getImgTexture());
                qDebug()<< "The aplication go inside the if";
            }
            //qDebug()<<"Key<"+QString::number(clave.first)+","+QString::number(clave.second)+">"+"->"+(*it).getImgTexture();
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
