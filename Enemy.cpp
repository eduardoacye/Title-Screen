#include "Enemy.hpp"

Enemy::Enemy()
{
    setFillColor(sf::Color((rand()%256 + 255)/2, (rand()%256 + 255)/2, (rand()%256 + 255)/2));
    setPosition(rand()%sizeX-20 , -20);
    setRadius(10);
    velocity = 10.0/(rand()%11 + 30);
    swing = 10.0f/(rand()%50) * 100;
    isDead = false;
}

bool Enemy::isClicked(sf::Vector2i mousePosition){
    const sf::Vector2f position = getPosition();
    return (mousePosition.x >= position.x and mousePosition.x <= position.x + getRadius()*2 and
            mousePosition.y >= position.y and mousePosition.y <= position.y + getRadius()*2);
}

void Enemy::move(float x)
{
    setFillColor(sf::Color((rand()%256 + 255)/2, (rand()%256 + 255)/2, (rand()%256 + 255)/2));
    const sf::Vector2f position = getPosition();
    if(position.x < 0)
        setPosition(0, position.y + velocity);
    else if(position.x > sizeX)
        setPosition(sizeX, position.y + velocity);
    else
        //setPosition(position.x + sin(x) * velocity, position.y + velocity);
        setPosition(position.x + sin(x+swing) * velocity, position.y + velocity);
}
