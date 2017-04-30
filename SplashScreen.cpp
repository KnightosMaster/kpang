//
// Created by knightos on 4/30/17.
//

#include "SplashScreen.h"

void SplashScreen::show(sf::RenderWindow window) {
    sf::Texture splash;
    if(splash.loadFromFile("images/Splash.png") != true)
        return;

    sf::Sprite sprite(splash);
    window.draw(sprite);
    window.display();

    sf::Event event;
    while(true){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::EventType::MouseButtonPressed
             ||event.type == sf::Event::EventType::KeyPressed
             ||event.type == sf::Event::EventType::Closed){
                return
            }
        }
    }

};