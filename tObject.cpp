#include "tObject.h"
#include <cmath>

tObject::tObject(int _X, int _Y, int _Width, int _Height) {
    X = _X;
    Y = _Y;
    Width = _Width;
    Height = _Height;
    std::string path = std::filesystem::current_path();
    // Загрузка картинки
    SomeTexture.loadFromFile(path + "/resources/images/orb.png");
}

tObject::~tObject() = default;

void tObject::Move(int dX, int dY) {
    X += dX;
    Y += dY;
    // Проверка на нахождение в окне
    if (X + Width > 1500)
        X = 1500 - Width;
    else if (X < 0)
        X = 0;
    if (Y + Height > 1500)
        Y = 1500 - Height;
    else if (Y < 0)
        Y = 0;
}
