#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "Master.hpp"

class Enemy : public sf::CircleShape
{
public:
    Enemy();

    // Métodos
    bool isClicked(sf::Vector2i mousePosition);
    void move(float x);

    // Atributos
    float velocity;
    float swing;
    bool isDead;
};

#endif // ENEMY_HPP
