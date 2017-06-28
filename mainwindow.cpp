#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
    t=new QTimer;
    ui->setupUi(this);
    for(int i=0;i<=4;i++) scene[i]=new QGraphicsScene(0,0,1550,768);
    ui->graphicsView->setScene(scene[1]);

    a=new audio;
    b=new background;
    b->setbattle(scene[0]);
    b->setstart(scene[1]);
    b->setmanage(scene[2]);
    b->setrank(scene[3]);
    b->setdraw(scene[4]);

    s=new account;
    s->show();

    for(int i=0;i<=19;i++) cardnum[i]=0;
    end=false;
    phase=1;
    page=0;
    flag=0;
    earn=0;
    selected=new unit(0,0,0,0,0,0,'n',false,false,false);
    origin=new unit(0,0,0,0,0,0,'n',false,false,false);

    for(int i=0;i<=1;i++)
    {
        unit *player=new grand_castle;
        player->init(i,list,scene[0],-184+(-i+11)*48,98+(-i+7)*48);
    }
    getmoney();
    getrank();
    b->setpage(page);
    b->setbattlefog(list,phase);
    b->setbattlephase(phase);
    t->start(15);
    setdb();

    server=new QTcpServer;
    socket=new QTcpSocket;
    server->listen(QHostAddress::Any, 8763);
    socket->connectToHost("127.0.0.1", 8763);
    connect(server,&QTcpServer::newConnection,this,&MainWindow::serverIncome);
    tcpConnect();
    in="0:0:0:0";
}

/***Control between screens***/

void MainWindow::mousePressEvent(QMouseEvent *e)
{
     if(ui->graphicsView->scene()==scene[0]) setdata(e);
     if(ui->graphicsView->scene()==scene[1]) start(e);
     if(ui->graphicsView->scene()==scene[2]) manage(e);
     if(ui->graphicsView->scene()==scene[3]) rank(e);
     if(ui->graphicsView->scene()==scene[4]) draw(e);
}

/***Control battle screen***/

