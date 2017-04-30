//
// Created by knightos on 4/30/17.
//

#pragma once

#include "stdafx.h"

class MainMenu
{
public:
    enum MenuAction {Nothing, Play, Exit};

    struct MenuItem
    {
    public:
        sf::Rect<int> rect;
        MenuAction action;
    };

    MenuAction show(sf::RenderWindow& window);

private:
    MenuAction getMenuResponse(sf::RenderWindow& window);
    MenuAction handleClick(int x, int y);
    std::list<MenuItem> menuItems;
};




