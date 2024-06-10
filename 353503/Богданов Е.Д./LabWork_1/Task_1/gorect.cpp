#include "gorect.h"

GoRect::GoRect()
{
    this->setSceneRect(-200, -200, 300, 300);
    this->addRect(-240, -200, 100, 200);


}

void GoRect::move(int step, int x, int y, bool shadow)
{

    this->clear();
    this->addRect(x+step*10, y, 100, 200);



}







