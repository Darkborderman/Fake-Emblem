#include "background.h"

background::background()
{
    //init unit
    {
        u[0]=new axe_infantry;
        u[1]=new sword_infantry;
        u[2]=new spear_infantry;
        u[3]=new axe_calvery;
        u[4]=new sword_calvery;
        u[5]=new spear_calvery;
        u[6]=new axe_armored;
        u[7]=new sword_armored;
        u[8]=new spear_armored;
        u[9]=new bow_infantry;
        u[10]=new longbow_infantry;
        u[11]=new spear_calvery_throwing;
        u[12]=new axe_calvery_throwing;
        u[13]=new red_magic_infantry;
        u[14]=new blue_magic_infantry;
        u[15]=new green_magic_infantry;
        u[16]=new sword_infantry_throwing;
        u[17]=new sword_infantry_lord;
        u[18]=new spear_calvery_lord;
        u[19]=new bow_calvery;
        u[20]=new grand_castle;
    }
}

/***background about battle screen***/

void background::setbattle(QGraphicsScene *s)
{
    //map
    {
        QGraphicsPixmapItem *map[2];
        for(int i=0;i<=1;i++)
        {
            map[i]=new QGraphicsPixmapItem;
            map[i]->setPos(-184,-154);
        }
        s->addItem(map[0]);
        map[0]->setPixmap(QPixmap(":/res/map/map1.png").scaled(1536,768));
        map[1]->setPixmap(QPixmap(":/res/map/map2.png").scaled(1536,768));
    }
    //right Panel
    {
        QGraphicsPixmapItem *panel[8];
        for(int i=0;i<=7;i++)
        {
            panel[i]=new QGraphicsPixmapItem;
            panel[i]->setPixmap(QPixmap(":/res/button.png").scaled(191, 155));
            s->addItem(panel[i]);
            if(i%2==0) panel[i]->setPos(1352,145+155*(i/2)-48-252);
            else panel[i]->setPos(1543,145+155*(i/2)-48-252);
        }
    }
    //down Panel
    {
        QGraphicsPixmapItem *panel[5];
        for(int i=0;i<=4;i++)
        {
            panel[i]=new QGraphicsPixmapItem;
            s->addItem(panel[i]);
        }
        panel[0]->setPixmap(QPixmap(":/res/button.png").scaled(1920, 82));
        panel[0]->setPos(-185,715-252);
        panel[1]->setPixmap(QPixmap(":/res/button.png").scaled(1920, 82));
        panel[1]->setPos(-185,715-252+1*82);
        panel[2]->setPixmap(QPixmap(":/res/button.png").scaled(1535-384, 177));
        panel[2]->setPos(-185+384,627);
        panel[3]->setPixmap(QPixmap(":/res/button.png").scaled(384, 177));
        panel[3]->setPos(1350,627);
        panel[4]->setPixmap(QPixmap(":/res/button.png").scaled(384, 177));
        panel[4]->setPos(-183,627);
    }
    //back buttom
    {
        QGraphicsTextItem *text=new QGraphicsTextItem;
        text->setFont(QFont("Arial",100,10));
        s->addItem(text);
        text->setPos(-160,627);
        text->setPlainText("back");
    }
    //right Panel Button
    {
        QGraphicsPixmapItem *icon[8];
        for(int i=0;i<=7;i++)
        {
            icon[i]=new QGraphicsPixmapItem;
            s->addItem(icon[i]);
        }

        icon[0]->setPixmap(QPixmap(":/res/icon/summon.png").scaled(128, 128));
        icon[0]->setPos(1380,169-300);
        icon[1]->setPixmap(QPixmap(":/res/icon/move.png").scaled(128, 128));
        icon[1]->setPos(1380,322-300);
        icon[2]->setPixmap(QPixmap(":/res/icon/attack.png").scaled(128,128));
        icon[2]->setPos(1380,475-300);
        icon[3]->setPixmap(QPixmap(":/res/icon/halt.png").scaled(128,128));
        icon[3]->setPos(1380,628-300);
        icon[4]->setPixmap(QPixmap(":/res/icon/change.png").scaled(128, 128));
        icon[4]->setPos(1380+192,169-300);
        icon[5]->setPixmap(QPixmap(":/res/icon/cast.png").scaled(128, 128));
        icon[5]->setPos(1380+192,322-300);
        icon[6]->setPixmap(QPixmap(":/res/icon/none.png").scaled(128, 128));
        icon[6]->setPos(1380+192,475-300);
        icon[7]->setPixmap(QPixmap(":/res/icon/none.png").scaled(128, 128));
        icon[7]->setPos(1380+192,628-300);
    }
    //summon unit display
    {
        QGraphicsPixmapItem *cards[20];
        QGraphicsPixmapItem *magic[20];
        for(int i=0;i<=19;i++)
        {
            cards[i]=new QGraphicsPixmapItem;
            cards[i]->setPos(-180+82*i,463);
            s->addItem(cards[i]);
            magic[i]=new QGraphicsPixmapItem;
            magic[i]->setPos(-180+82*i,463+82);
            s->addItem(magic[i]);
        }
        magic[0]->setPixmap(QPixmap(":/res/magic/bomb/bomb2.png").scaled(82,82));
        magic[1]->setPixmap(QPixmap(":/res/magic/heal/heal3.png").scaled(82,82));
        magic[2]->setPixmap(QPixmap(":/res/magic/lightning/lightning0.png").scaled(82,82));

        cards[0]->setPixmap(QPixmap(":/res/unit/axe infantry.png").scaled(82,82));
        cards[1]->setPixmap(QPixmap(":/res/unit/sword infantry.png").scaled(82,82));
        cards[2]->setPixmap(QPixmap(":/res/unit/spear infantry.png").scaled(82,82));
        cards[3]->setPixmap(QPixmap(":/res/unit/axe calvery.png").scaled(82,82));
        cards[4]->setPixmap(QPixmap(":/res/unit/sword calvery.png").scaled(82,82));
        cards[5]->setPixmap(QPixmap(":/res/unit/spear calvery.png").scaled(82,82));
        cards[6]->setPixmap(QPixmap(":/res/unit/axe armored.png").scaled(82,82));
        cards[7]->setPixmap(QPixmap(":/res/unit/sword armored.png").scaled(82,82));
        cards[8]->setPixmap(QPixmap(":/res/unit/spear armored.png").scaled(82,82));
        cards[9]->setPixmap(QPixmap(":/res/unit/bow infantry.png").scaled(82,82));
        cards[10]->setPixmap(QPixmap(":/res/unit/longbow infantry.png").scaled(82,82));
        cards[11]->setPixmap(QPixmap(":/res/unit/spear calvery throwing.png").scaled(82,82));
        cards[12]->setPixmap(QPixmap(":/res/unit/axe calvery throwing.png").scaled(82,82));
        cards[13]->setPixmap(QPixmap(":/res/unit/red magic infantry.png").scaled(82,82));
        cards[14]->setPixmap(QPixmap(":/res/unit/blue magic infantry.png").scaled(82,82));
        cards[15]->setPixmap(QPixmap(":/res/unit/green magic infantry.png").scaled(82,82));
        cards[16]->setPixmap(QPixmap(":/res/unit/sword infantry throwing.png").scaled(82,82));
        cards[17]->setPixmap(QPixmap(":/res/unit/sword infantry lord.png").scaled(82,82));
        cards[18]->setPixmap(QPixmap(":/res/unit/spear calvery lord.png").scaled(82,82));
        cards[19]->setPixmap(QPixmap(":/res/unit/bow calvery.png").scaled(82,82));
    }
    //Phase display(member data)
    {
        phase=new QGraphicsTextItem;
        phase->setPos(1625,468);
        phase->setFont(QFont("Arial",40,10));
        s->addItem(phase);
    }
    //fog display(member data)
    {
        for(int i=0;i<=12;i++)
        {
            for(int j=0;j<=31;j++)
            {
                fog[i][j]=new QGraphicsPixmapItem;
                fog[i][j]->setPixmap(QPixmap(":/res/fog.png").scaled(48,48));
                fog[i][j]->setPos(-182+j*48,-158+i*48);
                s->addItem(fog[i][j]);
            }
        }
    }
    //stat display(member data)
    {
        for(int i=0;i<=3;i++)
        {
            stat[i]=new QGraphicsTextItem;
            stat[i]->setFont(QFont("Arial",40,10));
            s->addItem(stat[i]);
            stat[i]->setPos(1450+90*(i/2),650+70*(i%2));
        }
        head=new QGraphicsPixmapItem;
        s->addItem(head);
        head->setPos(1360,640);
    }
}

