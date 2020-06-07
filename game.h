#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QPushButton>
#include "card.h"
#include <vector>

//set default players to 2 (including dealer)

const constexpr int PLAYERS = 2;
const constexpr int WIDTH = 500;
const constexpr int HEIGHT = 300;


class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(int = PLAYERS);

public slots:
    void setNumberOfPlayers(int players);
    void startGame();
    void animate1();

signals:
    void gameStarted();
    void cardDrawn(int delay);


private:
    int num_of_cards;
    std::vector<Card*> cards;
    Card* card;
    Card* card2;

    std::vector<QPixmap> card_images;

    QRectF rect1;
    QRectF rect2;
    QRectF rect3;
    QRectF rect4;

    QPixmap* full_image;
    QPixmap card_image;

    void makeDeck();
    void refresh();
    void doDraw();

    QPushButton* draw;

    QLabel* dealer;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QTimer timer;
    int num_of_players;
};

#endif // GAME_H
