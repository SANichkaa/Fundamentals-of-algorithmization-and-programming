#include "Plant.h"

QString Plant::name[MAX_ANOUNT_PLANT]{"Роза", "Георгина", "Сирень", "Фикус", "Нарцис"};
int Plant::flowersNum[MAX_ANOUNT_PLANT]{0,0,100,0,0};

Plant::Plant()
    : daysOfGrowing(10)
    , height(0.0f)
    , plantGender('T')
    , isFlowering(false)
{
}

Plant::Plant(int daysOfGrow, double height, char gender, bool isFlowering)
    : daysOfGrowing(daysOfGrow)
    , height(height)
    , plantGender(gender)
    , isFlowering(isFlowering)
{
}

QString Plant::plantToString()
{
    return "Days of growing: " + QString::number(daysOfGrowing) + " | Height: " + QString::number(height)
           + " | Gender: " + plantGender + " | Is Flowering: " + (isFlowering ? "Yes" : "No");
}