void MainWindow::battle()
{
    if(sig[0]==0) //left button
    {
        if(sig[1]==0) //select unit
        {
            for(QLinkedList<unit *>::iterator i=list.begin();i!=list.end();i++)
            {
                if((sig[2]==(*i)->posx)&&(sig[3]==(*i)->posy))
                {
                    selected=(*i);
                    b->setbattlestat(selected);
                }
            }
        }
        if(sig[1]==1) //select panel
        {
            if(selected->group==(phase%2)&&selected->active==true)
            {
                selected->active=false;
                if(sig[2]==1&&selected->cansummon==true) selected->summon=true;
                if(sig[2]==2&&selected->canmove==true)   selected->move=true;
                if(sig[2]==3&&selected->canattack==true) selected->attack=true;
                if(sig[2]==4) selected->active=false;
            }
            if(sig[2]==5)
            {
                phase++;
                setphase();
                b->setbattlefog(list,phase);
            }
            if(sig[2]==6&&selected->cansummon==true) selected->summon=true;
            if(sig[2]==7);
            if(sig[2]==8);
        }
    }
    if(sig[0]==1) //right button
    {
        if(selected->move==true)
        {
            selected->move=false;
            tick=48;
            distx=(selected->posx-sig[2]);
            disty=(selected->posy-sig[3]);
            if(abs(distx)+abs(disty)<=selected->walk) connect(t,SIGNAL(timeout()),this,SLOT(moving()));
            a->move();
            selected->getPos();
        }
        if(selected->summon==true)
        {
            selected->summon=false;
            if(sig[1]==1)
            {
                unit *summoned=new unit(0,0,0,0,0,0,'n',false,false,false);
                if(sig[2]==0) summoned=new axe_infantry;
                if(sig[2]==1) summoned=new sword_infantry;
                if(sig[2]==2) summoned=new spear_infantry;
                if(sig[2]==3) summoned=new axe_calvery;
                if(sig[2]==4) summoned=new sword_calvery;
                if(sig[2]==5) summoned=new spear_calvery;
                if(sig[2]==6) summoned=new axe_armored;
                if(sig[2]==7) summoned=new sword_armored;
                if(sig[2]==8) summoned=new spear_armored;
                if(sig[2]==9) summoned=new bow_infantry;
                if(sig[2]==10)summoned=new longbow_infantry;
                if(sig[2]==11)summoned=new spear_calvery_throwing;
                if(sig[2]==12)summoned=new axe_calvery_throwing;
                if(sig[2]==13)summoned=new red_magic_infantry;
                if(sig[2]==14)summoned=new blue_magic_infantry;
                if(sig[2]==15)summoned=new green_magic_infantry;
                if(sig[2]==16)summoned=new sword_infantry_throwing;
                if(sig[2]==17)summoned=new sword_infantry_lord;
                if(sig[2]==18)summoned=new spear_calvery_lord;
                if(sig[2]==19)summoned=new bow_calvery;
                summoned->init(selected->group,list,scene[0],selected->x()+48,selected->y()+256);
                b->setbattlefog(list,phase);
            }
            if(sig[1]==3)
            {
                magic *summoned;
                if(sig[2]==0) summoned=new bomb(scene[0],selected->x(),selected->y());
                if(sig[2]==1) summoned=new heal(scene[0],selected->x(),selected->y());
                if(sig[2]==2) summoned=new lightning(scene[0],selected->x(),selected->y());
                connect(t,SIGNAL(timeout()),summoned,SLOT(splash()));
                summoned->blast(list);
                b->setbattlestat(selected);

                for(QLinkedList<unit *>::iterator it=list.begin();it!=list.end();)
                {
                    if((*it)->hp<=0)
                    {
                        earn=earn+(*it)->money;
                        delete (*it);
                        it=list.erase(it);
                    }
                    else it++;
                }
                b->setbattlefog(list,phase);
            }
        }
        if(selected->attack==true)
        {
            selected->attack=false;
            for(QLinkedList<unit *>::iterator i=list.begin();i!=list.end();i++)
            {
                if((sig[2]==(*i)->posx)&&(sig[3]==(*i)->posy))
                {
                    target=(*i);
                }
            }
            int distx=(selected->posx-sig[2]);
            int disty=(selected->posy-sig[3]);
            if(abs(distx)+abs(disty)>=selected->minrange&&abs(distx)+abs(disty)<=selected->maxrange&&selected->group!=target->group)
            {
                selected->attacking(selected,target);
            }
            b->setbattlestat(selected);
            for(QLinkedList<unit *>::iterator it=list.begin();it!=list.end();)
            {
                if((*it)->hp<=0)
                {
                    earn=earn+(*it)->money;
                    delete (*it);
                    it=list.erase(it);
                }
                else it++;
            }
            b->setbattlefog(list,phase);
        }
    }
}

void MainWindow::moving()
{
    if(tick>0)
    {
        tick--;
        selected->setPos(selected->x()-distx,selected->y()-disty);
    }
    else
    {
        selected->getPos();
        disconnect(t,SIGNAL(timeout()),this,SLOT(moving()));
        b->setbattlefog(list,phase);
    }
}

void MainWindow::setphase()
{
    for(QLinkedList<unit *>::iterator i=list.begin();i!=list.end();i++)
    {
        if((*i)->group==phase%2) (*i)->active=true;
    }
    b->setbattlephase(phase);
   if(b->setbattleresult(scene[0],list)==true&&end==false)
   {
       setmoney();
       setrank();
       getmoney();
       end=true;
   }
}

/***Control start screen***/

void MainWindow::start(QMouseEvent *e)
{
    QPoint p=QCursor::pos();
    if((p.x()>=489&&p.x()<=1433)&&(p.y()>=299&&p.y()<=447)) ui->graphicsView->setScene(scene[0]);
    if((p.x()>=489&&p.x()<=1433)&&(p.y()>=459&&p.y()<=613)) ui->graphicsView->setScene(scene[2]);
    if((p.x()>=489&&p.x()<=1433)&&(p.y()>=622&&p.y()<=768)) ui->graphicsView->setScene(scene[3]);
    if((p.x()>=489&&p.x()<=1433)&&(p.y()>=777&&p.y()<=923)) ui->graphicsView->setScene(scene[4]);
}

/***Control manage screen***/

