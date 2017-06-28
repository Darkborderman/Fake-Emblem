#include "spear_armored.h"

spear_armored::spear_armored():unit(40,25,1,1,3,5,'b',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/spear armored.png").scaled(48,48));
}
