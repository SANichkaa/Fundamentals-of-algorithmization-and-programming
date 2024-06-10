#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include <QMap>
#include <QPair>
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QTextStream>
#include <QDataStream>
#include <QFile>

#include "happiness.h"
#include "clothes.h"
#include "food.h"
#include "health.h"
#include "housing.h"
#include "job.h"
#include "relationship.h"
#include "transport.h"

class Character : public QObject {
    Q_OBJECT
public:
    Character(int age, int happiness, int health, int money, int monthlyIncome, int monthlyExpenses, QString job, QString food, QString housing, QString relationship, QString transport, QString clothes);

    static Character* GetInstance() {
        if(!character) {
            character = new Character(18, 100, 100, 1000, 0, 0, "Нет", "Нет", "Нет", "Нет", "Нет", "Нет");
        }
        return character;
    }

    bool loadCharacterData();

    bool saveCharacterData();


    // Getters
    int getAge() const;
    int getHappiness() const;
    int getHealth() const;
    int getMoney() const;
    QString getJob() const;
    QString getFood() const;
    QString getHousing() const;
    QString getRelationship() const;
    QString getTransport() const;
    QString getClothing() const;
    int getMonthlyExpenses() const;
    int getMonthlyIncome() const;
    int getMonthsAtCurrentJob() const;

    // Setters
    void setAge(int age);
    void setHappiness(int happiness);
    void setHealth(int health);
    void setMoney(int money);
    void setMonthlyIncome(int monthlyIncome);
    void setMonthlyExpenses(int monthlyExpenses);
    void setJob(const QString &job);
    void setFood(const QString &food);
    void setHousing(const QString &housing);
    void setRelationship(const QString &relationship);
    void setTransport(const QString &transport);
    void setClothing(const QString &clothing);

    // Update months at current job
    void updateMonthsAtCurrentJob();
    void onInGameMonthPassed();

    bool canChangeJob() const;

private:
    void Update_all_in_file();


public slots:
    void updateChanges();
    void betChange(int moneyMinus);

    void updateTimeOnJob();
private:
    int age;
    int happiness;
    int health;
    int money;
    QString job;
    QString food;
    QString housing;
    QString relationship;
    QString transport;
    QString clothes;
    QString name;
    int monthlyExpenses;
    int monthlyIncome;
    int monthsAtCurrentJob;
    QTimer* timer;

    int timeOnCurrentJob;
    QTimer jobTimer;

    QString file_name = "character.txt";

    static const int REQUIRED_TIME_ON_JOB = 10000;

    void updateMonthlyExpenses();
    void updateMonthlyIncome();

    QMap<QString, int> availableJobs;
    QMap<QString, int> availableFoods;
    QMap<QString, int> availableHousings;
    QMap<QString, int> availableRelationships;
    QMap<QString, int> availableTransports;
    QMap<QString, int> availableClothings;

    static Character* character;
    Character( const Character&);
    Character operator=(Character&);


signals:
    void updateHealth();
    void updateHappiness();
    void updateMoney();
    void updateAge();
    void updateJob();
    void updateRelationship();
    void updateTransport();
    void updateFood();
    void updateClothes();
    void updateHousing();
    void updateIncome();
    void updateExpenses();
    void characterDataChanged();

};
#endif // CHARACTER_H