void background::setbattlephase(int phase)
{
    this->phase->setPlainText("P"+QString::number(phase%2));
}

bool background::setbattleresult(QGraphicsScene *s,QLinkedList<unit *> &list)
{
    int p1_flag=0;
    int p2_flag=0;
    for(QLinkedList<unit *>::iterator i=list.begin();i!=list.end();i++)
    {
        if((*i)->group==1) p1_flag=1;
        if((*i)->group==0) p2_flag=1;
    }
    QGraphicsTextItem *win=new QGraphicsTextItem;
    win->setFont(QFont("Arial",100,10));
    s->addItem(win);
    win->setPos(500,650);
    if(p1_flag==0&&p2_flag==1){ win->setPlainText("You lose"); return true;}
    if(p2_flag==0&&p1_flag==1){ win->setPlainText("You win"); return true;}
    if(p2_flag==0&&p1_flag==0){ win->setPlainText("Draw"); return true;}
    return false;
}

void background::setbattlefog(QLinkedList<unit *> &list,int phase)
{
    for(int i=0;i<=12;i++)
        for(int j=0;j<=31;j++)
            fog[i][j]->show();
    for(QLinkedList<unit *>::iterator i=list.begin();i!=list.end();i++)
    {
        if(phase%2!=(*i)->group) (*i)->hide();
        if(phase%2==(*i)->group) (*i)->show();
    }
    for(QLinkedList<unit *>::iterator i=list.begin();i!=list.end();i++)
    {
        if(phase%2==1&&(*i)->group==1)
        {
            int x=(*i)->posx;
            int y=(*i)->posy;
            fog[y][x]->hide();
            fog[y][x-1]->hide();
            fog[y][x+1]->hide();
            fog[y-1][x]->hide();
            fog[y-1][x+1]->hide();
            fog[y-1][x-1]->hide();
            fog[y+1][x]->hide();
            fog[y+1][x+1]->hide();
            fog[y+1][x-1]->hide();

            for(QLinkedList<unit *>::iterator i=list.begin();i!=list.end();i++)
            {
                if(((*i)->posx==x-1||(*i)->posx==x+1||(*i)->posx==x)&&((*i)->posy==y-1||(*i)->posy==y+1||(*i)->posy==y))
                {
                    (*i)->show();
                }
            }
        }
        if(phase%2==0&&(*i)->group==0)
        {
            int x=(*i)->posx;
            int y=(*i)->posy;
            fog[y][x]->hide();
            fog[y][x-1]->hide();
            fog[y][x+1]->hide();
            fog[y-1][x]->hide();
            fog[y-1][x+1]->hide();
            fog[y-1][x-1]->hide();
            fog[y+1][x]->hide();
            fog[y+1][x+1]->hide();
            fog[y+1][x-1]->hide();

            for(QLinkedList<unit *>::iterator i=list.begin();i!=list.end();i++)
            {
                if(((*i)->posx==x-1||(*i)->posx==x+1||(*i)->posx==x)&&((*i)->posy==y-1||(*i)->posy==y+1||(*i)->posy==y))
                {
                    (*i)->show();
                }
            }
        }
    }
}

