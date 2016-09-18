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

////////////////////7
/// \brief Cell::hasTexture
/// \return
/// Método que nos devuelve true si la celda tiene una textura asignada
/// y false si no tiene textura
////////////////////////
bool Cell::hasTexture(){
    bool salida=true;
    if(imgTexture.isEmpty()){
        salida=false;
    }
    return salida;
}

//////////////////////////
/// \brief Cell::clear
/// Método para limpiar nuestro objecto cell
/////////////////////////
void Cell::clear(){
    imgTexture.clear();
    state.clear();
}

