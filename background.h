#ifndef BACKGROUND_H
#define BACKGROUND_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<QString>
#include<iostream>
#include<algorithm>

#include"unit.h"
#include"axe_infantry.h"
#include"grand_castle.h"
#include"sword_armored.h"
#include"sword_infantry.h"
#include"sword_calvery.h"
#include"spear_armored.h"
#include"spear_calvery.h"
#include"spear_infantry.h"
#include"axe_calvery.h"
#include"axe_armored.h"
#include"bow_infantry.h"
#include"longbow_infantry.h"
#include"spear_calvery_throwing.h"
#include"axe_calvery_throwing.h"
#include"red_magic_infantry.h"
#include"blue_magic_infantry.h"
#include"green_magic_infantry.h"
#include"sword_infantry_throwing.h"
#include"sword_infantry_lord.h"
#include"spear_calvery_lord.h"
#include"bow_calvery.h"

class background: public QGraphicsPixmapItem
{
public:
    background();
    void setbattle(QGraphicsScene *s);
    void setbattlephase(int phase);
    void setbattlestat(unit *u);
    void setbattlefog(QLinkedList<unit *> &list, int phase);
    bool setbattleresult(QGraphicsScene *s, QLinkedList<unit *> &list);
    void setstart(QGraphicsScene *s);
    void setmanage(QGraphicsScene *s);
    void setrank(QGraphicsScene *s);
    void setrank(QGraphicsScene *s, QStringList sl);
    void setdraw(QGraphicsScene *s);
    void setpage(int page);
    void setdrawresult(int i);
    void showcard(int i, int num);
    void hidecard();
    void setdrawmoney(int money);
    QGraphicsTextItem *phase;
    QGraphicsPixmapItem *head;
    QGraphicsPixmapItem *fog[13][32];
    QGraphicsTextItem *stat[4];
    unit *u[21],*slot[10];
    QGraphicsPixmapItem *result[2];
    QGraphicsPixmapItem *card_disp[3];
    QGraphicsTextItem *card_stat[4];
    QGraphicsTextItem *money;
};

#endif // BACKGROUND_H
