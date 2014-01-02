#ifndef DAMAGESOUND_HPP
#define DAMAGESOUND_HPP

#include <SFML/Audio.hpp>

class DamageSound
{
    friend class GameScreen;

public:
    DamageSound();
private:
    sf::SoundBuffer hitSoundBuffer;
    sf::Sound hitSound;
};


#endif // DAMAGESOUND_HPP
