///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////


#include "gamemap.h"

gameMap::gameMap()
{
    numPages=0;
    sizeMap=0;
    currentPage=0;
}

void gameMap::setNumPages(std::pair<int,int> aNumPages){
    numPages=aNumPages;
}
void gameMap::setSizeMap(std::pair<int,int> aSizeMap){
    sizeMap=aSizeMap;
}
void gameMap::setCurrentPage(std::pair<int,int> aCPage){
   currentPage=aCPage;
}
