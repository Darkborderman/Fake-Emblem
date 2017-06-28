#include "heal.h"


heal::heal(QGraphicsScene *s,int x,int y):magic(10,6)
{
    for(int i=0;i<=4;i++)
    {
        for(int j=0;j<=tick-1;j++)
        {
        pict[i][j]->setPixmap(QPixmap(":/res/magic/heal/heal"+QString::number(j)+".png").scaled(48,48));
        s->addItem(pict[i][j]);
        pict[i][j]->hide();
        }
    }
    for(int i=0;i<=tick-1;i++)
    {
        pict[0][i]->setPos(x,y);
        pict[1][i]->setPos(x+48,y);
        pict[2][i]->setPos(x-48,y);
        pict[3][i]->setPos(x,y+48);
        pict[4][i]->setPos(x,y-48);
    }
    posx=(x+184)/48;
    posy=(y+154)/48;
}
void heal::splash()
{
    tick--;
    if(tick==5)
    {
        for(int i=0;i<=4;i++) pict[i][0]->show();
    }
    if(tick==4)
    {
        for(int i=0;i<=4;i++)pict[i][1]->show();
        for(int i=0;i<=4;i++)pict[i][0]->hide();
    }
    if(tick==3)
    {
        for(int i=0;i<=4;i++)pict[i][2]->show();
        for(int i=0;i<=4;i++)pict[i][1]->hide();
    }
    if(tick==2)
    {
        for(int i=0;i<=4;i++)pict[i][3]->show();
        for(int i=0;i<=4;i++)pict[i][2]->hide();
    }
    if(tick==1)
    {
        for(int i=0;i<=4;i++)pict[i][4]->show();
        for(int i=0;i<=4;i++)pict[i][3]->hide();
    }
    if(tick==0)
    {
        for(int i=0;i<=4;i++)pict[i][5]->show();
        for(int i=0;i<=4;i++)pict[i][4]->hide();
    }
    if(tick==-1)
    {
        for(int i=0;i<=4;i++)pict[i][5]->hide();
    disconnect(this);
    delete this;
    }
}
void heal::blast(QLinkedList<unit *> &list)
{
    for(QLinkedList<unit *>::iterator i=list.begin();i!=list.end();i++)
    {
        if((posx==(*i)->posx)&&(posy==(*i)->posy))
        {
            (*i)->hp=(*i)->hp+10;
        }
        if((posx-1==(*i)->posx)&&(posy==(*i)->posy))
        {
            (*i)->hp=(*i)->hp+10;
        }
        if((posx+1==(*i)->posx)&&(posy==(*i)->posy))
        {
            (*i)->hp=(*i)->hp+10;
        }
        if((posx==(*i)->posx)&&(posy-1==(*i)->posy))
        {
            (*i)->hp=(*i)->hp+10;
        }
        if((posx==(*i)->posx)&&(posy+1==(*i)->posy))
        {
            (*i)->hp=(*i)->hp+10;
        }
    }
}
