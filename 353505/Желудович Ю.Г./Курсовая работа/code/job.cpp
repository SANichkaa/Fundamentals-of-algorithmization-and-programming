#include "job.h"
#include "ui_job.h"

Job::Job(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Job)
{
    ui->setupUi(this);

    connect(this, SIGNAL(updateJobSignal()), Character::GetInstance(), SLOT(updateChanges()));


    connect(Character::GetInstance(), SIGNAL(updateHealth()), this, SLOT(updateHealth()));
    connect(Character::GetInstance(), SIGNAL(updateHappiness()), this, SLOT(updateHappiness()));

    ui->healthBar->setValue(Character::GetInstance()->getHealth());
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());

}

Job::~Job()
{
    delete ui;
}

void Job::on_pushButton_8_clicked()
{
    emit(OpenMainWindow());
    close();
}

void Job::updateHealth()
{
    ui->healthBar->setValue(Character::GetInstance()->getHealth());
}

void Job::updateHappiness() {
    ui->happinessBar->setValue(Character::GetInstance()->getHappiness());
}


void Job::on_pushButton_clicked()
{
    if (Character::GetInstance()->getHousing() != "Нет") {
        Character::GetInstance()->setJob("Промоутер");
        ui->pushButton->setEnabled(false);
        ui->pushButton->hide();
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_38->setEnabled(true);
            tim->stop();
        });
        tim->start();

    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Жилье: общежитие");
    }
}

void Job::on_pushButton_38_clicked()
{
    if (Character::GetInstance()->getClothing() != "Нет") {
        Character::GetInstance()->setJob("Курьер");
        ui->pushButton_38->setEnabled(false);
        ui->pushButton_38->hide();
        ui->pushButton->show();
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_34->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Одежда: Кеды, шорты и майка");
    }
}


void Job::on_pushButton_34_clicked()
{
 //   if (Character::GetInstance()->getClothing() != "Нет") {
        Character::GetInstance()->setJob("Билетный контролер");
        ui->pushButton_34->setEnabled(false);
        ui->pushButton_34->hide();
        ui->pushButton_38->show();
        ui->pushButton_38->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_35->setEnabled(true);
            tim->stop();
        });
        tim->start();
  //  }
//    else {
//        QMessageBox::information(this, "Не выполнены все условия", "Одежда: Кеды, шорты и майка");
//    }
}


void Job::on_pushButton_35_clicked()
{
    if (Character::GetInstance()->getFood() != "Нет") {
        Character::GetInstance()->setJob("Пиццмейкер");
        ui->pushButton_35->setEnabled(false);
        ui->pushButton_35->hide();
        ui->pushButton_34->show();
        ui->pushButton_34->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_36->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Еда: Бесплатная еда на работе");
    }
}


void Job::on_pushButton_36_clicked()
{
    if (Character::GetInstance()->getFood() != "Бесплатная еда на работе" && Character::GetInstance()->getClothing() != "Кеды, шорты и майка") {
        Character::GetInstance()->setJob("Кассир");
        ui->pushButton_36->setEnabled(false);
        ui->pushButton_36->hide();
        ui->pushButton_35->show();
        ui->pushButton_35->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_37->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Еда: Бургер и бесплатная еда на работе <br>Одежда: Джинсы, кроссовки и майка");
    }
}


void Job::on_pushButton_37_clicked()
{
    if (Character::GetInstance()->getTransport() != "Нет") {
        Character::GetInstance()->setJob("Таксист");
        ui->pushButton_37->setEnabled(false);
        ui->pushButton_37->hide();
        ui->pushButton_36->show();
        ui->pushButton_36->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_43->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Трансопрт: 40-летняя машина");
    }
}


void Job::on_pushButton_43_clicked()
{
    if (Character::GetInstance()->getClothing() != "Джинсы, кроссовки и майка" && Character::GetInstance()->getHousing() != "Общежитие") {
        Character::GetInstance()->setJob("Бармен");
        ui->pushButton_43->setEnabled(false);
        ui->pushButton_43->hide();
        ui->pushButton_37->show();
        ui->pushButton_37->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_40->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Одежда: Дешевая одежда с рынка <br>Жилье: Отдельная комната");
    }
}


