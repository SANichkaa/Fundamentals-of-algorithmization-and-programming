#ifndef PLANT_H
#define PLANT_H

#include <QChar>

struct Plant
{
    int daysOfGrowing;
    double height;
    bool isFlowering;
    QChar name[16];
};

#endif // PLANT_H
