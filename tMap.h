#ifndef INC_2SEMESTR_TMAP_H
#define INC_2SEMESTR_TMAP_H

#include "SFML/Graphics.hpp"
#include <filesystem>

class tMap {
protected:
    int X, Y, Width, Height;
    sf::Texture SomeTexture;

public:
    tMap(int _X, int _Y, int _Width, int _Height);
    ~tMap();
    void Draw(sf::RenderWindow *Window);
};


#endif //INC_2SEMESTR_TMAP_H
