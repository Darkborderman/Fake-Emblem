#include "sword_armored.h"

sword_armored::sword_armored():unit(40,25,1,1,3,5,'r',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/sword armored.png").scaled(48,48));
}
