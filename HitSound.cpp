#include "HitSound.hpp"

HitSound::HitSound()
{
    soundBuffer.loadFromFile("res/hit.wav");
    sound.setBuffer(soundBuffer);
}
