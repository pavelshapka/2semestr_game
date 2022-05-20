#ifndef INC_2SEMESTR_TOBJECT_H
#define INC_2SEMESTR_TOBJECT_H
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <cmath>
#include "tBase_Obj.h"


class tObject : virtual public tBase_Obj {

public:
    tObject(int _X, int _Y, int _Width, int _Height);
    ~tObject();
    void Move(int dX, int dY);
};


#endif //INC_2SEMESTR_TOBJECT_H
