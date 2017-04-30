//
// Created by knightos on 4/30/17.
//

#pragma once

#include "VisibleGameObject.h"

class GameObjectManager
{
public:
    GameObjectManager();
    ~GameObjectManager();

    void add(std::string name, VisibleGameObject* gameObject);
    void remove(std::string name);
    int getObjectCount() const;
    VisibleGameObject* get(std::string name) const;

    void drawAll(sf::RenderWindow& window);

private:
    std::map<std::string, VisibleGameObject*> _gameObjects;

    struct GameObjectDeallocator
    {
        void operator()(const std::pair<std::string, VisibleGameObject*> & p) const
        {
            delete p.second;
        }
    };
};




