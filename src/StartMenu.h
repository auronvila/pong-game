//
// Created by Auron Vila on 3.04.2025.
//

#ifndef STARTMENU_H
#define STARTMENU_H
#include <SFML/Graphics.hpp>
#include<iostream>

class StartMenu {
public:
    StartMenu();

    void renderStartMenu(sf::RenderWindow& window) const;
    void setTextPosition(float screenWidth, float screenHeight) const;

private:
    std::unique_ptr<sf::Text>m_game_title_text;
    std::unique_ptr<sf::Text>m_start_game_text;
    sf::Font m_font;

public:
};

#endif //STARTMENU_H
