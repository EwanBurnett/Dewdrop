#ifndef __DEWDROP_MATH_CONSTANTS_H
#define __DEWDROP_MATH_CONSTANTS_H

#include <limits>

namespace Math {
    constexpr double Pi = 3.1415926535897932385;
    constexpr float Float_Max = std::numeric_limits<float>::max();
    constexpr float Float_Min = std::numeric_limits<float>::min();
    
    constexpr int Int_Max = std::numeric_limits<int>::max();
    constexpr int Int_Min = std::numeric_limits<int>::min();

    constexpr float Infinity = std::numeric_limits<float>::infinity();
    constexpr float Epsilon = FLT_EPSILON;

    constexpr float Deg2Rad = Pi / 180.0f;
    constexpr float Rad2Deg = 180.0f / Pi;
    
}

#endif