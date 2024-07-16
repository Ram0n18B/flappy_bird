#pragma once

#include <src/Bird.hpp>
#include <src/World.hpp>
#include <src/strategies/BaseStrategy.hpp>

class HardMode : public BaseStrategy
{
public:
    HardMode(StateMachine* sm, std::shared_ptr<World> _world = nullptr, std::shared_ptr<Bird> _bird = nullptr) noexcept;

    void handle_inputs(const sf::Event& event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

    void spawn_logs(float& logs_spawn_timer, std::mt19937& rng, float& last_log_y, std::list<std::shared_ptr<LogPair>>& logs, Factory<LogPair>& log_factory) noexcept override;

private:
    std::shared_ptr<Bird> bird;
    std::shared_ptr<World> world;
    int score{0};
};