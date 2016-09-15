///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <sizemapdialog.h>
#include <advancedqlabel.h>
#include <QPushButton>
#include <gamemap.h>
#include <textureqlabel.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onClicked();

    void on_actionNew_File_triggered();
    //slot para la navegación por el mapa
    void on_buttonUp();
    void on_buttonDown();
    void on_buttonLeft();
    void on_buttonRight();

private:
    void createMapSection();
    void createTextureSection();
    Ui::MainWindow *ui;
    QPushButton *buttonUp,*buttonDown,*buttonLeft,*buttonRight;
    QList<AdvancedQLabel*> visibleMap;
    gameMap map;
    QLabel *nameSection;
};

#endif // MAINWINDOW_H
