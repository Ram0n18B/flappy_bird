#include <Settings.hpp>
#include <src/PowerUp.hpp>


PowerUp::PowerUp(float _x, float _y, float w, float h) noexcept
    : x{_x}, y{_y}, width{w}, height{h}, sprite{Settings::textures["berrie"]}
{
    sprite.setPosition(x, y);
}

bool PowerUp::collides(const sf::FloatRect& rect) const noexcept
{
    return get_collision_rect().intersects(rect);
}

sf::FloatRect PowerUp::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, width, height};
}

bool PowerUp::is_out_of_game() const noexcept
{
    return (x + Settings::BERRIE_WIDTH) < -Settings::LOG_WIDTH;
}

void PowerUp::update(float dt) noexcept
{
    x += -Settings::BACK_SCROLL_SPEED * dt;
}

void PowerUp::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}
