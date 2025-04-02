#include <SFML/Graphics.hpp>
#include "Arena.h"
#include "Ball.h"
#include "Player.h"
#include"Consts.h"

int main() {
    srand(time(0));
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Pong Game");
    window.setFramerateLimit(144);

    sf::Vector2u windowSize = window.getSize();
    const float screenWidth = static_cast<float>(windowSize.x);
    const float screenHeight = static_cast<float>(windowSize.y);


    sf::Color player_color = sf::Color{100, 250, 0};

    sf::Vector2f player_pos(
        screenWidth - PLAYER_WIDTH - 200.0f,
        (screenHeight - PLAYER_HEIGHT) / 2.0f
    );

    Player playerOne = Player(player_pos, player_color);
    const sf::RectangleShape arena = CreateArena(window.getSize());

    float ballPosX = arena.getPosition().x + (ARENA_WIDTH / 2) - BALL_RADIUS;
    float ballPosY = arena.getPosition().y + (ARENA_HEIGHT / 2) - BALL_RADIUS;
    Ball ball = Ball({ballPosX, ballPosY}, {255, 255, 255});
    ball.initialVelocity();

    // * game loop
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }


        if (isKeyPressed(sf::Keyboard::Key::Up)) {
            playerOne.move(-2.0f, arena.getSize(), arena.getPosition());
        } else if (isKeyPressed(sf::Keyboard::Key::Down)) {
            playerOne.move(2.0f, arena.getSize(), arena.getPosition());
        }

        window.clear();
        // ? draw elements here
        window.draw(arena);
        ball.draw(window);
        playerOne.draw(window);
        ball.detectCollisionWithPaddle(playerOne.getShape());
        ball.moveBall(arena);


        window.display();
    }
}
