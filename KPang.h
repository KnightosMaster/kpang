//
// Created by knightos on 4/30/17.
//

#ifndef KPANG_KPANG_H
#define KPANG_KPANG_H

#include "stdafx.h"
#include "PlayerPaddle.h"

class KPang
{
public:
    static void start();
private:
    static bool isExiting();
    static void gameLoop();

    static void showSplash();
    static void showMenu();

    enum GameState {Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting};

    static GameState gameState;
    static sf::RenderWindow mainWindow;
    static PlayerPaddle _player1;
};

#endif //KPANG_KPANG_H
