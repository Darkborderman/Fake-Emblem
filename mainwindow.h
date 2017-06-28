#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QTimer>
#include<QKeyEvent>
#include<QPoint>
#include<iostream>
#include<QLinkedList>
#include<cstdlib>
#include<QtMultimedia/QMediaPlayer>
#include<string>
#include<unistd.h>
#include<QGraphicsTextItem>
#include<QFont>
#include<QtSql>
#include<QObject>
#include<fstream>
#include<QLineEdit>
#include<QTcpServer>
#include<QTcpSocket>
#include<string.h>
#include<cstdio>

#include"ui_mainwindow.h"
#include"background.h"
#include"audio.h"

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

#include"magic.h"
#include"bomb.h"
#include"heal.h"
#include"lightning.h"

#include"account.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   MainWindow(QWidget *parent = 0);
   virtual void mousePressEvent(QMouseEvent *e);
   virtual void keyPressEvent(QKeyEvent *e);
   void manage(QMouseEvent *e);
   void rank(QMouseEvent *e);
   void setdata(QMouseEvent *e);
   void start(QMouseEvent *e);
   void draw(QMouseEvent *e);
   void setphase();
   void getmoney();
   void setmoney();
   void getrank();
   void setrank();
   void senddata();
   void setdb();
   void battle();

   QString gettext(QWidget *w);

public slots:
   void moving();

private:
    Ui::MainWindow *ui;
    QTimer *t;
    QGraphicsScene *scene[5];
    unit *selected,*target,*origin;
    QLinkedList<unit *> list;
    QStringList list_rank;
    background *b;
    audio *a;
    int phase,tick,page,money;
    int distx,disty;
    bool end;
    account *s;
    int cardnum[20],sig[4];
    string in;
    int earn;
    QSqlDatabase db;
    QTcpSocket *socket,*skt;
    QTcpServer *server;
    int flag;

public:
    void tcpConnect();

public slots:
    void connected();
    void getdata();
    void serverIncome();
};

#endif // MAINWINDOW_H
