#ifndef HITSOUND_HPP
#define HITSOUND_HPP

#include <SFML/Audio.hpp>

class HitSound
{
    friend class GameScreen;
public:
    HitSound();
private:
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
};
#endif // HITSOUND_HPP