void MainWindow::manage(QMouseEvent *e)
{
    QPoint p=QCursor::pos();
    if(e->button()==Qt::LeftButton) //select cards
    {
        if((p.x()>=37&&p.x()<=334)&&(p.y()>=60&&p.y()<=157)) ui->graphicsView->setScene(scene[1]);
        if((p.x()>=37&&p.x()<=137)&&(p.y()>=400&&p.y()<=694)&&page>0) page--;
        if((p.x()>=1783&&p.x()<=1883)&&(p.y()>=400&&p.y()<=694)&&page<1) page++;
        b->setpage(page);
        if((p.x()>=267&&p.x()<=502)&&(p.y()>=181&&p.y()<=558))   b->showcard(0+10*page,cardnum[0+10*page]);
        else if((p.x()>=548&&p.x()<=780)&&(p.y()>=181&&p.y()<=558))   b->showcard(1+10*page,cardnum[1+10*page]);
        else if((p.x()>=828&&p.x()<=1064)&&(p.y()>=181&&p.y()<=558))  b->showcard(2+10*page,cardnum[2+10*page]);
        else if((p.x()>=1116&&p.x()<=1341)&&(p.y()>=181&&p.y()<=558)) b->showcard(3+10*page,cardnum[3+10*page]);
        else if((p.x()>=1390&&p.x()<=1622)&&(p.y()>=181&&p.y()<=558)) b->showcard(4+10*page,cardnum[4+10*page]);
        else if((p.x()>=267&&p.x()<=502)&&(p.y()>=584&&p.y()<=962))   b->showcard(5+10*page,cardnum[5+10*page]);
        else if((p.x()>=548&&p.x()<=780)&&(p.y()>=584&&p.y()<=962))   b->showcard(6+10*page,cardnum[6+10*page]);
        else if((p.x()>=828&&p.x()<=1064)&&(p.y()>=584&&p.y()<=962))  b->showcard(7+10*page,cardnum[7+10*page]);
        else if((p.x()>=1116&&p.x()<=1341)&&(p.y()>=584&&p.y()<=962)) b->showcard(8+10*page,cardnum[8+10*page]);
        else if((p.x()>=1390&&p.x()<=1622)&&(p.y()>=584&&p.y()<=962)) b->showcard(9+10*page,cardnum[9+10*page]);
    }
    if(e->button()==Qt::RightButton) //hide or buy cards
    {
        if((p.x()>=267&&p.x()<=502)&&(p.y()>=181&&p.y()<=558))
        {
            b->showcard(0+10*page,++cardnum[0+10*page]);
            money=money-50;
            setmoney();
        }
        else if((p.x()>=548&&p.x()<=780)&&(p.y()>=181&&p.y()<=558))
        {
            b->showcard(1+10*page,++cardnum[1+10*page]);
            money=money-50;
            setmoney();
        }
        else if((p.x()>=828&&p.x()<=1064)&&(p.y()>=181&&p.y()<=558))
        {
            b->showcard(2+10*page,++cardnum[2+10*page]);
            money=money-50;
            setmoney();
        }
        else if((p.x()>=1116&&p.x()<=1341)&&(p.y()>=181&&p.y()<=558))
        {
            b->showcard(3+10*page,++cardnum[3+10*page]);
            money=money-50;
            setmoney();
        }
        else if((p.x()>=1390&&p.x()<=1622)&&(p.y()>=181&&p.y()<=558))
        {
            b->showcard(4+10*page,++cardnum[4+10*page]);
            money=money-50;
            setmoney();
        }
        else if((p.x()>=267&&p.x()<=502)&&(p.y()>=584&&p.y()<=962))
        {
            b->showcard(5+10*page,++cardnum[5+10*page]);
            money=money-50;
            setmoney();
        }
        else if((p.x()>=548&&p.x()<=780)&&(p.y()>=584&&p.y()<=962))
        {
            b->showcard(6+10*page,++cardnum[6+10*page]);
            money=money-50;
            setmoney();
        }
        else if((p.x()>=828&&p.x()<=1064)&&(p.y()>=584&&p.y()<=962))
        {
            b->showcard(7+10*page,++cardnum[7+10*page]);
            money=money-50;
            setmoney();
        }
        else if((p.x()>=1116&&p.x()<=1341)&&(p.y()>=584&&p.y()<=962))
        {
            b->showcard(8+10*page,++cardnum[8+10*page]);
            money=money-50;
            setmoney();
        }
        else if((p.x()>=1390&&p.x()<=1622)&&(p.y()>=584&&p.y()<=962))
        {
            b->showcard(9+10*page,++cardnum[9+10*page]);
            money=money-50;
            setmoney();
        }
        else b->hidecard();
    }
    if(e->button()==Qt::MidButton) //sell cards
    {
        if((p.x()>=267&&p.x()<=502)&&(p.y()>=181&&p.y()<=558)&&cardnum[0+10*page])
        {
            b->showcard(0+10*page,--cardnum[0+10*page]);
            money=money+5;
            setmoney();
        }
        else if((p.x()>=548&&p.x()<=780)&&(p.y()>=181&&p.y()<=558)&&cardnum[1+10*page])
        {
            b->showcard(1+10*page,--cardnum[1+10*page]);
            money=money+5;
            setmoney();
        }
        else if((p.x()>=828&&p.x()<=1064)&&(p.y()>=181&&p.y()<=558)&&cardnum[2+10*page])
        {
            b->showcard(2+10*page,--cardnum[2+10*page]);
            money=money+5;
            setmoney();
        }
        else if((p.x()>=1116&&p.x()<=1341)&&(p.y()>=181&&p.y()<=558)&&cardnum[3+10*page])
        {
            b->showcard(3+10*page,--cardnum[3+10*page]);
            money=money+5;
            setmoney();
        }
        else if((p.x()>=1390&&p.x()<=1622)&&(p.y()>=181&&p.y()<=558)&&cardnum[4+10*page])
        {
            b->showcard(4+10*page,--cardnum[4+10*page]);
            money=money+5;
            setmoney();
        }
        else if((p.x()>=267&&p.x()<=502)&&(p.y()>=584&&p.y()<=962)&&cardnum[5+10*page])
        {
            b->showcard(5+10*page,--cardnum[5+10*page]);
            money=money+5;
            setmoney();
        }
        else if((p.x()>=548&&p.x()<=780)&&(p.y()>=584&&p.y()<=962)&&cardnum[6+10*page])
        {
            b->showcard(6+10*page,--cardnum[6+10*page]);
            money=money+5;
            setmoney();
        }
        else if((p.x()>=828&&p.x()<=1064)&&(p.y()>=584&&p.y()<=962)&&cardnum[7+10*page])
        {
            b->showcard(7+10*page,--cardnum[7+10*page]);
            money=money+5;
            setmoney();
        }
        else if((p.x()>=1116&&p.x()<=1341)&&(p.y()>=584&&p.y()<=962)&&cardnum[8+10*page])
        {
            b->showcard(8+10*page,--cardnum[8+10*page]);
            money=money+5;
            setmoney();
        }
        else if((p.x()>=1390&&p.x()<=1622)&&(p.y()>=584&&p.y()<=962)&&cardnum[9+10*page])
        {
            b->showcard(9+10*page,--cardnum[9+10*page]);
            money=money+5;
            setmoney();
        }
    }
}

