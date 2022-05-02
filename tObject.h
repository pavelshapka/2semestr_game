#ifndef INC_2SEMESTR_TOBJECT_H
#define INC_2SEMESTR_TOBJECT_H
#include <SFML/Graphics.hpp>
#include <filesystem>


class tObject {
protected:
    int X, Y, Width, Height;
    sf::Texture SomeTexture;

public:
    tObject(int _X, int _Y, int _Width, int _Height);
    ~tObject();
    void Draw(sf::RenderWindow *Window);
    bool Contains(int _X, int _Y);
    void Move(int dX, int dY);
};


#endif //INC_2SEMESTR_TOBJECT_H
