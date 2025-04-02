//
// Created by Auron Vila on 1.04.2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

#include "Ball.h"


class Player {
    sf::RectangleShape shape;

public:
    Player(sf::Vector2f position, sf::Color color);

    ~Player();

    void move(float dy, sf::Vector2f arena_size, sf::Vector2f arena_position);

    void draw(sf::RenderWindow &window);

    sf::FloatRect getGlobalBounds() const;

    sf::RectangleShape &getShape();

    void customAiMovement(const Ball& ball, sf::RectangleShape& arena);
};

#endif //PLAYER_H
