//
// Created by knightos on 4/30/17.
//

#include "MainMenu.h"

MainMenu::MenuAction MainMenu::show(sf::RenderWindow& window)
{
    //First we get the menu Image
    sf::Texture menuTexture;
    menuTexture.loadFromFile("images/mainmenu.png");
    sf::Sprite menuSprite(menuTexture);

    //Now we get all clickety

    //Play button
    MenuItem playButton;
    playButton.rect = sf::Rect<int> (0,145,1023,235);
    playButton.action = Play;

    //Exit button
    MenuItem exitButton;
    exitButton.rect = sf::Rect<int> (0,383,1023,177);
    exitButton.action = Exit;

    menuItems.push_back(playButton);
    menuItems.push_back(exitButton);

    window.draw(menuSprite);
    window.display();

    return getMenuResponse(window);
}

MainMenu::MenuAction MainMenu::handleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;

    for (it = menuItems.begin(); it != menuItems.end(); it++){
        sf::Rect<int> menuItemRect = (*it).rect;
        if(menuItemRect.contains(x,y))
            return (*it).action;
    }

    return Nothing;
}

MainMenu::MenuAction MainMenu::getMenuResponse(sf::RenderWindow& window)
{
    sf::Event menuEvent;

    while(true){
        while(window.pollEvent(menuEvent)){
            if(menuEvent.type == sf::Event::MouseButtonPressed)
                return handleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
            if(menuEvent.type == sf::Event::Closed)
                return Exit;
        }
    }

}