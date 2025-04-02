//
// Created by Auron Vila on 2.04.2025.
//

#include <SFML/Graphics.hpp>

#include "Scoreboard.h"
#include<iostream>

Scoreboard::Scoreboard(const float &screenWidth) {
    if (!m_font.openFromFile("assets/fonts/Roboto/static/Roboto-Regular.ttf")) {
        std::cout << "Error while loading the font!!";
    }


    m_playerOneScore = std::make_unique<sf::Text>(m_font, "0", 40);
    m_aiScore = std::make_unique<sf::Text>(m_font, "0", 40);

    m_playerOneScore->setFillColor(sf::Color::White);
    m_aiScore->setFillColor(sf::Color::White);

    float playerOneTextPos = screenWidth / 2;
    m_playerOneScore->setPosition({playerOneTextPos + 100, 100});
    m_aiScore->setPosition({playerOneTextPos - 100, 100});
}


Scoreboard::~Scoreboard() {
}

sf::Text &Scoreboard::getPlayerOneScore() const {
    return *m_playerOneScore;
}

sf::Text &Scoreboard::getAiScore() const {
    return *m_aiScore;
}

void Scoreboard::updatePlayerOneScore(const int score) {
    m_playerOneScore->setString(std::to_string(score));
}

void Scoreboard::updateAiScore(int score) {
    m_aiScore->setString(std::to_string(score));
}
