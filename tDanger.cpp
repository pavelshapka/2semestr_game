#include "tDanger.h"
#include "Constants.h"

tDanger::tDanger(int _type) {
    std::string img_filename;
    X = -1000;
    Y = -1000;
    switch (_type) {
        case 0:
            img_filename = PATH + "/resources/images/Stone1.png";
            break;
        case 1:
            img_filename = PATH + "/resources/images/Stone2.png";
            break;
        case 2:
            img_filename = PATH + "/resources/images/Stone3.png";
            break;
        case 3:
            img_filename = PATH + "/resources/images/Stone4.png";
            break;
        default:
            img_filename = PATH + "/resources/images/Stone5.png";
            break;
    }
    LoadImage(img_filename);
}

tDanger::~tDanger()  = default;

void tDanger::Move() {
    X -= Speed;
}

bool tDanger::IsOut() {
    return X + Width <  0;
}

void tDanger::Run(float _speed) {
    Speed = rand_uns(BASE_SPEED + _speed, BASE_SPEED + _speed*1.3);
    X = SCREEN_WIDTH;
    Y = rand_uns(0, SCREEN_HEIGHT - Height);
    Width = rand_uns(50, 200);
    Height = Width;

}

bool tDanger::IsCollisison(float _X, float _Y, float _Width, float _Height) {
    float R_ou = sqrt(pow(X + Width/2 - (_X + _Width/2), 2) + pow(Y + Height/2 - (_Y + _Width/2), 2));
    if (R_ou <= (Width/2 + _Width/2)*0.7)
        return true;
    return false;
}
