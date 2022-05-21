#include "tObject.h"

tObject::tObject(float _X, float _Y, float _Width, float _Height) {
    X = _X;
    Y = _Y;
    Width = _Width;
    Height = _Height;
    // Загрузка картинки
    SomeTexture.loadFromFile(PATH + "/resources/images/orb.png");
}

tObject::~tObject() = default;

void tObject::Move(float dX, float dY) {
    X += dX;
    Y += dY;
    // Проверка на нахождение в окне
    if (X + Width > SCREEN_WIDTH)
        X = SCREEN_WIDTH - Width;
    else if (X < 0)
        X = 0;
    if (Y + Height > SCREEN_HEIGHT)
        Y = SCREEN_HEIGHT - Height;
    else if (Y < 0)
        Y = 0;
}
