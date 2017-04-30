//
// Created by knightos on 4/30/17.
//

#ifndef KPANG_KPANG_H
#define KPANG_KPANG_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class KPang
{
public:
    static void start();
private:
    static bool isExiting();
    static void gameLoop();

    enum GameState {Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting};

    static GameState gameState;
    static sf::RenderWindow mainWindow;
};

#endif //KPANG_KPANG_H
