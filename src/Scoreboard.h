//
// Created by Auron Vila on 2.04.2025.
//

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class Scoreboard {
public:
    Scoreboard(const float &screenWidth);

    ~Scoreboard();

    void drawText(sf::RenderWindow &window) {
        window.draw(*m_playerOneScore);
        window.draw(*m_aiScore);
    }

    sf::Text &getPlayerOneScore() const;

    sf::Text &getAiScore() const;

    void updatePlayerOneScore(int score);
    void updateAiScore(int score);

private:
    sf::Font m_font;
    std::unique_ptr<sf::Text> m_playerOneScore;
    std::unique_ptr<sf::Text> m_aiScore;
};

#endif //SCOREBOARD_H
