#include "tBoom.h"

tBoom::tBoom(float _Width, float _Height) {
    Width = _Width;
    Height = _Height;
    LoadImage( "resources/images/Boom.png");
}
tBoom::~tBoom() = default;

