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

    void init();
    void handleInput();
    void handleAiPlayerMovement();
    void update();
    void handleEvents();
    void render();
};





#endif //GAME_H
