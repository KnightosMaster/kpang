#include "KPang.h"
#include "SplashScreen.h"
#include "MainMenu.h"


KPang::GameState KPang::gameState = Uninitialized;
sf::RenderWindow KPang::mainWindow;
PlayerPaddle KPang::_player1;

void KPang::start()
{
    if(gameState != Uninitialized)
        return;

    mainWindow.create(sf::VideoMode(1024,768,32),"KPanG!");

    _player1.load("images/paddle.png");
    _player1.setPosition((1024/2)-45,700);

    gameState = KPang::ShowingSplash;

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

void KPang::showSplash()
{
    SplashScreen splashScreen;
    splashScreen.show(mainWindow);
    gameState = ShowingMenu;
}

void KPang::showMenu()
{
    MainMenu mainMenu;
    MainMenu::MenuAction action = mainMenu.show(mainWindow);
    switch(action)
    {
        case MainMenu::Play:
            gameState = Playing;
            break;
        case MainMenu::Exit:
            gameState = Exiting;
            break;
    }
}

void KPang::gameLoop()
{
    sf::Event currentEvent;
    while(mainWindow.pollEvent(currentEvent)){

        switch(gameState)
        {
            case KPang::ShowingSplash:
            {
                showSplash();
                break;
            }
            case KPang::ShowingMenu:
            {
                showMenu();
                break;
            }
            case KPang::Playing:
            {
                mainWindow.clear(sf::Color(0,0,0));
                _player1.draw(mainWindow);
                mainWindow.display();

                if(currentEvent.type == sf::Event::Closed)
                    gameState = KPang::Exiting;

                if(currentEvent.type == sf::Event::KeyPressed)
                    if(currentEvent.key.code == sf::Keyboard::Escape)
                        showMenu();

                break;
            }
        }

    }
}