/***Control rank screen***/

void MainWindow::rank(QMouseEvent *e)
{
    QPoint p=QCursor::pos();
    if((p.x()>=37&&p.x()<=334)&&(p.y()>=60&&p.y()<=157)) ui->graphicsView->setScene(scene[1]);
}

/***Control draw screen***/

void MainWindow::draw(QMouseEvent *e)
{
    getmoney();
    b->setdrawmoney(money);
    QPoint p=QCursor::pos();
    if((p.x()>=37&&p.x()<=334)&&(p.y()>=60&&p.y()<=157)) ui->graphicsView->setScene(scene[1]);
    if((p.x()>=1191&&p.x()<=1592)&&(p.y()>=800&&p.y()<=900)&&money>=25)
    {
        getmoney();
        int x=rand()%20;
        b->setdrawresult(x);
        cardnum[x]++;
        money=money-25;
        setmoney();
        b->setdrawmoney(money);
    }
}

/***Set/Get member data***/

void MainWindow::getmoney()
{
    if(db.open())
    {
        QSqlQuery query("SELECT * FROM Account WHERE name='"+s->text+"' AND pass='"+s->pass+"'");
        while(query.next())
        {
            money=query.value(2).toInt();
        }
    }
}

void MainWindow::setmoney()
{
    if(db.open())
    {
        QSqlQuery q;
        q.exec("UPDATE Account SET money="+QString::number(money+earn)+" WHERE name='"+s->text+"' AND pass='"+s->pass+"'");
    }
    earn=0;
}

