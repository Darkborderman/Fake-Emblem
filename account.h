#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include<QInputDialog>

class account: public QDialog
{
    Q_OBJECT

public:
    account(QWidget* parent=0);
    QString text;
    QString pass;
public slots:
    void InputName();
    void InputPass();
private:
    QWidget *w;
    QLabel *nameLabel1;
    QLabel *nameLabel2;
    QLabel *passLabel1;
    QLabel *passLabel2;
    QPushButton *nameBtn;
    QPushButton *passBtn;
    QGridLayout *mainLayout;
};


#endif // ACCOUNT_H