void Job::on_pushButton_40_clicked()
{
    if (Character::GetInstance()->getTransport() != "40-летняя машина" && Character::GetInstance()->getRelationship() != "Нет") {
        Character::GetInstance()->setJob("Официант");
        ui->pushButton_40->setEnabled(false);
        ui->pushButton_40->hide();
        ui->pushButton_43->show();
        ui->pushButton_43->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_41->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Транспорт: 30-летняя машина <br>Семья: Девушка");
    }
}


void Job::on_pushButton_41_clicked()
{
    if (Character::GetInstance()->getClothing() != "Дешевая одежда с рынка") {
        Character::GetInstance()->setJob("Администратор ресторана");
        ui->pushButton_41->setEnabled(false);
        ui->pushButton_41->hide();
        ui->pushButton_40->show();
        ui->pushButton_40->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_39->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Одежда: Ботинки, штаны, свитер");
    }
}


void Job::on_pushButton_39_clicked()
{
    if (Character::GetInstance()->getTransport() != "30-летняя машина") {
        Character::GetInstance()->setJob("Заведующий рестораном");
        ui->pushButton_39->setEnabled(false);
        ui->pushButton_39->hide();
        ui->pushButton_41->show();
        ui->pushButton_41->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_42->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Транспорт: 10-летняя машина");
    }
}


void Job::on_pushButton_42_clicked()
{
    if (Character::GetInstance()->getRelationship() != "Девушка" && Character::GetInstance()->getTransport() != "10-летняя машина") {
        Character::GetInstance()->setJob("Директор ресторана");
        ui->pushButton_42->setEnabled(false);
        ui->pushButton_42->hide();
        ui->pushButton_39->show();
        ui->pushButton_39->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_48->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Семья: Жена <br>Транспорт: Б/у машина");
    }
}


void Job::on_pushButton_48_clicked()
{
    if (Character::GetInstance()->getFood() != "Бургер и бесплатная еда на работе") {
        Character::GetInstance()->setJob("Менеджер по продажам");
        ui->pushButton_48->setEnabled(false);
        ui->pushButton_48->hide();
        ui->pushButton_42->show();
        ui->pushButton_42->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_45->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Еда: Бургер и картошка фри с газировкой");
    }
}


void Job::on_pushButton_45_clicked()
{
    if (Character::GetInstance()->getHousing() != "Отдельная комната") {
        Character::GetInstance()->setJob("Старший менеджер");
        ui->pushButton_45->setEnabled(false);
        ui->pushButton_45->hide();
        ui->pushButton_48->show();
        ui->pushButton_48->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_44->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Дешевые апартаменты");
    }
}


void Job::on_pushButton_44_clicked()
{
    if (Character::GetInstance()->getHousing() != "Дешевые апартаменты" && Character::GetInstance()->getFood() != "Бургер, картошка фри и газировка") {
        Character::GetInstance()->setJob("Супервайзер");
        ui->pushButton_44->setEnabled(false);
        ui->pushButton_44->hide();
        ui->pushButton_45->show();
        ui->pushButton_45->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_47->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Апартаменты среднего класса <br>Еда: Фастфуд из супермаркета");
    }
}


void Job::on_pushButton_47_clicked()
{
    if (Character::GetInstance()->getFood() != "Фастфуд из супермаркета") {
        Character::GetInstance()->setJob("Начальник отдела продаж");
        ui->pushButton_47->setEnabled(false);
        ui->pushButton_47->hide();
        ui->pushButton_44->show();
        ui->pushButton_44->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_46->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Еда: Дешевое кафе");
    }
}


void Job::on_pushButton_46_clicked()
{
    if (Character::GetInstance()->getHousing() != "Апартаменты среднего класса" && Character::GetInstance()->getTransport() != "Б/у машина" && Character::GetInstance()->getRelationship() != "Жена") {
        Character::GetInstance()->setJob("Босс в компании по продажам");
        ui->pushButton_46->setEnabled(false);
        ui->pushButton_46->hide();
        ui->pushButton_47->show();
        ui->pushButton_47->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_55->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Комфортные апартаменты <br>Еда: Фастфуд из супермаркета <br>Семья: Жена + ребенок");
    }
}


