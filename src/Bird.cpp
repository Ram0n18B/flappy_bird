/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class Bird.
*/

#include <Settings.hpp>
#include <src/Bird.hpp>

Bird::Bird(float _x, float _y, float w, float h) noexcept
    : x{_x}, y{_y}, width{w}, height{h}, vy{0.f}, vx{0}, sprite{Settings::textures["bird"]}, score{0}
{
    sprite.setPosition(x, y);
}

void Bird::reset(float _x, float _y) noexcept
{
    x = _x;
    y = _y;
    vy = 0.f;
    vx = 0.f;
    sprite.setPosition(x, y);
}

sf::FloatRect Bird::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, width, height};
}

void Bird::jump() noexcept
{
    if (!jumping)
    {
        jumping = true;
    }
}

void Bird::movingRight() noexcept 
{
    vx = Settings::BIRD_SPEED_X;
    isMovX = true;
}

void Bird::movingLeft() noexcept 
{
    vx = -Settings::BIRD_SPEED_X;
    isMovX = true;
}

void Bird::stopMovingX() noexcept
{
    isMovX = false;
}

void Bird::addScore()
{
    ++score;
}

int Bird::getScore() const
{
    return score;
}

void Bird::scoreReset()
{
    score = 0;
}

void Bird::update(float dt) noexcept
{
    vy += Settings::GRAVITY * dt;

    if (jumping)
    {
        Settings::sounds["jump"].play();
        vy = -Settings::JUMP_TAKEOFF_SPEED;
        jumping = false;
    }

    if (!isMovX) 
    {
        vx = 0.f;
    }

    x += vx * dt;
    y += vy * dt;
    sprite.setPosition(x, y);
}

void Bird::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}