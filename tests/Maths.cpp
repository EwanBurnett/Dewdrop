#include <gtest/gtest.h>
#include <Dewdrop/Maths.h>

//TODO: Write tests for Maths library functions

using namespace Dewdrop::Math;
//VECTOR

TEST(Dewdrop_Maths_Vector, Constructor) {

    //Constructing from Arbitrary types
    {
        Vector2f float2(1.5, 1);    //Should implicitly convert to floating-point types. 
        EXPECT_FLOAT_EQ(float2.xy.x, 1.5f);
        EXPECT_FLOAT_EQ(float2.xy.y, 1.0f);
    }


}
