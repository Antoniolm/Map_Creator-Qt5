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
std::pair<int,int> gameMap::getNumPages(){
    return numPages;
}
std::pair<int,int> gameMap::getSizeMap(){
    return sizeMap;
}
std::pair<int,int> gameMap::getCurrentPage(){
    return currentPage;
}
