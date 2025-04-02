//
// Created by Auron Vila on 2.04.2025.
//

#include "Ball.h"
#include"Consts.h"

void Ball::MoveBall() {
    shape.move(velocity);
}

void Ball::InitialVelocity() {
    float randomNum = rand() % 2;

    if (randomNum == 0) {
        velocity = {10.0f, 0.0f};
    } else {
        velocity = {-10.0f, 0.0f};
    }
}

Ball::Ball(sf::Vector2<float> position, sf::Color color) {
    shape.setPosition(position);
    shape.setFillColor(color);
    shape.setRadius(BALL_RADIUS);
}

Ball::~Ball() = default;

void Ball::draw(sf::RenderWindow &window) {
    window.draw(shape);
}
