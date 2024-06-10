#ifndef GOSOLDER_H
#define GOSOLDER_H

#include "gorect.h"

class GoSolder : public GoRect
{
public:

    GoSolder();
    void turn(int step, int x, int y);
    void move(int step, int x, int y, bool shadow) override;
    void press_f(int step, int x, int y);

};

#endif // GOSOLDER_H
