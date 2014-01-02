#include "ShotSound.hpp"

ShotSound::ShotSound()
{
    soundBuffer.loadFromFile("res/shot.wav");
    sound.setBuffer(soundBuffer);
}
