#include "red_magic_infantry.h"

red_magic_infantry::red_magic_infantry():unit(20,35,1,2,5,5,'r',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/red magic infantry.png").scaled(48,48));
}
