#include "sword_infantry.h"

sword_infantry::sword_infantry():unit(30,20,1,1,5,5,'r',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/sword infantry.png").scaled(48,48));
}
