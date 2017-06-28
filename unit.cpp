#include "unit.h"

unit::unit(int hp, int atk, int minrange, int maxrange, int walk,int money, char weapon, bool canmove, bool cansummon, bool canattack)
{
    this->hp=hp;
    this->atk=atk;
    this->minrange=minrange;
    this->maxrange=maxrange;
    this->walk=walk;
    this->money=money;
    this->weapon=weapon;
    this->canmove=canmove;
    this->cansummon=cansummon;
    this->canattack=canattack;
    this->summon=false;
    this->move=false;
    this->attack=false;
}
void unit::getPos()
{
    posx=(this->x()+184)/48;
    posy=(this->y()+154)/48;
}
void unit::attacking(unit *o,unit *t)
{
    if((o->weapon=='r'&&t->weapon=='g')||(o->weapon=='g'&&t->weapon=='b')||(o->weapon=='b'&&t->weapon=='r'))
    {
        t->hp=t->hp-(1.2*o->atk);
        o->hp=o->hp-(0.8*t->atk);
    }
    else if((o->weapon=='g'&&t->weapon=='r')||(o->weapon=='b'&&t->weapon=='g')||(o->weapon=='r'&&t->weapon=='b'))
    {
        t->hp=t->hp-(0.8*o->atk);
        o->hp=o->hp-(1.2*t->atk);
    }
    else
    {
        t->hp=t->hp-(1*o->atk);
        o->hp=o->hp-(1*t->atk);
    }
}
void unit::init(int group,QLinkedList<unit *> &list,QGraphicsScene *s,int x,int y)
{
    this->group=group;
    list.push_back(this);
    s->addItem(static_cast<QGraphicsPixmapItem*>(this));
    this->setPos(x,y-252);
    this->getPos();
    this->active=true;
}
