#include "spear_infantry.h"

spear_infantry::spear_infantry():unit(30,20,1,1,5,5,'b',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/spear infantry.png").scaled(48,48));
}
