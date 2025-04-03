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

    void moveBall(const sf::RectangleShape &arena, Scoreboard &scoreboard, float &currentBallSpeed, sf::Clock &gameClock);

    void initialVelocity();

    sf::Vector2f normalize(const sf::Vector2f &v);

    sf::Vector2f getInitialVelocity();

    void detectCollisionWithPaddle(sf::RectangleShape &paddle);

    float getYPos() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    float speed;

    void resetGame(float initialBallPosX, float initialBallPosY, sf::Clock &gameClock);
};



#endif //BALL_H
