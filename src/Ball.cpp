//
// Created by Auron Vila on 2.04.2025.
//

#include "Ball.h"
#include"Consts.h"
#include<iostream>

void Ball::moveBall(const sf::RectangleShape &arena, Scoreboard &scoreboard) {
    shape.move(velocity);

    sf::FloatRect ballBounds = shape.getGlobalBounds();
    const float arena_top = arena.getPosition().y;
    const float arena_bottom = arena.getPosition().y + arena.getSize().y;

    const float arena_left = arena.getPosition().x;
    const float arena_right = arena.getPosition().x + arena.getSize().x;

    const float ball_left = ballBounds.position.x;
    const float ball_right = ballBounds.position.x + ballBounds.size.x;

    const float ball_top = ballBounds.position.y;
    const float ball_bottom = ballBounds.position.y + ballBounds.size.y;


    if (ball_top <= arena_top || ball_bottom >= arena_bottom) {
        velocity.y = -velocity.y;
    }

    float initial_ball_pos_x = arena.getPosition().x + (ARENA_WIDTH / 2) - BALL_RADIUS;
    float initial_ball_pos_y = arena.getPosition().y + (ARENA_HEIGHT / 2) - BALL_RADIUS;

    // AI scores (left player)
    if (ball_right > arena_right) {
        velocity.x = -velocity.x;

        // todo update the score
        resetGame(initial_ball_pos_x, initial_ball_pos_y);
        sf::Text scoreStr = scoreboard.getAiScore();
        const int currentScore = std::stoi(scoreboard.getAiScore().getString().toAnsiString());
        scoreboard.updateAiScore(currentScore + 1);

        // Player scores (right player)
    } else if (ball_left < arena_left) {
        velocity.x = -velocity.x;
        const int currentScore = std::stoi(scoreboard.getPlayerOneScore().getString().toAnsiString());
        scoreboard.updatePlayerOneScore(currentScore + 1);
        resetGame(initial_ball_pos_x, initial_ball_pos_y);
    }
}

void Ball::initialVelocity() {
    float randomNum = rand() % 2;

    if (randomNum == 0) {
        velocity = {10.0f, 1.0f};
    } else {
        velocity = {-10.0f, 1.0f};
    }
}

void Ball::detectCollisionWithPaddle(sf::RectangleShape &paddle) {
    const float paddleTop = paddle.getPosition().y;
    const float paddleHeight = paddle.getSize().y;
    const float paddleCenterY = paddleTop + (paddleHeight / 2.f);

    const sf::FloatRect ballGlobalBound = shape.getGlobalBounds();
    const float ballCenterY = ballGlobalBound.position.y + (ballGlobalBound.size.y / 2.f);

    const float offset = ballCenterY - paddleCenterY;


    if (ballGlobalBound.findIntersection(paddle.getGlobalBounds())) {
        velocity.x = -velocity.x;
        velocity.y = offset * 0.05f;
    }
}

Ball::Ball(sf::Vector2<float> position, sf::Color color) {
    shape.setPosition(position);
    shape.setFillColor(color);
    shape.setRadius(BALL_RADIUS);

    // collision detection
}

Ball::~Ball() = default;

void Ball::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

void Ball::resetGame(float initialBallPosX, float initialBallPosY) {
    shape.setPosition({initialBallPosX, initialBallPosY});
    initialVelocity();
}
