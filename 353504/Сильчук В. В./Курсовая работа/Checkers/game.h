#ifndef GAME_H
#define GAME_H
#include "model.h"
#include "mainwindow.h"
#include "controller.h"

class Game
{
public:
    Game();

private:
    std::unique_ptr<Model> model_;
    std::unique_ptr<MainWindow> view_;
    std::unique_ptr<Controller> controller_;
};
#endif // GAME_H
