#ifndef UNIT_H
#define UNIT_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QLinkedList>
#include<QObject>

using namespace std;

class unit:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    unit(int hp, int atk, int minrange, int maxrange, int walk,int money, char weapon, bool canmove, bool cansummon, bool canattack);

    int hp;
    int atk;
    int posx;
    int posy;
    int group;
    int walk;
    int minrange;
    int maxrange;
    int money;
    char weapon;

    bool active;
    bool canmove;
    bool cansummon;
    bool canattack;

    bool summon;
    bool move;
    bool attack;


    void getPos();
    void attacking(unit *o,unit *t);
    void init(int group, QLinkedList<unit *> &list, QGraphicsScene *s, int x, int y);

};

#endif // UNIT_H
