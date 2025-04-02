//
// Created by Auron Vila on 2.04.2025.
//

#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;

public:
    Ball(sf::Vector2<float> position, sf::Color color);

    ~Ball();

    void draw(sf::RenderWindow &window);

    void MoveBall();

    void InitialVelocity();
};

#endif //BALL_H
