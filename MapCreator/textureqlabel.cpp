///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "textureqlabel.h"

TextureQLabel::TextureQLabel(QWidget *parent) : QVBoxLayout(parent)
{
    texture=new QLabel("");
    texture->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    texture->setMinimumHeight(50);
    texture->setMinimumWidth(50);
    texture->setMaximumHeight(100);
    texture->setMaximumWidth(100);
    texture->setStyleSheet("QLabel {background: blue;}");
    QPixmap pixmap(":/texture/texture/default.png");
    texture->setPixmap(pixmap);
    texture->show();

    stateTexture=new QLabel("");
    stateTexture->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    stateTexture->setMinimumHeight(10);
    stateTexture->setMinimumWidth(10);
    stateTexture->setMaximumHeight(30);
    stateTexture->setMaximumWidth(100);
    stateTexture->setStyleSheet("QLabel {background: red;}");


    this->setSpacing(0);
    this->addWidget(texture);
    this->addWidget(stateTexture);

}

