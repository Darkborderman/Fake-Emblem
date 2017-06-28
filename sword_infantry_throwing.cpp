#include "sword_infantry_throwing.h"

sword_infantry_throwing::sword_infantry_throwing():unit(30,20,1,2,5,5,'r',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/sword infantry throwing.png").scaled(48,48));
}
