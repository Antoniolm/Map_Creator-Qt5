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

private:
    Ui::MainWindow *ui;
    QList<AdvancedQLabel*> visibleMap;
    gameMap map;
};

#endif // MAINWINDOW_H
