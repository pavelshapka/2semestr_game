#include "tLives.h"

tLives::tLives(float _X, float _Y, float _Width, float _Height) {
    X = _X;
    Y = _Y;
    Width = _Width;
    Height = _Height;
    LoadImage("resources/images/Live.png");
}

tLives::~tLives() = default;