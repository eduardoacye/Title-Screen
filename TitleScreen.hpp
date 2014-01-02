#ifndef TITLESCREEN_HPP
#define TITLESCREEN_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.hpp"

class TitleScreen : virtual public State
{
    friend class Game;
protected:                        // Attributes

    sf::Font font;

    sf::Text title;
    sf::Text startGame;
    sf::Text instructions;
    sf::Text exitGame;

    sf::RectangleShape background;
    sf::RectangleShape selection;


    int selectionId;

protected:                        // Functions
    void processEvent(sf::Event &);
    void update(sf::Time);
    void render(sf::RenderWindow &);
    fsm::Q goTo() const;

    void itemSelected();

public:                         // Functions
    TitleScreen(fsm::Q, std::string);
};

#endif // TITLESCREEN_HPP
