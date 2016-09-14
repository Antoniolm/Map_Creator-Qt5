///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "sizemapdialog.h"
#include "ui_sizemapdialog.h"

sizeMapDialog::sizeMapDialog() : QDialog(0),ui(new Ui::sizeMapDialog)
{
    ui->setupUi(this);
    height=0;
    width=0;
    ui->cellheight->setMaximum(1000);
    ui->cellheight->setMinimum(100);
    ui->cellwidth->setMaximum(1000);
    ui->cellwidth->setMinimum(100);
}
sizeMapDialog::~sizeMapDialog(){
    delete ui;

}


void sizeMapDialog::on_CreateMaButton_clicked()
{
    height=ui->cellheight->value();
    width=ui->cellwidth->value();
    close();
}

std::pair<int,int> sizeMapDialog::getSize(){
    std::pair<int,int> salida;
    salida.first=height;
    salida.second=width;
    return salida;
}