void background::setbattlestat(unit *u)
{
    head->setPixmap(u->pixmap().scaled(75,75));
    stat[0]->setPlainText("P"+QString::number(u->group));
    stat[1]->setPlainText("$: "+QString::number(u->money));
    stat[2]->setPlainText("HP: "+QString::number(u->hp));
    stat[3]->setPlainText("ATK: "+QString::number(u->atk));
}

/***background about start screen***/

void background::setstart(QGraphicsScene *s)
{
    //background
    {
        QGraphicsPixmapItem *b=new QGraphicsPixmapItem;
        b->setPixmap(QPixmap(":/res/screen/start screen.png").scaled(1920,1080));
        b->setPos(-182,-280);
        s->addItem(b);
    }
    //panel
    {
        QGraphicsPixmapItem *panel[4];
        for(int i=0;i<=3;i++)
        {
            panel[i]=new QGraphicsPixmapItem;
            panel[i]->setPixmap(QPixmap(":/res/button.png").scaled(950,155));
            s->addItem(panel[i]);
            panel[i]->setPos(300,100+160*i);
        }
    }
    //panel text
    {
        QGraphicsTextItem *menu[4];
        for(int i=0;i<=3;i++)
        {
            menu[i]=new QGraphicsTextItem;
            menu[i]->setFont(QFont("Arial",100,10));
            s->addItem(menu[i]);
            menu[i]->setPos(600,100+154*i);
        }
        menu[0]->setPlainText("battle");
        menu[1]->setPlainText("manage");
        menu[2]->setPlainText("rank");
        menu[3]->setPlainText("draw");
    }
}

