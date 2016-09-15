///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "textureqlabel.h"

TextureQLabel::TextureQLabel(QWidget *parent) : QVBoxLayout(parent)
{
    texture=new QLabel("");
    texture->setFixedHeight(50);
    texture->setFixedWidth(50);
    //texture->setStyleSheet("QLabel {background: blue;}");
    QPixmap pixmap(":/texture/texture/default.png");
    texture->setPixmap(pixmap);
    texture->show();

    stateTexture=new QLabel("");
    stateTexture->setFixedHeight(10);
    stateTexture->setFixedWidth(50);
    stateTexture->setStyleSheet("QLabel {background: red;}");


    this->setSpacing(0);
    this->addWidget(texture);
    this->addWidget(stateTexture);

}

