#ifndef INSTRUCTIONSSCREEN_HPP
#define INSTRUCTIONSSCREEN_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.hpp"

class InstructionsScreen : virtual public State
{
    friend class Game;
protected:
    sf::Font font;

    sf::Text title;
    sf::Text instructions;
    sf::Text back;

    sf::RectangleShape background;
    sf::RectangleShape selection;

protected:                        // Functions
    void processEvent(sf::Event &);
    void update(sf::Time);
    void render(sf::RenderWindow &);
    fsm::Q goTo() const;

    void itemSelected();

public:
    InstructionsScreen(fsm::Q, std::string);
};

#endif // INSTRUCTIONSSCREEN_HPP