/***background about manage screen***/

void background::setmanage(QGraphicsScene *s)
{
    //background
    {
        QGraphicsPixmapItem *b=new QGraphicsPixmapItem;
        b->setPixmap(QPixmap(":/res/screen/trade screen.png").scaled(1920,1080));
        b->setPos(-182,-280);
        s->addItem(b);
    }
    //panel
    {
        QGraphicsPixmapItem *panel[3];
        for(int i=0;i<=2;i++)
        {
            panel[i]=new QGraphicsPixmapItem;
            s->addItem(panel[i]);
        }
        panel[0]->setPixmap(QPixmap(":/res/button.png").scaled(300,100));
        panel[0]->setPos(-150,-140);
        panel[1]->setPixmap(QPixmap(":/res/button.png").scaled(100,300));
        panel[1]->setPos(-150,200);
        panel[2]->setPixmap(QPixmap(":/res/button.png").scaled(100,300));
        panel[2]->setPos(1600,200);
    }
    //panel text
    {
        QGraphicsTextItem *text[3];
        for(int i=0;i<=2;i++)
        {
            text[i]=new QGraphicsTextItem;
            text[i]->setFont(QFont("Arial",100,10));
            s->addItem(text[i]);
        }
        text[0]->setPlainText("<");
        text[0]->setPos(-150,270);
        text[1]->setPlainText(">");
        text[1]->setPos(1600,270);
        text[2]->setPlainText("back");
        text[2]->setPos(-150,-168);
    }
    //card background
    {
        QGraphicsPixmapItem *card[10];
        for(int i=0;i<=9;i++)
        {
            card[i]=new QGraphicsPixmapItem;
            card[i]->setPixmap(QPixmap(":/res/card/card.png").scaled(60*4,96*4));
            s->addItem(card[i]);
            card[i]->setPos(80+280*(i%5),-20+400*(i/5));
        }
    }
    //slots(member data)
    {
        for(int i=0;i<=9;i++)
        {
            slot[i]=new unit(0,0,0,0,0,0,'n',false,false,false);
            s->addItem(slot[i]);
            slot[i]->setPos(132+280*(i%5),12+400*(i/5));
        }
    }
    //detail card display(member data)
    {
        for(int i=0;i<=2;i++)
        {
            card_disp[i]=new QGraphicsPixmapItem;
            s->addItem(card_disp[i]);
            card_disp[i]->hide();
            card_disp[i]->setPos(500+108*i,0+70*i);
        }
        card_disp[0]->setPixmap(QPixmap(":/res/card/card.png").scaled(60*8,96*8));
        card_disp[2]->setPos(874,4);
        for(int i=0;i<=3;i++)
        {
            card_stat[i]=new QGraphicsTextItem;
            card_stat[i]->setFont(QFont("Arial",50,10));
            s->addItem(card_stat[i]);
            card_stat[i]->setPos(560,375+(72*i));
            card_stat[i]->hide();
        }
    }
}

void background::setpage(int page)
{
    for(int i=0;i<=9;i++)
    {
        slot[i]->setPixmap(u[i+(10*page)]->pixmap().scaled(132,132));
        slot[i]->hp=u[i+(10*page)]->hp;
    }
}

void background::showcard(int i, int num)
{
    card_disp[1]->setPixmap(u[i]->pixmap().scaled(260,260));
    if(u[i]->weapon=='n') card_disp[2]->setPixmap(QPixmap(":/res/card/none type.png").scaled(100,100));
    if(u[i]->weapon=='r') card_disp[2]->setPixmap(QPixmap(":/res/card/red type.png").scaled(100,100));
    if(u[i]->weapon=='b') card_disp[2]->setPixmap(QPixmap(":/res/card/blue type.png").scaled(100,100));
    if(u[i]->weapon=='g') card_disp[2]->setPixmap(QPixmap(":/res/card/green type.png").scaled(100,100));
    for(int i=0;i<=2;i++) card_disp[i]->show();
    card_stat[0]->setPlainText("has"+QString::number(num));
    card_stat[1]->setPlainText("HP:"+QString::number(u[i]->hp));
    card_stat[2]->setPlainText("ATK"+QString::number(u[i]->atk));
    card_stat[3]->setPlainText("Sell for $:"+QString::number(u[i]->money));
    for(int i=0;i<=3;i++) card_stat[i]->show();
}

