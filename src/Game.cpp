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
    srand(time(0));
    initWindow();

    // * game loop
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        switch (gameState) {
            case GameState::START_MENU:
                updateStartMenuTextPos();
                handleStartMenuKeyPress();
                renderStartMenu();
                break;
            case GameState::PLAYING:
                if (gameAdjusted) {
                    initGame();
                    gameAdjusted = false;
                }
                handleInput();
                handleAiPlayerMovement();
                update();
                handleEvents();
                renderGame();
                break;
            case GameState::PAUSED:
                break;
            case GameState::GAME_OVER:
                break;
        }
    }
}

void Game::initWindow() {
    window.create(sf::VideoMode({1920u, 1080u}), "Pong Game");
    window.setFramerateLimit(144);
}

void Game::initGame() {
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
    gameClock.start();
    const float elapsedTime = gameClock.getElapsedTime().asSeconds();
    const float speedMultiplier = 1.0f + (elapsedTime / SPEED_SCALE_INTERVAL);

    float currentBallSpeed = BASE_BALL_SPEED * speedMultiplier;

    ball.moveBall(arena, *scoreboard, currentBallSpeed, gameClock);
}

void Game::renderGame() {
    window.clear();
    window.draw(arena);
    playerOne.draw(window);
    aiPlayer.draw(window);
    ball.draw(window);
    scoreboard->drawText(window);
    window.display();
}

void Game::updateStartMenuTextPos() const {
    startMenu.setTextPosition(window.getSize().x, window.getSize().y);
}

void Game::handleStartMenuKeyPress() {
    if (isKeyPressed(sf::Keyboard::Key::Enter)) {
        gameState = GameState::PLAYING;
        gameAdjusted = true;
    }
}

void Game::renderStartMenu() {
    window.clear();
    startMenu.renderStartMenu(window);
    window.display();
}

void Game::handleAiPlayerMovement() {
    aiPlayer.customAiMovement(ball, arena);
}
