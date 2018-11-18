#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <QMainWindow>
#include <QGraphicsScene>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <particula.h>
#include <QTimer>
#include <cstdlib>


#define ANCHO 750
#define ALTO 425
#define DT 100

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
//class MainWindow : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void on_pushButton_clicked_2();
    void on_pushButton_clicked();
    void actualizar_escena();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QTimer *timer = nullptr;
    QGraphicsScene *scene = nullptr;
    Particula *particula = nullptr;

};




#endif // MAINWINDOW_H

