/*
    ISPPJ1 2024
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class LogPair.
*/

#pragma once

#include <memory>
#include <src/Bird.hpp>
#include <src/StaticLog.hpp>

class LogPair
{
public:
    LogPair(float _x, float _y) noexcept;

    bool collides(const sf::FloatRect& rect) const noexcept;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

    bool is_out_of_game() const noexcept;

    bool update_scored(const sf::FloatRect& rect) noexcept;

    void reset(float _x, float _y) noexcept;

private:
    float x;
    float y;
    std::shared_ptr<Log> top = nullptr;
    std::shared_ptr<Log> bottom = nullptr;

    bool scored{false};
};