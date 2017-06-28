#ifndef LIGHTNING_H
#define LIGHTNING_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QLinkedList>
#include<QObject>
#include<QTimer>

#include"unit.h"
#include"magic.h"

class lightning: public magic
{
public:
    lightning(QGraphicsScene *s, int x, int y);
    QGraphicsScene *s;
    void blast(QLinkedList<unit *> &list);
    int x,y;
public slots:
    void splash();
};

#endif // LIGHTNING_H
