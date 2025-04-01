//
// Created by Auron Vila on 1.04.2025.
//
#include"Consts.h"

sf::RectangleShape CreateArena(sf::Vector2u windowSize) {
    sf::Vector2f arenaSize(ARENA_WIDTH, ARENA_HEIGHT);

    sf::Vector2f arenaPos(
        (windowSize.x - arenaSize.x) / 2.f,
        (windowSize.y - arenaSize.y) / 2.f
    );

    sf::RectangleShape arena;
    arena.setSize(arenaSize);
    arena.setPosition(arenaPos);
    arena.setOutlineThickness(2.0f);
    arena.setOutlineColor(sf::Color(100, 100, 100));
    arena.setFillColor(sf::Color::Transparent);

    return arena;
}
