#ifndef __MATH_MATRIX_H
#define __MATH_MATRIX_H

#include <memory>
#include <type_traits>

#include "Vector.h"

namespace Math {
    //Defines which ordering should be used within Matrix Multiplication. 
    //Has no effect on Matrix Memory Layout! 
    enum EMMultOrdering { Row = 0, Column = 1 }; 
    constexpr auto ORDERING = EMMultOrdering::Column;


    /**
     * \brief A 2 x 2 Matrix of floats
    */
    struct Matrix2x2 {
        Matrix2x2();

        union {
            float _matrix[4];
            float matrix[2][2];
        };

        Vector2f Row(uint8_t index) const;
        Vector2f Column(uint8_t index) const;

        Matrix2x2 operator + (const Matrix2x2& rhs);
        Matrix2x2 operator - (const Matrix2x2& rhs);
        Matrix2x2 operator ^ (const Matrix2x2& rhs);

        Matrix2x2 operator + (const float rhs);
        Matrix2x2 operator - (const float rhs);
        Matrix2x2 operator * (const float rhs);
        Matrix2x2 operator / (const float rhs);

        static Matrix2x2 Identity();
        static Matrix2x2 Transpose(const Matrix2x2& matrix);
        static float Determinant(const Matrix2x2& matrix);
        static Matrix2x2 Inverse(const Matrix2x2& matrix);

        static Matrix2x2 Rotation(const float rotation);
        static Matrix2x2 Scaling(const Vector2f& scaling);
        static Matrix2x2 UniformScaling(const float scaling);

        static Matrix2x2 MMult_M2x2_M2x2(const Matrix2x2& a, const Matrix2x2& b);
        static Matrix2x2 MMult_V2f_M2x2(const Vector2f& a, const Matrix2x2& b);
        static Matrix2x2 MMult_M2x2_V2f(const Matrix2x2& a, const Vector2f& b);
    };


    /**
     * \brief A 3 x 3 Matrix of floats
    */
    struct Matrix3x3 {
        Matrix3x3();

        union {
            float _matrix[9];
            float matrix[3][3];
        };

        Vector3f Row(uint8_t index) const;
        Vector3f Column(uint8_t index) const;

        Matrix3x3 operator + (const Matrix3x3& rhs);
        Matrix3x3 operator - (const Matrix3x3& rhs);
        Matrix3x3 operator ^ (const Matrix3x3& rhs);

        Matrix3x3 operator + (const float rhs);
        Matrix3x3 operator - (const float rhs);
        Matrix3x3 operator * (const float rhs);
        Matrix3x3 operator / (const float rhs);

        static Matrix3x3 Identity();
        static Matrix3x3 Transpose(const Matrix3x3& matrix);
        static float Determinant(const Matrix3x3& matrix);
        static Matrix3x3 Inverse(const Matrix3x3& matrix);

        static Matrix3x3 Translation(const Vector3f& translation);
        static Matrix3x3 Rotation(const Vector3f& rotation);
        static Matrix3x3 Scaling(const Vector3f& scaling);
        static Matrix3x3 UniformScaling(const float scaling);

        static Matrix3x3 MMult_M3x3_M3x3(const Matrix3x3& a, const Matrix3x3& b);
        static Matrix3x3 MMult_V3f_M3x3(const Vector3f& a, const Matrix3x3& b);
        static Matrix3x3 MMult_M3x3_V3f(const Matrix3x3& a, const Vector3f& b);
    };


    /**
     * \brief A 4 x 4 Matrix of floats
    */
    struct Matrix4x4 {
        Matrix4x4();

        union {
            float _matrix[16];
            float matrix[4][4];
        };

        Vector4f Row(uint8_t index) const;
        Vector4f Column(uint8_t index) const;

        Matrix4x4 operator + (const Matrix4x4& rhs);
        Matrix4x4 operator - (const Matrix4x4& rhs);
        Matrix4x4 operator ^ (const Matrix4x4& rhs);

        Matrix4x4 operator + (const float rhs);
        Matrix4x4 operator - (const float rhs);
        Matrix4x4 operator * (const float rhs);
        Matrix4x4 operator / (const float rhs);

        static Matrix4x4 Identity();
        static Matrix4x4 Transpose(const Matrix4x4& matrix);
        static Matrix4x4 Inverse(const Matrix4x4& matrix, bool& inverseExists);
        static float Determinant(const Matrix4x4& matrix);
        static Matrix4x4 Inverse(const Matrix4x4& matrix);

        static Matrix4x4 Translation(const Vector3f& translation);
        static Matrix4x4 Rotation(const Vector3f& rotation);
        static Matrix4x4 Scaling(const Vector3f& scaling);
        static Matrix4x4 UniformScaling(const float scaling);

        static Matrix4x4 Projection();
        static Matrix4x4 OrthographicProjection();

        static Matrix4x4 MMult_M4x4_M4x4(const Matrix4x4& a, const Matrix4x4& b);
        static Vector4f MMult_V4f_M4x4(const Vector4f& a, const Matrix4x4& b);
        static Matrix4x4 MMult_M4x4_V4f(const Matrix4x4& a, const Vector4f& b);
    };


}
#include "Matrix.inl"
#endif
