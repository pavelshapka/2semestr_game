#ifndef INC_2SEMESTR_TAPPLICATION_H
#define INC_2SEMESTR_TAPPLICATION_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include "tMap.h"
#include "tObject.h"
#include "tDanger.h"
#include "Constants.h"
#include "tBoom.h"
#include "tLives.h"
#include "tEnd.h"

class tApplication {
protected:
    sf::RenderWindow* Window;
    tMap *Map;
    tObject *Object;
    std::vector<tDanger*> Danger;
    tBoom *Boom;
    std::vector<tLives*> Lives;
    tEnd *End;

public:
    tApplication();
    ~tApplication();
    void Init();
    void Run();
};

#endif
