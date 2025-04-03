//
// Created by Auron Vila on 2.04.2025.
//

#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Arena.h"
#include "Ball.h"
#include "Player.h"
#include"Consts.h"
#include "Scoreboard.h"
#include"StartMenu.h"

enum class GameState {
    START_MENU = 0,
    PAUSED = 1,
    PLAYING = 2,
    GAME_OVER = 3,
};


class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    sf::RectangleShape arena;
    Ball ball;
    Player playerOne;
    Player aiPlayer;
    std::unique_ptr<Scoreboard> scoreboard;
    sf::Clock gameClock;
    GameState gameState = GameState::START_MENU;
    StartMenu startMenu;
    bool gameAdjusted = false;


    void updateStartMenuTextPos() const;
    void handleStartMenuKeyPress();
    void initWindow();
    void initGame();
    void handleInput();
    void handleAiPlayerMovement();
    void update();
    void handleEvents();
    void renderGame();
    void renderStartMenu();
};





#endif //GAME_H
