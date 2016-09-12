///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#ifndef SIZEMAPDIALOG_H
#define SIZEMAPDIALOG_H

#include <QDialog>

namespace Ui {
class sizeMapDialog;
}

class sizeMapDialog : public QDialog
{
    Q_OBJECT
public:
    explicit sizeMapDialog();
    ~sizeMapDialog();
    std::pair<int,int> getSize();
signals:

public slots:

private slots:
    void on_CreateMaButton_clicked();

private:
    Ui::sizeMapDialog *ui;
    int height,width;

};

#endif // SIZEMAPDIALOG_H
