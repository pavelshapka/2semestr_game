#ifndef INC_2SEMESTR_TDANGER_H
#define INC_2SEMESTR_TDANGER_H

#include "tBase_Obj.h"
#include "functions.h"

class tDanger : virtual public tBase_Obj {
private:
    float Speed;
public:
    tDanger(int _type);
    ~tDanger();
    void Move();
    bool IsOut();
    void Run();
};


#endif //INC_2SEMESTR_TDANGER_H
