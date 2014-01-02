#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Master.hpp"
#include "TitleScreen.hpp"
#include "InstructionsScreen.hpp"
#include "GameScreen.hpp"
#include "GameOverScreen.hpp"

class Game
{
    friend class State;
public:                         // Functions
    Game();
    ~Game();
    void run();

private:                        // Functions

    void processEvents();

private:                        // Attributes
    sf::RenderWindow window;
    State ** states;
    fsm::Q currentState;
    State * state;
};


#endif // GAME_HPP