void Job::on_pushButton_55_clicked()
{
   // if (Character::GetInstance()->getHousing() != "Дешевая квартира" && Character::GetInstance()->getFood() != "Бургер, картошка фри и газировка") {
        Character::GetInstance()->setJob("Копирайтер");
        ui->pushButton_55->setEnabled(false);
        ui->pushButton_55->hide();
        ui->pushButton_46->show();
        ui->pushButton_46->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_53->setEnabled(true);
            tim->stop();
        });
        tim->start();
//    }
//    else {
//        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Квартира среднего класса <br>Еда: Фастфуд из супермаркета");
//    }
}


void Job::on_pushButton_53_clicked()
{
    // if (Character::GetInstance()->getHousing() != "Дешевая квартира" && Character::GetInstance()->getFood() != "Бургер, картошка фри и газировка") {
         Character::GetInstance()->setJob("Программист");
         ui->pushButton_53->setEnabled(false);
         ui->pushButton_53->hide();
         ui->pushButton_55->show();
         ui->pushButton_55->setEnabled(false);
         emit updateJobSignal();
         QTimer* tim = new QTimer(this);
         tim->setInterval(30000);
         connect(tim, &QTimer::timeout, this, [=]()mutable{
             ui->pushButton_54->setEnabled(true);
             tim->stop();
         });
         tim->start();
 //    }
 //    else {
 //        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Квартира среднего класса <br>Еда: Фастфуд из супермаркета");
 //    }
}


void Job::on_pushButton_54_clicked()
{
    // if (Character::GetInstance()->getHousing() != "Дешевые апартаменты" && Character::GetInstance()->getFood() != "Бургер, картошка фри и газировка") {
         Character::GetInstance()->setJob("Верстальщик");
         ui->pushButton_54->setEnabled(false);
         ui->pushButton_54->hide();
         ui->pushButton_53->show();
         ui->pushButton_53->setEnabled(false);
         emit updateJobSignal();
         QTimer* tim = new QTimer(this);
         tim->setInterval(30000);
         connect(tim, &QTimer::timeout, this, [=]()mutable{
             ui->pushButton_56->setEnabled(true);
             tim->stop();
         });
         tim->start();
 //    }
 //    else {
 //        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Апартаменты среднего класса <br>Еда: Фастфуд из супермаркета");
 //    }
}


void Job::on_pushButton_56_clicked()
{
    if (Character::GetInstance()->getFood() != "Дешевое кафе") {
        Character::GetInstance()->setJob("Веб-дизайнер");
        ui->pushButton_56->setEnabled(false);
        ui->pushButton_56->hide();
        ui->pushButton_54->show();
        ui->pushButton_54->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_51->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Еда: Домашняя еда");
    }
}


void Job::on_pushButton_51_clicked()
{
    // if (Character::GetInstance()->getHousing() != "Дешевая квартира" && Character::GetInstance()->getFood() != "Бургер, картошка фри и газировка") {
         Character::GetInstance()->setJob("Главный программист");
         ui->pushButton_51->setEnabled(false);
         ui->pushButton_51->hide();
         ui->pushButton_56->show();
         ui->pushButton_56->setEnabled(false);
         emit updateJobSignal();
         QTimer* tim = new QTimer(this);
         tim->setInterval(30000);
         connect(tim, &QTimer::timeout, this, [=]()mutable{
             ui->pushButton_49->setEnabled(true);
             tim->stop();
         });
         tim->start();
 //    }
 //    else {
 //        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Квартира среднего класса <br>Еда: Фастфуд из супермаркета");
 //    }
}


void Job::on_pushButton_49_clicked()
{
    // if (Character::GetInstance()->getHousing() != "Дешевая квартира" && Character::GetInstance()->getFood() != "Бургер, картошка фри и газировка") {
         Character::GetInstance()->setJob("Администратор веб проектов");
         ui->pushButton_49->setEnabled(false);
         ui->pushButton_49->hide();
         ui->pushButton_51->show();
         ui->pushButton_51->setEnabled(false);
         emit updateJobSignal();
         QTimer* tim = new QTimer(this);
         tim->setInterval(30000);
         connect(tim, &QTimer::timeout, this, [=]()mutable{
             ui->pushButton_50->setEnabled(true);
             tim->stop();
         });
         tim->start();
 //    }
 //    else {
 //        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Квартира среднего класса <br>Еда: Фастфуд из супермаркета");
 //    }
}


