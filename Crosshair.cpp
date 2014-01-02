#include "Crosshair.hpp"

Crosshair::Crosshair()
{
    texture.loadFromFile("res/crosshair.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,50,50)); // The dimensions of crosshair.png are 50x50
    sprite.setOrigin(sprite.getTextureRect().width/2.f,
                     sprite.getTextureRect().height/2.f);
}
void Crosshair::update(float sec)
{
}
