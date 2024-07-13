/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class Bird.
*/

#pragma once

#include <SFML/Graphics.hpp>

class Bird
{
public:
    Bird(float _x, float _y, float w, float h) noexcept;

    Bird(const Bird&) = delete;

    Bird& operator = (Bird) = delete;

    void reset(float _x, float _y) noexcept;

    sf::FloatRect get_collision_rect() const noexcept;

    void jump() noexcept;
    void moving(float dt) noexcept;
    void movingRight() noexcept;
    void movingLeft() noexcept;
    void stopMovingX() noexcept;

    bool isIntangible() const noexcept;
    void setIntangible() noexcept;

    void addScore();
    int getScore() const;
    void scoreReset();

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    float x;
    float y;
    float width;
    float height;
    float vy;
    float vx;
    bool intangible{false}; // true intangible, false no intangible
    sf::Sprite sprite;
    bool jumping{false};
    bool isMovX{false};
    int score;
};
