#include "particula.h"

Particula::Particula()
{

}

float Particula::getPx()
{
    return px;
}

float Particula::getPy()
{
    return py;
}

float Particula::getVx()
{
    return vx;
}

float Particula::getVy()
{
    return vy;
}

float Particula::getR()
{
    return r;
}

void Particula::setVelocidad(float velx, float vely)
{
    vx=velx;
    vy=vely;
}


void Particula::setPosicion(float x, float y)
{
    px=x;
    py=y;
}

void Particula::setangulo(int a)
{
    ang=a;
}

int Particula::getangulo()
{
    return  ang;
}

void Particula::mover(float vertlim)
{


    px=x0+vx*cos((ang*pi)/180)*t;  //Ecuacion para calcular posicion en x
    py=y0+(vy*sin((ang*pi)/180)*t)-0.5*g*pow(t,2);  //Ecuacion para calcular posicion en y
    t=t+0.1; //Contador para aumentar el tiempo
    setPos(getPx(),(vertlim-getPy()));

 }

void Particula::colision(float horzlim, float vertlim)
{
if (getPx()<getR() || getPx()>horzlim-getR()){
    setVelocidad(-1*getVx(), getVy());
}
if (getPy()<getR() || getPy()>horzlim-getR()){
    setVelocidad(getVx(), -1*getVy());
}
}

QRectF Particula::boundingRect() const
{
    return QRectF(-1*r, -1*r, 2*r, 2*r);
}


void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
 painter->setBrush(Qt::darkGreen);
 painter->drawEllipse(boundingRect());
}
