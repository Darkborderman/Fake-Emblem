#include "grand_castle.h"

grand_castle::grand_castle():unit(60,15,1,5,0,5,'n',false,true,true)
{
     setPixmap(QPixmap(":/res/unit/castle.png").scaled(48,48));

}
