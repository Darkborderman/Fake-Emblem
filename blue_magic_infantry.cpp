#include "blue_magic_infantry.h"

blue_magic_infantry::blue_magic_infantry():unit(20,35,1,2,5,5,'b',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/blue magic infantry.png").scaled(48,48));
}
