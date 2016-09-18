///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////


#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <advancedqlabel.h>
#include <cell.h>
#include <QMap>
#include <QDebug>

using namespace std;

class gameMap
{
public:
    gameMap();
    ~gameMap();
    void setNumPages(pair<int,int>);
    void setSizeMap(pair<int,int>);
    void setCurrentPage(pair<int,int>);
    void setCurrentVisibleMap(QList<QList<AdvancedQLabel*>> &);
    pair<int,int> getNumPages();
    pair<int,int> getSizeMap();
    pair<int,int> getCurrentPage();
    QList<QList<Cell>> & getCurrentVisibleMap();

private:
    QMap<pair<int,int>,Cell> textureMap;
    QList<QList<Cell>> auxVisibleMap;// visibleMap auxiliar que nos agilizara el obtener la sección actual del mapa
    pair<int,int> sizeMap;  //Nos indica el tamaño en celda de nuestro mapa <height,width>
    pair<int,int> numPages; //Nos indica el numero de paginas total <height,width>
    pair<int,int> cellPerPages; //Numero de celdas por pagina
    pair<int,int>currentPage; //Nos permite detectar que pagina del mapa es invisble
    void cleanVisibleMap(); //Método para limpiar nuestro visibleMap local
};

#endif // GAMEMAP_H
