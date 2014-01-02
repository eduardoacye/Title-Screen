#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Enemy.hpp"
#include "Crosshair.hpp"
#include "DamageSound.hpp"
#include "HitSound.hpp"
#include "ShotSound.hpp"

class GameScreen : virtual public State
{
    friend class Game;
protected:
    std::vector<Enemy> enemies;
    sf::Vector2i mousePosition;

    int lives;
    float delay;
    bool succesfulHit;

    sf::RectangleShape background;
    sf::RectangleShape effect;
    int effectDecay;

    Crosshair crosshair;
    DamageSound damageSound;
    ShotSound shotSound;
    HitSound hitSound;
    sf::Music music;

    sf::Font font;
    sf::Text scoreString;
    sf::Text livesString;
    sf::RectangleShape scoreBackground;
    sf::RectangleShape livesBackground;

protected:
    void processEvent(sf::Event &);
    void update(sf::Time);
    void render(sf::RenderWindow &);
    fsm::Q goTo() const;

    void itemSelected();

public:
    GameScreen(fsm::Q, std::string);
    void clear();
};

#endif // GAMESCREEN_HPP
