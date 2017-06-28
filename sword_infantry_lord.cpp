#include "sword_infantry_lord.h"

sword_infantry_lord::sword_infantry_lord():unit(60,25,1,1,5,5,'r',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/sword infantry lord.png").scaled(48,48));
}
