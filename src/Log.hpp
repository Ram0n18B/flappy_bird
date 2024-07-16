/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class Log.
*/

#pragma once

#include <SFML/Graphics.hpp>

class Log
{
public:
    Log(float _x, float _y, bool inverted) noexcept;

    sf::FloatRect get_collision_rect() const noexcept;

    virtual void update(float _x, float _y) noexcept {}

    void render(sf::RenderTarget& target) const noexcept;

protected:
    float x = 0;
    float y = 0;
    float vertical_speed = 0;
    bool inverted = false;
    sf::Sprite sprite;
};