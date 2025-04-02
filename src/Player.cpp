//
// Created by Auron Vila on 1.04.2025.
//

#include "Player.h"
#include "Consts.h"


Player::Player(sf::Vector2f position, sf::Color color) {
    shape.setSize({PLAYER_WIDTH, PLAYER_HEIGHT});
    shape.setPosition(position);
    shape.setFillColor(color);
}

Player::~Player() {
}

void Player::move(float dy, sf::Vector2f arena_size, sf::Vector2f arena_position) {
    float top_limit = arena_position.y;
    float bottom_limit = arena_position.y + arena_size.y;
    float futureTopPos = shape.getPosition().y + dy;
    float futureBottomPos = shape.getPosition().y + PLAYER_HEIGHT + dy;
    sf::Vector2<float> movePos = {0.f, dy};
    if (futureTopPos >= top_limit && futureBottomPos <= bottom_limit) {
        shape.move(movePos);
    }
}


void Player::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

sf::FloatRect Player::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

sf::RectangleShape &Player::getShape() {
    return shape;
}

void Player::customAiMovement(const Ball &ball, sf::RectangleShape &arena) {
    float ball_y_pos = ball.getYPos();
    float ai_paddle_pos_y = shape.getPosition().y;

    if (ball_y_pos > ai_paddle_pos_y) {
        shape.move({0, 2.0f});
    } else {
        shape.move({0, -2.0f});
    }
}
