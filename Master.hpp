#ifndef MASTER_HPP
#define MASTER_HPP

//#include <QDebug>
#include <SFML/System.hpp>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <string>

namespace fsm{
    enum Q {TitleScreen, GameLoop, Instructions, GameOver, Empty};
};
class State;
class Game;
static int sizeX = sf::VideoMode::getDesktopMode().width;
static int sizeY = sf::VideoMode::getDesktopMode().height;
static sf::Clock masterClock;
extern int score;
extern int record;

static std::string to_string(int number)
{
    std::ostringstream ss;
    ss << number;
    return ss.str();
}

#endif // MASTER_HPP
