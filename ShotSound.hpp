#ifndef SHOTSOUND_HPP
#define SHOTSOUND_HPP

#include <SFML/Audio.hpp>

class ShotSound
{
    friend class GameScreen;
public:
    ShotSound();
private:
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
};

#endif // SHOTSOUND_HPP