void Job::on_pushButton_50_clicked()
{
    // if (Character::GetInstance()->getHousing() != "Дешевая квартира" && Character::GetInstance()->getFood() != "Бургер, картошка фри и газировка") {
         Character::GetInstance()->setJob("Начальник IT студии");
         ui->pushButton_50->setEnabled(false);
         ui->pushButton_50->hide();
         ui->pushButton_49->show();
         ui->pushButton_49->setEnabled(false);
         emit updateJobSignal();
         QTimer* tim = new QTimer(this);
         tim->setInterval(30000);
         connect(tim, &QTimer::timeout, this, [=]()mutable{
             ui->pushButton_52->setEnabled(true);
             tim->stop();
         });
         tim->start();
 //    }
 //    else {
 //        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Квартира среднего класса <br>Еда: Фастфуд из супермаркета");
 //    }
}


void Job::on_pushButton_52_clicked()
{
    if (Character::GetInstance()->getHousing() != "Комфортные апартаменты") {
        Character::GetInstance()->setJob("Директор IT студии");
        ui->pushButton_52->setEnabled(false);
        ui->pushButton_52->hide();
        ui->pushButton_50->show();
        ui->pushButton_50->setEnabled(false);
        emit updateJobSignal();
        QTimer* tim = new QTimer(this);
        tim->setInterval(30000);
        connect(tim, &QTimer::timeout, this, [=]()mutable{
            ui->pushButton_58->setEnabled(true);
            tim->stop();
        });
        tim->start();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Комфортная квартира в центре города");
    }
}


void Job::on_pushButton_58_clicked()
{
    // if (Character::GetInstance()->getHousing() != "Дешевая квартира" && Character::GetInstance()->getFood() != "Бургер, картошка фри и газировка") {
         Character::GetInstance()->setJob("Бухгалтер");
         ui->pushButton_58->setEnabled(false);
         ui->pushButton_58->hide();
         ui->pushButton_52->show();
         ui->pushButton_52->setEnabled(false);
         emit updateJobSignal();
         QTimer* tim = new QTimer(this);
         tim->setInterval(30000);
         connect(tim, &QTimer::timeout, this, [=]()mutable{
             ui->pushButton_57->setEnabled(true);
             tim->stop();
         });
         tim->start();
 //    }
 //    else {
 //        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Квартира среднего класса <br>Еда: Фастфуд из супермаркета");
 //    }
}


void Job::on_pushButton_57_clicked()
{
    // if (Character::GetInstance()->getHousing() != "Дешевая квартира" && Character::GetInstance()->getFood() != "Бургер, картошка фри и газировка") {
         Character::GetInstance()->setJob("Помощник аудитора");
         ui->pushButton_57->setEnabled(false);
         ui->pushButton_57->hide();
         ui->pushButton_58->show();
         ui->pushButton_58->setEnabled(false);
         emit updateJobSignal();
         QTimer* tim = new QTimer(this);
         tim->setInterval(30000);
         connect(tim, &QTimer::timeout, this, [=]()mutable{
             ui->pushButton_60->setEnabled(true);
             tim->stop();
         });
         tim->start();
 //    }
 //    else {
 //        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Квартира среднего класса <br>Еда: Фастфуд из супермаркета");
 //    }
}


void Job::on_pushButton_60_clicked()
{
    // if (Character::GetInstance()->getHousing() != "Дешевая квартира" && Character::GetInstance()->getFood() != "Бургер, картошка фри и газировка") {
         Character::GetInstance()->setJob("Аудитор");
         ui->pushButton_60->setEnabled(false);
         ui->pushButton_60->hide();
         ui->pushButton_57->show();
         ui->pushButton_57->setEnabled(false);
         emit updateJobSignal();
         QTimer* tim = new QTimer(this);
         tim->setInterval(30000);
         connect(tim, &QTimer::timeout, this, [=]()mutable{
             ui->pushButton_62->setEnabled(true);
             tim->stop();
         });
         tim->start();
 //    }
 //    else {
 //        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Квартира среднего класса <br>Еда: Фастфуд из супермаркета");
 //    }
}