void background::hidecard()
{
    for(int i=0;i<=2;i++) card_disp[i]->hide();
    for(int i=0;i<=3;i++) card_stat[i]->hide();
}

/***background about rank screen***/

void background::setrank(QGraphicsScene *s)
{
    //background
    {
        QGraphicsPixmapItem *b=new QGraphicsPixmapItem;
        b->setPixmap(QPixmap(":/res/screen/rank screen.png").scaled(1920,1080));
        b->setPos(-182,-280);
        s->addItem(b);
    }
    //panel
    {
        QGraphicsPixmapItem *panel=new QGraphicsPixmapItem;
        panel->setPixmap(QPixmap(":/res/button.png").scaled(300,100));
        s->addItem(panel);
        panel->setPos(-150,-140);
    }
    //panel text
    {
        QGraphicsTextItem *back= new QGraphicsTextItem;
        back->setFont(QFont("Arial",100,10));
        s->addItem(back);
        back->setPlainText("back");
        back->setPos(-150,-168);
    }
    //rank text
    {
        QGraphicsTextItem *rank[2];
        for(int i=0;i<=1;i++)
        {
            rank[i]=new QGraphicsTextItem;
            rank[i]->setFont(QFont("Arial",40,10));
            s->addItem(rank[i]);
            rank[i]->setPos(550+450*i,-100);
        }
        rank[0]->setPlainText("rank");
        rank[1]->setPlainText("phase");
    }
}

void background::setrank(QGraphicsScene *s,QStringList sl)
{
    for(int i=0;i<=(sl.size()-1)/2;i++)
    {
        QGraphicsTextItem *rank[2];
        for(int j=0;j<=1;j++)
        {
            rank[j]=new QGraphicsTextItem;
            rank[j]->setFont(QFont("Arial",25,10));
            s->addItem(rank[j]);
            rank[j]->setPos(550+450*j,-25+50*i);
        }
        rank[0]->setPlainText(sl.at(0+2*i));
        rank[1]->setPlainText(sl.at(1+2*i));
    }
}

/***background about the draw screen***/

void background::setdraw(QGraphicsScene *s)
{
    //background
    {
        QGraphicsPixmapItem *b=new QGraphicsPixmapItem;
        b->setPixmap(QPixmap(":/res/screen/draw screen.png").scaled(1920,1080));
        b->setPos(-182,-280);
        s->addItem(b);
    }
    QGraphicsPixmapItem *panel=new QGraphicsPixmapItem;
    panel->setPixmap(QPixmap(":/res/button.png").scaled(300,100));
    s->addItem(panel);
    panel->setPos(-150,-140);

    QGraphicsTextItem *back=new QGraphicsTextItem;
    back->setFont(QFont("Arial",100,10));
    s->addItem(back);
    back->setPlainText("back");
    back->setPos(-150,-168);

    QGraphicsPixmapItem *card=new QGraphicsPixmapItem;
    card->setPixmap(QPixmap(":/res/card/card.png").scaled(60*7,84*7));
    s->addItem(card);
    card->setPos(1000,-100);

    QGraphicsPixmapItem *but=new QGraphicsPixmapItem;
    but->setPixmap(QPixmap(":/res/button.png").scaled(420,100));
    s->addItem(but);
    but->setPos(1000,600);

    QGraphicsTextItem *click=new QGraphicsTextItem;
    click->setFont(QFont("Arial",80,10));
    s->addItem(click);
    click->setPlainText("$:25");
    click->setPos(1100,580);

    result[0]=new QGraphicsPixmapItem;
    result[0]->setPixmap(QPixmap(":/res/card/card.png").scaled(60*4,96*4));
    s->addItem(result[0]);
    result[0]->setPos(0,0);

    result[1]=new QGraphicsPixmapItem;
    s->addItem(result[1]);
    result[1]->setPos(60,34);

    QGraphicsPixmapItem *but2=new QGraphicsPixmapItem;
    but2->setPixmap(QPixmap(":/res/button.png").scaled(600,100));
    s->addItem(but2);
    but2->setPos(-150,-140+740);

    money=new QGraphicsTextItem;
    money->setFont(QFont("Arial",100,10));
    s->addItem(money);
    money->setPos(-150,-168+740);
}

void background::setdrawresult(int i)
{
    result[1]->setPixmap(u[i]->pixmap().scaled(120,120));
}

void background::setdrawmoney(int money)
{
    this->money->setPlainText("$:"+QString::number(money));
}
