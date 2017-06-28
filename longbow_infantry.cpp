#include "longbow_infantry.h"

longbow_infantry::longbow_infantry():unit(20,20,3,5,5,5,'n',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/longbow infantry.png").scaled(48,48));
}
