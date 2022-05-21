#include "tMap.h"
#include <iostream>

tMap::tMap() {
    X = 0;
    Y = 0;
    Width = SCREEN_WIDTH;
    Height = SCREEN_HEIGHT;
    // Загрузка картинки
    SomeTexture.loadFromFile(PATH + "/resources/images/grass.jpg");
}

tMap::~tMap() = default;
