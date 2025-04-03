//
// Created by Auron Vila on 3.04.2025.
//

#include "StartMenu.h"

StartMenu::StartMenu() {
    if (!m_font.openFromFile("assets/fonts/Roboto/static/Roboto-Regular.ttf")) {
        std::cerr << "Font loading failed. Exiting..." << std::endl;
        std::exit(EXIT_FAILURE);
    }


    m_game_title_text = std::make_unique<sf::Text>(m_font, "Pong", 80);
    m_start_game_text = std::make_unique<sf::Text>(m_font, "Press Enter Key To Start", 36);

    m_game_title_text->setFillColor(sf::Color(100, 250, 50));
    m_game_title_text->setStyle(sf::Text::Bold);

    m_start_game_text->setFillColor(sf::Color(180, 180, 180));
    m_start_game_text->setStyle(sf::Text::Italic);
}

void StartMenu::renderStartMenu(sf::RenderWindow &window) const {
    window.draw(*m_game_title_text);
    window.draw(*m_start_game_text);
}

void StartMenu::setTextPosition(float screenWidth, float screenHeight) const {
    sf::FloatRect titleBounds = m_game_title_text->getLocalBounds();
    m_game_title_text->setOrigin({titleBounds.size.x / 2.0f, titleBounds.size.y / 2.0f});
    m_game_title_text->setPosition({screenWidth / 2.0f, screenHeight / 3.0f});

    sf::FloatRect startBounds = m_start_game_text->getLocalBounds();
    m_start_game_text->setOrigin({startBounds.size.x / 2.0f, startBounds.size.y / 2.0f});
    m_start_game_text->setPosition({screenWidth / 2.0f, screenHeight / 2.0f + 100.0f});
}
