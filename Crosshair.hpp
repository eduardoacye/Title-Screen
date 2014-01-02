#ifndef CROSSHAIR_HPP
#define CROSSHAIR_HPP

#include <SFML/Graphics.hpp>

class Crosshair
{
    friend class GameScreen;
public:                         // Functions
    Crosshair();
    void update(float sec);
private:                        // Attributes
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // CROSSHAIR_HPP
