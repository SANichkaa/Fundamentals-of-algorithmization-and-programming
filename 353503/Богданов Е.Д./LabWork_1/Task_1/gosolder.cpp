#include "gosolder.h"

GoSolder::GoSolder()
{
    this->setSceneRect(-200, -200, 300, 300);
    this->addRect(-240, -200, 100, 200);
    this->addEllipse(-210, -250, 40, 50);
    this->addLine(-180, -150, -180, -50);
    this->addRect(-200, 0, 40, 200);
}

void GoSolder::turn(int step, int x, int y)
{

    this->clear();
    this->addRect(x+step*10, y, 150, 200);
    this->addEllipse(-190+step*10, -250, 50, 50);
    this->addRect(x+step*10+20, 0, 115, 200);
    this->addLine(x+step*10+80, 0, x+step*10+80, 200);
    this->addLine(x+step*10, y+20, x+step*10-20, -70);
    this->addLine(x+step*10+150, y+20, x+step*10+170, -70);

}

void GoSolder::move(int step, int x, int y, bool shadow)
{

    this->clear();
    this->addRect(x+step*10, y, 100, 200);
    this->addEllipse(-210+step*10, -250, 40, 50);

    if(shadow) {

        this->addLine(x+step*10, -150, x+step*10-60, -100);
        this->addLine(-180+step*10, -150, -130+step*10, -100);
        this->addRect(-160+step*10, 0, 160, 40);
        this->addRect(-200+step*10, 0, 40, 200);

    }

    else {

        this->addLine(x+step*10+100, -150, x+step*10+110, -100);
        this->addLine(-180+step*10, -150, -280+step*10, -100);
        this->addRect(-200+step*10, 0, 200, 40);
        this->addRect(-200+step*10, 40, 40, 160);


    }

}

void GoSolder::press_f(int step, int x, int y)
{
    this->clear();
    this->addRect(x+step*10, y, 150, 200);
    this->addEllipse(-190+step*10, -250, 50, 50);
    this->addRect(x+step*10+20, 0, 115, 200);
    this->addLine(x+step*10+80, 0, x+step*10+80, 200);
    this->addLine(x+step*10+150, y+20, x+step*10+170, -70);
    this->addLine(x+step*10, y+20, x+step*10-30, y+20);
    this->addLine(x+step*10-30, y+20, -190+step*10, -225);

}
