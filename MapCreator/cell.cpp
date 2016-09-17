///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "cell.h"

Cell::Cell()
{

}

///
/// \brief Cell::setImgTexture
///
void Cell::setImgTexture(QString textu){
    imgTexture=textu;
}

///
/// \brief Cell::setState
///
void Cell::setState(QString &stat){
    state=stat;
}

///
/// \brief Cell::getImgTexture
/// \return
///
QString Cell::getImgTexture(){
    return imgTexture;
}

///
/// \brief Cell::getState
/// \return
///
QString Cell::getState(){
    return state;
}
