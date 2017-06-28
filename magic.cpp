#include "magic.h"

magic::magic(){}
magic::magic(int atk, int tick)
{
    this->atk=atk;
    this->tick=tick;
    for(int i=0;i<=12;i++)
    {
        for(int j=0;j<=15;j++) pict[i][j]=new QGraphicsPixmapItem;
    }
}
void magic::splash(){}
void magic::blast(QLinkedList<unit *> &list){}
