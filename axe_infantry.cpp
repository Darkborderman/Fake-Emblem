#include "axe_infantry.h"

axe_infantry::axe_infantry():unit(30,20,1,1,5,5,'g',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/axe infantry.png").scaled(48,48));
}
