#ifndef PARTICULA_H
#define PARTICULA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <iostream>
#include "math.h"
#define g 9.8
#define pi 3.1415
using namespace std;

class Particula : public QGraphicsItem
{

public:


    Particula(float m_x, float m_y, float m_r): px(m_x), py(m_y), r(m_r), y0(py),x0(px){vx=80;vy=80;t=0;ang=45;}
    void mover(float vertlim);
    void colision(float horzlim, float vertlim);
    void setVelocidad(float vx, float vy);
    void setPosicion(float x, float y);
    float getR();
    float getPx();
    float getPy();
    float getVx();
    float getVy();
    void setangulo(int a);
    int getangulo();


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
 private:
    float px;
    float py;
    float r;
    float vx;
    float vy;
    float y0;
    float x0;
    int ang;
    float t;
    Particula();
};

#endif // PARTICULA_H
