//
// Created by knightos on 4/30/17.
//

#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject()
{
    _isLoaded=false;
}

VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::load(std::string filename)
{
    if(_image.loadFromFile(filename) != true) {
        _filename = "";
        _isLoaded = false;
    }else{
        _filename = filename;
        _sprite.setTexture(_image);
        _isLoaded = true;
    }
}

void VisibleGameObject::draw(sf::RenderWindow &window)
{
    if(_isLoaded)
        window.draw(_sprite);
}

void VisibleGameObject::setPosition(float x, float y)
{
    if(_isLoaded)
        _sprite.setPosition(x, y);
}