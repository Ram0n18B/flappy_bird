#pragma once

#include <SFML/Graphics.hpp>

class Log
{
private:
    /* data */
public:
    Log();
    ~Log();

    virtual void update() noexcept
    {}

    virtual void render(sf::RenderTarget& target) const noexcept
    {}
};

Log::Log(/* args */)
{
}

Log::~Log()
{
}
