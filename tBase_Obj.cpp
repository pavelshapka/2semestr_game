#include "tBase_Obj.h"

void tBase_Obj::LoadImage(const std::string& img_filename) {
    SomeTexture.loadFromFile(img_filename);
}

void tBase_Obj::Draw(sf::RenderWindow *Window) {
    sf::Sprite SpriteStuff;
    SpriteStuff.setTexture(SomeTexture);
    SpriteStuff.setPosition(X, Y);
    float WidgetWidth = (float)Width / (float)SomeTexture.getSize().x;
    float WidgetHeight = (float)Height / (float)SomeTexture.getSize().y;
    SpriteStuff.setScale(WidgetWidth, WidgetHeight);
    Window->draw(SpriteStuff);
}