#ifndef MAGIC_H
#define MAGIC_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QLinkedList>
#include<QObject>
#include"unit.h"
#include<QTimer>
class magic:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    magic();
    magic(int atk,int tick);
    QGraphicsScene *s;
    QGraphicsPixmapItem *pict[13][16];
    int atk,tick;
    int posx,posy;
    virtual void blast(QLinkedList<unit *> &list);
public slots:
    virtual void splash();
};

#endif // MAGIC_H
