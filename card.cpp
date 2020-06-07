#include "card.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QImage>
#include <QPixmap>


Card::Card()
{
    pic = new QPixmap(":/images/back.jpg");
    velocity = 80 * QPointF(cos(0.749),-1*sin(0.749));
}
QRectF Card::boundingRect() const
{//0,0 is current position, which is upper left corner
    return QRectF(x,y,73, 100);
}

//width: 73, height: 97
void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect sourceRectangle(x, y, 73, 100);

    painter->drawPixmap(sourceRectangle, *pic);

}

void Card::advance(int phase)
{
    //check if it's in the right spot
    if(phase == 0)
    {
        QPointF final_location = QPointF(170,7);
        if(velocity == final_location)
        {
            velocity = QPointF(0,0);
        }
    }



    if(phase == 1)
    {
        setPos(mapToScene(velocity/30));
    }
}

void Card::set(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
}
