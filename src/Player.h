//
// Created by Auron Vila on 1.04.2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>


class Player {
    sf::RectangleShape shape;

public:
    Player(sf::Vector2f position, sf::Color color);

    ~Player();

    void move(float dy, sf::Vector2f arena_size, sf::Vector2f arena_position);

    void draw(sf::RenderWindow &window);

    sf::FloatRect getBounds() const;
};

#endif //PLAYER_H
