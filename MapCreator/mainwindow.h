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
#include <QListWidgetItem>

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
    void on_SelectTexture();


protected:
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private:
    void createMapSection();
    void createTextureSection();
    Ui::MainWindow *ui;
    QPushButton *buttonUp,*buttonDown,*buttonLeft,*buttonRight;
    QList<QList<AdvancedQLabel*>> visibleMap;
    gameMap map;
    QLabel *nameSection;
    QString currentTexture;
};

#endif // MAINWINDOW_H
