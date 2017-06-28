#include "green_magic_infantry.h"

green_magic_infantry::green_magic_infantry():unit(20,35,1,2,5,5,'g',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/green magic infantry.png").scaled(48,48));
}

