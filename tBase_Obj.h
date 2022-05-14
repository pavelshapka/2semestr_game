#ifndef INC_2SEMESTR_TBASE_OBJ_H
#define INC_2SEMESTR_TBASE_OBJ_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class tBase_Obj {
protected:
    float X, Y, Width, Height;
    sf::Texture SomeTexture;

public:
    void LoadImage(const std::string& img_filename);
    void Draw(sf::RenderWindow *Window);
};


#endif //INC_2SEMESTR_TBASE_OBJ_H
