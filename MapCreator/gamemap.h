///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////


#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <advancedqlabel.h>

class gameMap
{
public:
    gameMap();
    void setNumPages(std::pair<int,int>);
    void setSizeMap(std::pair<int,int>);
    void setCurrentPage(std::pair<int,int>);
    std::pair<int,int> getNumPages();
    std::pair<int,int> getSizeMap();
    std::pair<int,int> getCurrentPage();

private:
    QList<AdvancedQLabel*> map;
    std::pair<int,int> sizeMap;  //Nos indica el tamaño en celda de nuestro mapa <height,width>
    std::pair<int,int> numPages; //Nos indica el numero de paginas total <height,width>
    std::pair<int,int>currentPage; //Nos permite detectar que pagina del mapa es invisble
};

#endif // GAMEMAP_H
