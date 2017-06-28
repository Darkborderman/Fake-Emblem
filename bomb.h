#ifndef BOMB_H
#define BOMB_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QLinkedList>
#include<QObject>
#include<QTimer>

#include"unit.h"
#include"magic.h"

class bomb:public magic
{
public:
    bomb(QGraphicsScene *s, int x, int y);
    QGraphicsScene *s;
    int x,y;
    void blast(QLinkedList<unit *> &list);
public slots:
    void splash();
};

#endif // BOMB_H