void MainWindow::getrank()
{

}

void MainWindow::setrank()
{
    QSqlQuery q;
    QString a=QString::number(phase);
    if(db.open())
    {
        q.exec("INSERT INTO Rank (name, phase) VALUES ('"+s->text+"','"+a+"')");
        QSqlQuery query("SELECT * FROM Rank ORDER BY phase");
        while(query.next())
        {
            list_rank.append(query.value(0).toString().trimmed());
            list_rank.append(query.value(1).toString().trimmed());
        }
    }
    b->setrank(scene[3],list_rank);
}

void MainWindow::setdb()
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/divik/Desktop/2017-pd2-project-3-fire-emblem/data/data.db");
}

//!Mainly for debug

void MainWindow::keyPressEvent(QKeyEvent *e)
{
}

/***TCP socket connect***/

void MainWindow::tcpConnect()
{
    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(readyRead()),this, SLOT(getdata()));
}

void MainWindow::connected()
{
    qDebug() << "connected";
}

void MainWindow::serverIncome()
{
    skt=server->nextPendingConnection();
    senddata();
}

/***send/get battle data***/

void MainWindow::setdata(QMouseEvent *e)
{
    QPoint p=QCursor::pos();
    int posx=p.x()/48;
    int posy=(p.y()-43)/48;
    if((p.x()>=8&&p.x()<=384)&&(p.y()>=827&&p.y()<=996)) ui->graphicsView->setScene(scene[1]);
    if(e->button()==Qt::LeftButton)
    {
        if((p.x()>=1&&p.x()<=1916)&&(p.y()>=47&&p.y()<=659))
        {
            in="0:";

            if((p.x()>=3&&p.x()<=1536)&&(p.y()>=47&&p.y()<=659))
            {
                in=in+"0:"+to_string(posx)+":"+to_string(posy);
            }
            if((p.x()>=1540&&p.x()<=1920)&&(p.y()>=46&&p.y()<=660))
            {
                   if((p.x()>=1540&&p.x()<=1730)&&(p.y()>=46&&p.y()<=198)) in=in+"1:1:0";
                   if((p.x()>=1540&&p.x()<=1730)&&(p.y()>=199&&p.y()<=350))
                   {in=in+"1:2:0"; flag=0;}
                   if((p.x()>=1540&&p.x()<=1730)&&(p.y()>=351&&p.y()<=510))
                   {in=in+"1:3:0"; flag=1;}
                   if((p.x()>=1540&&p.x()<=1730)&&(p.y()>=511&&p.y()<=660)) in=in+"1:4:0";
                   if((p.x()>=1730&&p.x()<=1920)&&(p.y()>=46&&p.y()<=198)) in=in+"1:5:0";
                   if((p.x()>=1730&&p.x()<=1920)&&(p.y()>=199&&p.y()<=350)) in=in+"1:6:0";
                   if((p.x()>=1730&&p.x()<=1920)&&(p.y()>=351&&p.y()<=510)) in=in+"1:7:0";
                   if((p.x()>=1730&&p.x()<=1920)&&(p.y()>=511&&p.y()<=600)) in=in+"1:8:0";
            }
            senddata();
        }
    }
    if(e->button()==Qt::RightButton)
    {
        if(((p.x()>=1&&p.x()<=1536)&&(p.y()>=47&&p.y()<=659))||((p.x()>=1&&p.x()<=1647)&&(p.y()>=663&&p.y()<=822)))
        {
            in="1:";
            if((p.x()>=1&&p.x()<=1536)&&(p.y()>=47&&p.y()<=659)&&flag==0)
            {
                in=in+"0:"+to_string(posx)+":"+to_string(posy);
            }
            if((p.x()>=1&&p.x()<=1647)&&(p.y()>=663&&p.y()<=741))
            {
                in=in+"1:";
                    if((p.x()>=7&&p.x()<=78))     in=in+"0:0";
                    if((p.x()>=79&&p.x()<=162))   in=in+"1:0";
                    if((p.x()>=163&&p.x()<=252))  in=in+"2:0";
                    if((p.x()>=253&&p.x()<=335))  in=in+"3:0";
                    if((p.x()>=336&&p.x()<=414))  in=in+"4:0";
                    if((p.x()>=415&&p.x()<=496))  in=in+"5:0";
                    if((p.x()>=497&&p.x()<=564))  in=in+"6:0";
                    if((p.x()>=565&&p.x()<=652))  in=in+"7:0";
                    if((p.x()>=653&&p.x()<=746))  in=in+"8:0";
                    if((p.x()>=747&&p.x()<=816))  in=in+"9:0";
                    if((p.x()>=817&&p.x()<=900))  in=in+"10:0";
                    if((p.x()>=901&&p.x()<=987))  in=in+"11:0";
                    if((p.x()>=988&&p.x()<=1069)) in=in+"12:0";
                    if((p.x()>=1070&&p.x()<=1151))in=in+"13:0";
                    if((p.x()>=1152&&p.x()<=1234))in=in+"14:0";
                    if((p.x()>=1235&&p.x()<=1317))in=in+"15:0";
                    if((p.x()>=1318&&p.x()<=1400))in=in+"16:0";
                    if((p.x()>=1401&&p.x()<=1482))in=in+"17:0";
                    if((p.x()>=1483&&p.x()<=1565))in=in+"18:0";
                    if((p.x()>=1565&&p.x()<=1647))in=in+"19:0";
            }
            if((p.x()>=3&&p.x()<=1536)&&(p.y()>=47&&p.y()<=659)&&flag==1)
            {
                in=in+"2:"+to_string(posx)+":"+to_string(posy);
            }
            if((p.x()>=1&&p.x()<=1647)&&(p.y()>=742&&p.y()<=822))
            {
                 in=in+"3:";
                 if((p.x()>=7&&p.x()<=78))     in=in+"0:0";
                 if((p.x()>=79&&p.x()<=162))   in=in+"1:0";
                 if((p.x()>=163&&p.x()<=252))  in=in+"2:0";
                 if((p.x()>=253&&p.x()<=335))  in=in+"3:0";
                 if((p.x()>=336&&p.x()<=414))  in=in+"4:0";
                 if((p.x()>=415&&p.x()<=496))  in=in+"5:0";
                 if((p.x()>=497&&p.x()<=564))  in=in+"6:0";
                 if((p.x()>=565&&p.x()<=652))  in=in+"7:0";
                 if((p.x()>=653&&p.x()<=746))  in=in+"8:0";
                 if((p.x()>=747&&p.x()<=816))  in=in+"9:0";
                 if((p.x()>=817&&p.x()<=900))  in=in+"10:0";
                 if((p.x()>=901&&p.x()<=987))  in=in+"11:0";
                 if((p.x()>=988&&p.x()<=1069)) in=in+"12:0";
                 if((p.x()>=1070&&p.x()<=1151))in=in+"13:0";
                 if((p.x()>=1152&&p.x()<=1234))in=in+"14:0";
                 if((p.x()>=1235&&p.x()<=1317))in=in+"15:0";
                 if((p.x()>=1318&&p.x()<=1400))in=in+"16:0";
                 if((p.x()>=1401&&p.x()<=1482))in=in+"17:0";
                 if((p.x()>=1483&&p.x()<=1565))in=in+"18:0";
                 if((p.x()>=1565&&p.x()<=1647))in=in+"19:0";
            }
        }
        senddata();
    }
}

void MainWindow::getdata()
{
    QByteArray ba=socket->readAll();
    int size=ba.size();
    char *t=new char(size);
    memcpy(t,ba.data(),size);
    char *delim = ":";
    char *pch;
    pch = strtok(t,delim);
    sig[0]=atoi(pch);
    pch = strtok (NULL, delim);
    sig[1]=atoi(pch);
    pch = strtok (NULL, delim);
    sig[2]=atoi(pch);
    pch = strtok (NULL, delim);
    sig[3]=atoi(pch);
    cerr<<sig[0]<<":"<<sig[1]<<":"<<sig[2]<<":"<<sig[3];
    battle();
}

void MainWindow::senddata()
{
    char te[20];
    strcpy(te,in.c_str());
    skt->write(te, strlen(te));
    socket->waitForBytesWritten(1000);
    socket->flush();
}