void Job::on_pushButton_62_clicked()
{
    if (Character::GetInstance()->getClothing() != "Новая одежда") {
            Character::GetInstance()->setJob("Главный бухгалтер");
            ui->pushButton_62->setEnabled(false);
            ui->pushButton_62->hide();
            ui->pushButton_60->show();
            ui->pushButton_60->setEnabled(false);
            emit updateJobSignal();
            QTimer* tim = new QTimer(this);
            tim->setInterval(30000);
            connect(tim, &QTimer::timeout, this, [=]()mutable{
                ui->pushButton_61->setEnabled(true);
                tim->stop();
            });
            tim->start();
        }
        else {
            QMessageBox::information(this, "Не выполнены все условия", "Одежда: Костюм с галстуком");
        }
}


void Job::on_pushButton_61_clicked()
{
    if (Character::GetInstance()->getHousing() != "Комфортная квартира в центре города") {
            Character::GetInstance()->setJob("Ведущий аудитор");
            ui->pushButton_61->setEnabled(false);
            ui->pushButton_61->hide();
            ui->pushButton_62->show();
            ui->pushButton_62->setEnabled(false);
            emit updateJobSignal();
            QTimer* tim = new QTimer(this);
            tim->setInterval(30000);
            connect(tim, &QTimer::timeout, this, [=]()mutable{
                ui->pushButton_63->setEnabled(true);
                tim->stop();
            });
            tim->start();
        }
        else {
            QMessageBox::information(this, "Не выполнены все условия", "Жилье: Маленький дом за городом");
        }
}


void Job::on_pushButton_63_clicked()
{
    // if (Character::GetInstance()->getHousing() != "Дешевая квартира" && Character::GetInstance()->getFood() != "Бургер, картошка фри и газировка") {
         Character::GetInstance()->setJob("Бизнес консультант");
         ui->pushButton_63->setEnabled(false);
         ui->pushButton_63->hide();
         ui->pushButton_61->show();
         ui->pushButton_61->setEnabled(false);
         emit updateJobSignal();
         QTimer* tim = new QTimer(this);
         tim->setInterval(30000);
         connect(tim, &QTimer::timeout, this, [=]()mutable{
             ui->pushButton_64->setEnabled(true);
             tim->stop();
         });
         tim->start();
 //    }
 //    else {
 //        QMessageBox::information(this, "Не выполнены все условия", "Жилье: Квартира среднего класса <br>Еда: Фастфуд из супермаркета");
 //    }
}


void Job::on_pushButton_64_clicked()
{
    if (Character::GetInstance()->getRelationship() != "Жена + ребенок") {
            Character::GetInstance()->setJob("Бизнес менеджер");
            ui->pushButton_64->setEnabled(false);
            ui->pushButton_64->hide();
            ui->pushButton_63->show();
            ui->pushButton_63->setEnabled(false);
            emit updateJobSignal();
            QTimer* tim = new QTimer(this);
            tim->setInterval(30000);
            connect(tim, &QTimer::timeout, this, [=]()mutable{
                ui->pushButton_59->setEnabled(true);
                tim->stop();
            });
            tim->start();
        }
        else {
            QMessageBox::information(this, "Не выполнены все условия", "Семья: Жена + 2 ребенка");
        }
}


void Job::on_pushButton_59_clicked()
{
    if (Character::GetInstance()->getFood() != "Домашняя еда" && Character::GetInstance()->getTransport() != "Новая машина") {
        Character::GetInstance()->setJob("Начальник отдела финансовых консультаций");
        ui->pushButton_59->setEnabled(false);
        ui->pushButton_59->hide();
        ui->pushButton_64->show();
        ui->pushButton_64->setEnabled(false);
        emit updateJobSignal();
    }
    else {
        QMessageBox::information(this, "Не выполнены все условия", "Еда: Еда в дорогом ресторане <br>Транспорт: Пикап");
    }
}

