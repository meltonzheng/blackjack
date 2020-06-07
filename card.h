#ifndef CARD_H
#define CARD_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QObject>

const constexpr float FRAMES_PER_SECOND = 30;

class Card : public QGraphicsItem
{
private:
    int val;
    QPixmap* pic;
    int x = 70;
    int y = 100;
    void check();
    bool isMoving;

    QPointF velocity;

    QPointF destination;

public:
    Card();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void advance(int phase = 1) override;

    void set(int new_x, int new_y);

    bool moving();

};

#endif // CARD_H
