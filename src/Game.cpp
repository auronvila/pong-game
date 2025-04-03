//
// Created by Auron Vila on 2.04.2025.
//
#include"Game.h"

Game::Game()
    : ball({0.f, 0.f}, sf::Color::White),
      playerOne({0.f, 0.f}, sf::Color::Green),
      aiPlayer({0.f, 0.f}, sf::Color::Green) {
}


void Game::run() {
    init();

    // * game loop
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        handleInput();
        handleAiPlayerMovement();
        update();
        handleEvents();
        render();
    }
}


void Game::init() {
    srand(time(0));
    gameClock.start();

    window.create(sf::VideoMode({1920u, 1080u}), "Pong Game");
    window.setFramerateLimit(144);

    arena = CreateArena(window.getSize());

    const float screenWidth = static_cast<float>(window.getSize().x);
    const float screenHeight = static_cast<float>(window.getSize().y);

    sf::Color green = sf::Color{100, 250, 0};

    playerOne = Player(
        {screenWidth - PLAYER_WIDTH - PLAYER_MARGIN, (screenHeight - PLAYER_HEIGHT) / 2},
        green
    );

    aiPlayer = Player(
        {PLAYER_MARGIN, (screenHeight - PLAYER_HEIGHT) / 2},
        green
    );

    float ballX = arena.getPosition().x + (ARENA_WIDTH / 2) - BALL_RADIUS;
    float ballY = arena.getPosition().y + (ARENA_HEIGHT / 2) - BALL_RADIUS;
    ball = Ball({ballX, ballY}, sf::Color::White);
    ball.initialVelocity();

    scoreboard = std::make_unique<Scoreboard>(screenWidth);
}


void Game::handleEvents() {
    ball.detectCollisionWithPaddle(playerOne.getShape());
    ball.detectCollisionWithPaddle(aiPlayer.getShape());
}

void Game::handleInput() {
    const float elapsedTime = gameClock.getElapsedTime().asSeconds();

    const float speedMultiplier = 1.0f + (elapsedTime / SPEED_SCALE_INTERVAL);
    const float currentPlayerSpeed = BASE_PLAYER_SPEED * speedMultiplier;

    if (isKeyPressed(sf::Keyboard::Key::Up)) {
        playerOne.move(-currentPlayerSpeed, arena.getSize(), arena.getPosition());
    } else if (isKeyPressed(sf::Keyboard::Key::Down)) {
        playerOne.move(currentPlayerSpeed, arena.getSize(), arena.getPosition());
    }
}

void Game::update() {
    const float elapsedTime = gameClock.getElapsedTime().asSeconds();
    const float speedMultiplier = 1.0f + (elapsedTime / SPEED_SCALE_INTERVAL);

    float currentBallSpeed = BASE_BALL_SPEED * speedMultiplier;

    ball.moveBall(arena, *scoreboard, currentBallSpeed, gameClock);
}

void Game::render() {
    window.clear();
    window.draw(arena);
    playerOne.draw(window);
    aiPlayer.draw(window);
    ball.draw(window);
    scoreboard->drawText(window);
    window.display();
}

void Game::handleAiPlayerMovement() {
    aiPlayer.customAiMovement(ball, arena);
}
