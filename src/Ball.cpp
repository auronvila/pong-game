//
// Created by Auron Vila on 2.04.2025.
//

#include "Ball.h"
#include"Consts.h"
#include<iostream>

void Ball::MoveBall(const sf::RectangleShape &arena) {
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

    if (ball_right > arena_right || ball_left < arena_left) {
        velocity.x = -velocity.x;
        std::cout << "scoreddd" << std::endl;

        // todo reset the game and update the score
        float initial_ball_pos_x = arena.getPosition().x + (ARENA_WIDTH / 2) - BALL_RADIUS;
        float initial_ball_pos_y = arena.getPosition().y + (ARENA_HEIGHT / 2) - BALL_RADIUS;
        shape.setPosition({initial_ball_pos_x, initial_ball_pos_y});
        InitialVelocity();
    }
}

void Ball::InitialVelocity() {
    float randomNum = rand() % 2;

    if (randomNum == 0) {
        velocity = {10.0f, 5.0f};
    } else {
        velocity = {-10.0f, 5.0f};
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
