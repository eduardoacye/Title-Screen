#include "DamageSound.hpp"

DamageSound::DamageSound()
{
    hitSoundBuffer.loadFromFile("res/damage.wav");
    hitSound.setBuffer(hitSoundBuffer);
    hitSound.setVolume(200);
}
