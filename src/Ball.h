//
// Created by Auron Vila on 2.04.2025.
//

#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

#include "Scoreboard.h"

class Ball {
public:
    Ball(sf::Vector2<float> position, sf::Color color);

    ~Ball();

    void draw(sf::RenderWindow &window);

    void moveBall(const sf::RectangleShape &arena,Scoreboard& scoreboard);

    void initialVelocity();

    void detectCollisionWithPaddle(sf::RectangleShape &paddle);

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;

    void resetGame(float initialBallPosX, float initialBallPosY);
};


#endif //BALL_H
