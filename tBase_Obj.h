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
    tBase_Obj();
    ~tBase_Obj();
    void LoadImage(const std::string& img_filename);
    void Draw(sf::RenderWindow *Window);
    float get_X();
    float get_Y();
    float get_Width();
    float get_Height();
    void set_Position(float c_X, float c_Y);
};


#endif //INC_2SEMESTR_TBASE_OBJ_H
