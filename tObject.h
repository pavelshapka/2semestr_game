#ifndef INC_2SEMESTR_TOBJECT_H
#define INC_2SEMESTR_TOBJECT_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include "tBase_Obj.h"


class tObject : virtual public tBase_Obj {

public:
    tObject(float _X, float _Y, float _Width, float _Height);
    ~tObject();
    void Move(float dX, float dY);
};


#endif //INC_2SEMESTR_TOBJECT_H
