#include "tMap.h"
#include <iostream>

tMap::tMap(int _X, int _Y, int _Width, int _Height) {
    X = _X;
    Y = _Y;
    Width = _Width;
    Height = _Height;
    std::string path = std::filesystem::current_path();
    // Загрузка картинки
    std::cout << path + "/resources/images/grass.jpg" << std::endl;
    SomeTexture.loadFromFile(path + "/resources/images/grass.jpg");
}

tMap::~tMap() = default;

void tMap::Draw(sf::RenderWindow *Window) {
    sf::Sprite SpriteStuff;
    SpriteStuff.setTexture(SomeTexture);
    SpriteStuff.setPosition(X, Y);
    // Масштабирование изображения на все окно
    float WidgetWight = float(Width)/float(SomeTexture.getSize().x);
    float WidgetHeight = float(Height)/float(SomeTexture.getSize().y);
    SpriteStuff.setScale(WidgetWight, WidgetHeight);

    Window->draw(SpriteStuff);

}