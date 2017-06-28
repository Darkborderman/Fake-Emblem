#include "account.h"

account::account(QWidget *parent): QDialog(parent)
{
    setWindowTitle(QStringLiteral("Account"));
    nameLabel1 = new QLabel;
    nameLabel1->setText(tr("Name："));
    nameLabel2 = new QLabel;
    nameBtn = new QPushButton;
    nameBtn->setText(tr("Input"));

    passLabel1 = new QLabel;
    passLabel1->setText(tr("password："));
    passLabel2 = new QLabel;
    passBtn = new QPushButton;
    passBtn->setText(tr("Input"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(nameLabel1,0,0);
    mainLayout->addWidget(nameLabel2,0,1);
    mainLayout->addWidget(nameBtn,0,2);
    mainLayout->addWidget(passLabel1,2,0);
    mainLayout->addWidget(passLabel2,2,1);
    mainLayout->addWidget(passBtn,2,2);
    text="unnamed";
    pass="none";
    connect(nameBtn,SIGNAL(clicked()),this,SLOT(InputName()));
    connect(passBtn,SIGNAL(clicked()),this,SLOT(InputPass()));
}

void account::InputName()
{
    bool ok;
    text = QInputDialog::getText(this,tr("Input name"),tr("Name："),QLineEdit::Normal,nameLabel2->text(),&ok);
    if (ok && !text.isEmpty()) nameLabel2->setText(text);
}

void account::InputPass()
{
    bool ok;
    pass=QInputDialog::getText(this,tr("Input password"),tr("pass："),QLineEdit::Normal,passLabel2->text(),&ok);
    if (ok && !pass.isEmpty()) passLabel2->setText(pass);
}
