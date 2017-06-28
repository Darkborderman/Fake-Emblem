#include "bow_infantry.h"

bow_infantry::bow_infantry():unit(30,20,2,2,5,5,'n',true,false,true)
{
     setPixmap(QPixmap(":/res/unit/bow infantry.png").scaled(48,48));
}
