#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity(float _x, float _y);
    ~Entity();

private:
    float x;
    float y;
    sf::Sprite sprite;
};

Entity::Entity(float _x, float _y): x{_x}, y{_y}
{}

Entity::~Entity()
{
}
