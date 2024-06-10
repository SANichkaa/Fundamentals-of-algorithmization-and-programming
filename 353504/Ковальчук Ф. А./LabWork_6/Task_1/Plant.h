#ifndef PLANT_H
#define PLANT_H

#include <QString>

constexpr short MAX_ANOUNT_PLANT = 5;

struct Plant
{
    int daysOfGrowing;
    double height;
    char plantGender;//m f t
    bool isFlowering;
    static QString name[MAX_ANOUNT_PLANT];
    static int flowersNum[MAX_ANOUNT_PLANT];

    Plant();
    Plant(int daysOfGrow, double height, char gender, bool isFlowering);
    QString plantToString();
};

#endif // PLANT_H
