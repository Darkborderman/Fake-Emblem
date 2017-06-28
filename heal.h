#ifndef HEAL_H
#define HEAL_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QLinkedList>
#include<QObject>
#include<QTimer>

#include"unit.h"
#include"magic.h"

class heal: public magic
{
public:
    heal(QGraphicsScene *s, int x, int y);
    QGraphicsScene *s;
    void blast(QLinkedList<unit *> &list);
    int x,y;
public slots:
    void splash();
};

#endif // HEAL_H
