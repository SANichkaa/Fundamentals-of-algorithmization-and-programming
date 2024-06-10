#include "character.h"

Character* Character::character = nullptr;

Character::Character(int age, int happiness, int health, int money, int monthlyExpenses, int monthlyIncome, QString job, QString food, QString housing, QString relationship, QString transport, QString clothes)
    : age(age), happiness(happiness), health(health), money(money), monthlyExpenses(monthlyExpenses), monthlyIncome(monthlyIncome), job(job), food(food), housing(housing), relationship(relationship), transport(transport), clothes(clothes), monthsAtCurrentJob(0)
{

    connect(&jobTimer, &QTimer::timeout, this, &Character::updateTimeOnJob);

    availableJobs =  {
        {"Нет", 0},
        {"Промоутер", 120},
        {"Курьер", 150},
        {"Билетный контролер", 170},
        {"Пиццмейкер", 200},
        {"Кассир", 240},
        {"Таксист", 550},
        {"Бармен", 800},
        {"Официант", 1100},
        {"Администратор ресторана", 1600},
        {"Заведующий рестораном", 2200},
        {"Директор ресторана", 3000},
        {"Менеджер по продажам", 1700},
        {"Старший менеджер", 2200},
        {"Супервайзер", 2700},
        {"Начальник отдела продаж", 3200},
        {"Босс в компании по продажам", 4000},
        {"Копирайтер", 2800},
        {"Программист", 3200},
        {"Верстальщик", 3600},
        {"Веб-дизайнер", 4000},
        {"Главный программист", 4200},
        {"Администратор веб проектов", 4500},
        {"Начальник IT студии", 4700},
        {"Директор IT студии", 5400},
        {"Бухгалтер", 4400},
        {"Помощник аудитора", 5200},
        {"Аудитор", 5800},
        {"Главный бухгалтер", 6200},
        {"Ведущий аудитор", 8000},
        {"Бизнес консультант", 9000},
        {"Бизнес менеджер", 11000},
        {"Начальник отдела финансовых консультаций", 20000}
};

    availableFoods =  {
        {"Нет", 0},
        {"Бесплатная еда на работе", 0},
        {"Бургер и бесплатная еда на работе", 100},
        {"Бургер, картошка фри и газировка", 200},
        {"Фаст фуд с супермаркета", 500},
        {"Дешевое кафе", 750},
        {"Домашняя еда", 1300},
        {"Еда в дорогом ресторане", 2500}
    };

    availableClothings = {
        {"Нет", 0},
        {"Кеды, шорты и майка", 10},
        {"Джинсы, кроссовки и майка", 50},
        {"Дешевая одежда с рынка", 150},
        {"Ботинки, штаны, свитер", 200},
        {"Новая одежда", 500},
        {"Костюм с галстуком", 1500}
    };

    availableHousings = {
        {"Нет", 0},
        {"Общежитие", 100},
        {"Отдельная комната", 200},
        {"Дешевые апартаменты", 450},
        {"Апартаменты среднего класса", 800},
        {"Комфортные апартаменты", 1000},
        {"Комфортная квартира в центре города", 1800},
        {"Маленький дом за городом", 3600},
        {"Средний дом на окраине города", 4500}
    };

    availableRelationships = {
        {"Нет", 0},
        {"Девушка", 100},
        {"Жена", 1200},
        {"Жена + ребенок", 1600},
        {"Жена + 2 ребенка", 2500}
    };

    availableTransports = {
        {"Нет", 0},
        {"40-летняя машина", 1300},
        {"30-летняя машина", 3500},
        {"10-летняя машина", 7000},
        {"Б/у машина", 13000},
        {"Новая машина", 15000},
        {"Пикап", 23000},
    };

    updateMonthlyExpenses();
    updateMonthlyIncome();


    // Set up a timer to update the balance and months at the job every in-game month
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Character::onInGameMonthPassed);
    timer->start(1 * 30 * 1000); // 1 seconds for an in-game day

}

int Character::getAge() const { return age; }
int Character::getHappiness() const { return happiness; }
int Character::getHealth() const { return health; }
int Character::getMoney() const { return money; }
QString Character::getJob() const { return job; }
QString Character::getFood() const { return food; }
QString Character::getHousing() const { return housing; }
QString Character::getRelationship() const { return relationship; }
QString Character::getTransport() const { return transport; }
QString Character::getClothing() const { return clothes; }
int Character::getMonthlyExpenses() const { return monthlyExpenses; }
int Character::getMonthlyIncome() const { return monthlyIncome; }
int Character::getMonthsAtCurrentJob() const { return monthsAtCurrentJob; }
void Character::setAge(int newAge) { if (age != newAge) {
        age = newAge;
        emit characterDataChanged();
    } }
void Character::setHappiness(int newHappiness) { if (happiness != newHappiness) {
        happiness = newHappiness;
        emit characterDataChanged();
    } }
void Character::setHealth(int newHealth) {

    if (health != newHealth) {
        health = newHealth;
        emit characterDataChanged();
    }
}
void Character::setMoney(int newMoney) { if (money != newMoney) {
        money = newMoney;
        emit characterDataChanged();
    } }
