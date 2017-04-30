#include "KPang.h"

KPang::GameState KPang::gameState = Uninitialized;
sf::RenderWindow KPang::mainWindow;

void KPang::start()
{
    if(gameState != Uninitialized)
        return;

    mainWindow.create(sf::VideoMode(1024,768,32),"KPanG!");
    gameState = KPang::Playing;

    while(!isExiting()){
        gameLoop();
    }

    mainWindow.close();
}

bool KPang::isExiting()
{
    if(gameState==Exiting)
        return true;
    else
        return false;
}

void KPang::gameLoop()
{
    sf::Event currentEvent;
    while(mainWindow.pollEvent(currentEvent)){

        switch(gameState)
        {
            case KPang::Playing:
            {
                mainWindow.clear(sf::Color(255,43,76));
                mainWindow.display();

                if(currentEvent.type == sf::Event::Closed)
                    gameState = KPang::Exiting;

                break;
            }
        }

    }
}

