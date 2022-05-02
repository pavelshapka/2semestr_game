#include "tObject.h"
#include <math.h>

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

void tObject::Draw(sf::RenderWindow *Window) {
    sf::Sprite SpriteStuff;
    SpriteStuff.setTexture(SomeTexture);
    SpriteStuff.setPosition(X, Y);
    // Масштабирование объекта
    float WidgetWight = float(Width)/float(SomeTexture.getSize().x);
    float WidgetHeight = float(Height)/float(SomeTexture.getSize().y);
    SpriteStuff.setScale(WidgetWight, WidgetHeight);

    Window->draw(SpriteStuff);
}

bool tObject::Contains(int _X, int _Y) {
    int center_x = X + Width/2;
    int center_y = Y + Height/2;
    // Проверка на столкновение (ищем расстояние от точки до центра)
    return sqrt(pow(_X - center_x, 2) + pow(_Y - center_y, 2)) ? true : false;
}

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