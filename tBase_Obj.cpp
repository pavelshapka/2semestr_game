#include "tBase_Obj.h"

tBase_Obj::tBase_Obj() = default;
tBase_Obj::~tBase_Obj() = default;

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

float tBase_Obj::get_X() {
    return X;
}

float tBase_Obj::get_Y() {
    return Y;
}

float tBase_Obj::get_Width() {
    return Width;
}

float tBase_Obj::get_Height() {
    return Height;
}

void tBase_Obj::set_Position(float c_X, float c_Y) {
    X = c_X - Width/2;
    Y = c_Y - Height/2;
}