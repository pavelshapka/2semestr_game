#ifndef INC_2SEMESTR_TAPPLICATION_H
#define INC_2SEMESTR_TAPPLICATION_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <chrono>
#include "tMap.h"
#include "tObject.h"

class tApplication {
protected:
    sf::RenderWindow* Window;
    tMap *Map;
    tObject *Object;

public:
    tApplication();
    ~tApplication();
    void Init();
    void Run();
};


#endif
