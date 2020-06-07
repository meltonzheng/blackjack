#include "game.h"
#include "card.h"
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QObject>
#include <QGraphicsView>
#include <iostream>

/*QObject::connect(start,
                     &QPushButton::clicked,
                     this,
                     &MainWindow::startPressed);
 * images = new QPixmap(":/images/cards.jpg");

    card_one = new Card(images, 0, 0, 73, 97, 13, 2, 1);

    QGraphicsScene* scene = new QGraphicsScene();
    scene -> setSceneRect(0,0,450,450);
    QGraphicsView * view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing, true);
    card_one->setPos(100,100);
    scene->addItem(card_one);

    QObject::connect(&timer, &QTimer::timeout, scene, &QGraphicsScene::advance);

    setCentralWidget(view);

    timer.start(1000/30);
 */

Game::Game(int nplayers)
    : QWidget(nullptr)
  , dealer(new QLabel)
  , num_of_players(nplayers)
  , scene(new QGraphicsScene(QRectF(0,0,WIDTH,HEIGHT)))
  , view(new QGraphicsView())
{
//    QObject::connect(this,
//                         &Game::gameStarted,
//                         this,
//                         &Game::makeDeck);

//    std::cout << "works";
 //   scene->addItem(card);

    rect1 = QRectF(170,7, 73,100);
    rect2 = QRectF(257,7, 73,100);
    rect3 = QRectF(170,193,73,100);
    rect4 = QRectF(257,193,73,100);

    num_of_cards = 51;
    scene->addRect(rect1);
    scene->addRect(rect2);
    scene->addRect(rect3);
    scene->addRect(rect4);

    QRectF rect1_test = QRectF(170+73, 7, 1,1);
    scene->addRect(rect1_test);
    view->setScene(scene);
    view->setRenderHint(QPainter::Antialiasing, true);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(view);
    draw = new QPushButton("First Draw");
    layout->addWidget(draw,0,Qt::AlignHCenter);
    setLayout(layout);
    refresh();

    QObject::connect(draw,
                     &QPushButton::clicked,
                     this,
                     &Game::doFirstDraw);




}
void Game::makeDeck()
{

    //ace's have special values so...




    //from 2 -> king
    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            card_image = full_image->copy(i*73,j*100,73,100);

            if(i >= 10)
            {
                card_images.push_back(card_image);
            }
            else
            {
                card_images.push_back(card_image);
            }
        }
    }
}
void Game::setNumberOfPlayers(int nplayers)
{
    this->num_of_players = nplayers;
    refresh();
}
void Game::startGame()
{
    full_image = new QPixmap(":/images/cards.jpg");
    card_image = full_image->copy(0*73,0*97,73,97);
    this->makeDeck();

    card = new Card();

    scene->addItem(card);

    card2 = new Card();
    card2->set(370, 100);
//    QGraphicsScene* scene2 = new QGraphicsScene(QRectF(0,0,WIDTH,HEIGHT));
//    view->setScene(scene2);
    scene->addItem(card2);

    emit gameStarted();
}
void Game::refresh()
{
//    for(auto x : card_images)
//    {
//        scene->addPixmap(x);
//    }
}
void Game::doFirstDraw()
{


    if( num_of_cards + 1 <= card_images.size() )
    {
        int index = rand() % num_of_cards + 1;

        num_of_cards--;

        QPolygon test = view->mapFromScene(rect1);

        scene->addPixmap(card_images.at(index));

        card_images.erase(card_images.begin() + index);

    }

}