void Character::setMonthlyIncome(int newMonthlyIncome) {if (monthlyIncome != newMonthlyIncome) {
        monthlyIncome = newMonthlyIncome;
        emit characterDataChanged();
    } }
void Character::setMonthlyExpenses(int newMonthlyExpenses) {if (monthlyExpenses != newMonthlyExpenses) {
        monthlyExpenses = newMonthlyExpenses;

        emit characterDataChanged();
    } }

void Character::setFood(const QString &newFood) {
    if (food != newFood) {
            food = newFood;
            emit characterDataChanged();
        }
    this->food = newFood;
    updateMonthlyExpenses();
}

void Character::setHousing(const QString &newHousing) {
    if (housing != newHousing) {
            housing = newHousing;
            emit characterDataChanged();
        }
    this->housing = newHousing;
    updateMonthlyExpenses();
}

void Character::setRelationship(const QString &newRelationship) {
    if (relationship != newRelationship) {
            relationship = newRelationship;
            emit characterDataChanged();
        }
    this->relationship = newRelationship;
    updateMonthlyExpenses();
}

void Character::setTransport(const QString &newTransport) {
    if (transport != newTransport) {
            transport = newTransport;
            emit characterDataChanged();
        }
    this->transport = newTransport;
    money -= availableTransports.value(transport, 0);
    emit updateMoney();
}

void Character::setClothing(const QString &newClothes) {
    if (clothes != newClothes) {
            clothes = newClothes;
            emit characterDataChanged();
        }
    this->clothes = newClothes;
    updateMonthlyExpenses();
}

void Character::updateMonthsAtCurrentJob() {
    monthsAtCurrentJob++;
}

void Character::updateMonthlyExpenses() {
    monthlyExpenses = availableFoods.value(food, 0) +
                      availableHousings.value(housing, 0) +
                      availableRelationships.value(relationship, 0) +
                      availableClothings.value(clothes, 0);
}

void Character::updateMonthlyIncome() {
    monthlyIncome = availableJobs.value(job, 0);
}

void Character::onInGameMonthPassed() {
    money += monthlyIncome;
    money -= monthlyExpenses;
    emit updateMoney();

    // Update months at the current job
    updateMonthsAtCurrentJob();


    // Optionally, update age if a year has passed (12 in-game months)
    if (monthsAtCurrentJob % 12 == 0) {
        age++;
        emit updateAge();
    }

    if (age <= 33) {
            health -= 4;
            emit updateHealth();
            happiness -= 5;
            emit updateHappiness();
        } else {
            health -= 8;
            emit updateHealth();
            happiness -= 10;
            emit updateHappiness();
        }

        // Ensure health and happiness do not fall below 0
        if (health < 0) health = 0;
        emit updateHealth();
        if (happiness < 0) happiness = 0;
        emit updateHappiness();

}

void Character::updateChanges()
{
    emit updateHappiness();
    emit updateHealth();
    emit updateMoney();
    emit updateJob();
    emit updateRelationship();
    emit updateTransport();
    emit updateFood();
    emit updateClothes();
    emit updateHousing();
    emit updateExpenses();
    emit updateIncome();
}

void Character::setJob(const QString &job) {
       if (job != Character::GetInstance()->getJob()) {
           this->job = job;
           timeOnCurrentJob = 0;
           jobTimer.start();
           updateMonthlyIncome();
           emit updateJob();
       }
   }

void Character::updateTimeOnJob() {
        timeOnCurrentJob += jobTimer.interval();
        if (canChangeJob()) {
            jobTimer.stop();
        }
    }

bool Character::canChangeJob() const {
        return timeOnCurrentJob >= REQUIRED_TIME_ON_JOB;
    }


bool Character::loadCharacterData() {

    QFile file(file_name);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    if(file.size() == 0) {
        return false;
    }
    QTextStream in(&file);

    QString age = in.readLine();
    QString health = in.readLine();
    QString happiness = in.readLine();
    QString monthlyIncome = in.readLine();
    QString monthlyExp = in.readLine();
    QString money = in.readLine();
    QString job = in.readLine();
    QString relation = in.readLine();
    QString clothes = in.readLine();
    QString food = in.readLine();
    QString housing = in.readLine();
    QString transport = in.readLine();


    this -> age = age.toInt();
    this -> health = health.toInt();
    this -> happiness = happiness.toInt();

    this -> monthlyIncome = monthlyIncome.toInt();
    this -> monthlyExpenses = monthlyExp.toInt();
    this -> money = money.toInt();

    this -> job = job;
    this -> relationship = relation;
    this -> clothes = clothes;
    this -> food = food;
    this -> housing = housing;
    this -> transport = transport;


    file.close();

    return true;
}

bool Character::saveCharacterData() {
    QFile file(file_name);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(nullptr, "Error!", "Couldn't save to file. File already exists.");
        return false;
    }

    file.resize(0);

    QTextStream out(&file);

    out << age << '\n';
    out << health << '\n';
    out << happiness << '\n';

    out << monthlyIncome << '\n';
    out << monthlyExpenses << '\n';
    out << money << '\n';

    out << job << '\n';
    out << relationship << '\n';
    out << clothes << '\n';
    out << food << '\n';
    out << housing << '\n';
    out << transport << '\n';

    return true;
}
void Character::betChange(int money)
{
    this->money -= money;
    emit updateMoney();
}
