#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "particula.h"
#include "QGraphicsScene"
bool toStop;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
     setWindowTitle("Movimiento Parabolico");
    srand(time(NULL));
    timer=new QTimer(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,ANCHO,ALTO);

    ui->graphicsView->setScene(scene);

    scene->addRect(scene->sceneRect());

    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100,ui->graphicsView->height()+100);

    particula = new Particula(25,25,15);
    scene->addItem(particula);
    particula->mover(ALTO);

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar_escena()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete particula;
    delete timer;
    delete scene;
}


void MainWindow::on_pushButton_clicked()
{

    timer->start(20);
}
//void MainWindow::on_pushButton_clicked_2()
//{
//toStop=true;
//}

void MainWindow::actualizar_escena()
{
//const int itemsToAdd=10;
//toStop=false;
//for (int i=0;i<itemsToAdd;i++)
//{
    particula->mover(ALTO);
    particula->colision(ANCHO, ALTO);
//  QCoreApplication::processEvents();
//if(toStop)
//    break;

//}
}
