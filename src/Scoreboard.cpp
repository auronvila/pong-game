//
// Created by Auron Vila on 2.04.2025.
//

#include <SFML/Graphics.hpp>

#include "Scoreboard.h"
#include<iostream>

Scoreboard::Scoreboard(float screenWidth) {
    if (!m_font.openFromFile("assets/fonts/Roboto/static/Roboto-Regular.ttf")) {
        std::cerr << "Font loading failed. Exiting..." << std::endl;
        std::exit(EXIT_FAILURE); // force exit if font fails to load
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

void Scoreboard::setPosition(float screenWidth) const {
    m_playerOneScore->setPosition({screenWidth * 0.75f, 50});
    m_aiScore->setPosition({screenWidth * 0.25f, 50});
}
