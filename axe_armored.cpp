#include "axe_armored.h"

axe_armored::axe_armored():unit(40,25,1,1,3,5,'g',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/axe armored.png").scaled(48,48));
}
