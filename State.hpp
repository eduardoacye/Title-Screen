#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Master.hpp"

class State
{
    friend class Game;

protected:                    // Attributes
    fsm::Q type;
    fsm::Q goToState;
    std::string description;


protected:                    // Functions
    virtual void processEvent(sf::Event &) = 0;
    virtual void update(sf::Time dt) = 0;
    virtual void render(sf::RenderWindow &) = 0;
    virtual fsm::Q goTo() const = 0;

public:                     // Functions
    State(fsm::Q, std::string);
    friend std::ostream & operator << (std::ostream &, const State &);

};

#endif // STATE_HPP
