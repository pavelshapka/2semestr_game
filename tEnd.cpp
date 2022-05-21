#include "tEnd.h"

tEnd::tEnd() {
    Width = END_SIZE;
    Height = END_SIZE;
    X = SCREEN_WIDTH/2 - Width/2;
    Y = SCREEN_HEIGHT/2 - Height/2;
    LoadImage(PATH + "/resources/images/EndGame.png");
}

tEnd::~tEnd() = default;
