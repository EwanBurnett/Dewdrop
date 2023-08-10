#include "../include/Dewdrop/Maths/Matrix.h"


// MATRIX 2X2 

Dewdrop::Math::Matrix2x2::Matrix2x2() {
    memset(_matrix, 0, sizeof(Matrix2x2));
}

/**
 * \brief Computes the Determinant of a 2x2 Matrix.
 * \param matrix 
 * \return A float, containing the Determinant. 
*/
float Dewdrop::Math::Matrix2x2::Determinant(const Matrix2x2& matrix)
{
    return (matrix._matrix[0] * matrix._matrix[3]) - (matrix._matrix[1] * matrix._matrix[2]);
}


// MATRIX 3X3
Dewdrop::Math::Matrix3x3::Matrix3x3() {
    memset(_matrix, 0, sizeof(Matrix3x3));
}
 
float Dewdrop::Math::Matrix3x3::Determinant(const Matrix3x3& matrix)
{
    Matrix2x2 _a = {};
    {
        _a._matrix[0] = matrix._matrix[4];
        _a._matrix[1] = matrix._matrix[5];
        _a._matrix[2] = matrix._matrix[7];
        _a._matrix[3] = matrix._matrix[8];
    }

    Matrix2x2 _b = {};
    {
        _b._matrix[0] = matrix._matrix[1];
        _b._matrix[1] = matrix._matrix[2];
        _b._matrix[2] = matrix._matrix[7];
        _b._matrix[3] = matrix._matrix[8];
    }

    Matrix2x2 _c = {};
    {
        _c._matrix[0] = matrix._matrix[1];
        _c._matrix[1] = matrix._matrix[2];
        _c._matrix[2] = matrix._matrix[4]; 
        _c._matrix[3] = matrix._matrix[5];
    }

    return ((matrix._matrix[0] * Matrix2x2::Determinant(_a)) - (matrix._matrix[3] * Matrix2x2::Determinant(_b)) + (matrix._matrix[6] * Matrix2x2::Determinant(_c)));
}


// MATRIX 4X4

Dewdrop::Math::Matrix4x4::Matrix4x4() {
    //Ensure the matrix is set to 0 by default. 
    memset(_matrix, 0, sizeof(Matrix4x4));
}

Dewdrop::Math::Vector4f Dewdrop::Math::Matrix4x4::Row(uint8_t index) const {
    if (index > 3) index = 3;
    if (index < 0) index = 0;

    index = index * 4;
    return *((Vector4f*)_matrix) + index;  //{ _matrix[0 + index], _matrix[1 + index], _matrix[2 + index], _matrix[3 + index] };
}

Dewdrop::Math::Vector4f Dewdrop::Math::Matrix4x4::Column(uint8_t index) const {
    if (index > 3) index = 3;
    if (index < 0) index = 0;

    return { _matrix[0 + index], _matrix[4 + index], _matrix[8 + index], _matrix[12 + index] };
}


//Computes the 4x4 Identity Matrix (1's on the diagonal).
//Identical for row / column major ordering. 
Dewdrop::Math::Matrix4x4 Dewdrop::Math::Matrix4x4::Identity() {
    Matrix4x4 out = {};
    memset(&out, 0, sizeof(Matrix4x4));

    out._matrix[0] = 1.0f;
    out._matrix[5] = 1.0f;
    out._matrix[10] = 1.0f;
    out._matrix[15] = 1.0f;

    return out;
}

Dewdrop::Math::Matrix4x4 Dewdrop::Math::Matrix4x4::Transpose(const Matrix4x4& matrix)
{
    Matrix4x4 out = matrix;

    //Swap rows and columns (mirror along the diagonal)

    out._matrix[1] = matrix._matrix[4];
    out._matrix[2] = matrix._matrix[8];
    out._matrix[3] = matrix._matrix[12];
    out._matrix[6] = matrix._matrix[9];
    out._matrix[7] = matrix._matrix[13];
    out._matrix[11] = matrix._matrix[14];

    return out;
}

Dewdrop::Math::Matrix4x4 Dewdrop::Math::Matrix4x4::Inverse(const Matrix4x4& matrix, bool& inverseExists)
{
    Matrix4x4 out = {};

    //Construct the inverse...
    {
        out._matrix[0] = matrix._matrix[5] * matrix._matrix[10] * matrix._matrix[15] -
            matrix._matrix[5] * matrix._matrix[11] * matrix._matrix[14] -
            matrix._matrix[9] * matrix._matrix[6] * matrix._matrix[15] +
            matrix._matrix[9] * matrix._matrix[7] * matrix._matrix[14] +
            matrix._matrix[13] * matrix._matrix[6] * matrix._matrix[11] -
            matrix._matrix[13] * matrix._matrix[7] * matrix._matrix[10];


        out._matrix[4] = -matrix._matrix[4] * matrix._matrix[10] * matrix._matrix[15] +
            matrix._matrix[4] * matrix._matrix[11] * matrix._matrix[14] +
            matrix._matrix[8] * matrix._matrix[6] * matrix._matrix[15] -
            matrix._matrix[8] * matrix._matrix[7] * matrix._matrix[14] -
            matrix._matrix[12] * matrix._matrix[6] * matrix._matrix[11] +
            matrix._matrix[12] * matrix._matrix[7] * matrix._matrix[10];

        out._matrix[8] = matrix._matrix[4] * matrix._matrix[9] * matrix._matrix[15] -
            matrix._matrix[4] * matrix._matrix[11] * matrix._matrix[13] -
            matrix._matrix[8] * matrix._matrix[5] * matrix._matrix[15] +
            matrix._matrix[8] * matrix._matrix[7] * matrix._matrix[13] +
            matrix._matrix[12] * matrix._matrix[5] * matrix._matrix[11] -
            matrix._matrix[12] * matrix._matrix[7] * matrix._matrix[9];

        out._matrix[12] = -matrix._matrix[4] * matrix._matrix[9] * matrix._matrix[14] +
            matrix._matrix[4] * matrix._matrix[10] * matrix._matrix[13] +
            matrix._matrix[8] * matrix._matrix[5] * matrix._matrix[14] -
            matrix._matrix[8] * matrix._matrix[6] * matrix._matrix[13] -
            matrix._matrix[12] * matrix._matrix[5] * matrix._matrix[10] +
            matrix._matrix[12] * matrix._matrix[6] * matrix._matrix[9];

        out._matrix[1] = -matrix._matrix[1] * matrix._matrix[10] * matrix._matrix[15] +
            matrix._matrix[1] * matrix._matrix[11] * matrix._matrix[14] +
            matrix._matrix[9] * matrix._matrix[2] * matrix._matrix[15] -
            matrix._matrix[9] * matrix._matrix[3] * matrix._matrix[14] -
            matrix._matrix[13] * matrix._matrix[2] * matrix._matrix[11] +
            matrix._matrix[13] * matrix._matrix[3] * matrix._matrix[10];


        out._matrix[5] = matrix._matrix[0] * matrix._matrix[10] * matrix._matrix[15] -
            matrix._matrix[0] * matrix._matrix[11] * matrix._matrix[14] -
            matrix._matrix[8] * matrix._matrix[2] * matrix._matrix[15] +
            matrix._matrix[8] * matrix._matrix[3] * matrix._matrix[14] +
            matrix._matrix[12] * matrix._matrix[2] * matrix._matrix[11] -
            matrix._matrix[12] * matrix._matrix[3] * matrix._matrix[10];


        out._matrix[9] = -matrix._matrix[0] * matrix._matrix[9] * matrix._matrix[15] +
            matrix._matrix[0] * matrix._matrix[11] * matrix._matrix[13] +
            matrix._matrix[8] * matrix._matrix[1] * matrix._matrix[15] -
            matrix._matrix[8] * matrix._matrix[3] * matrix._matrix[13] -
            matrix._matrix[12] * matrix._matrix[1] * matrix._matrix[11] +
            matrix._matrix[12] * matrix._matrix[3] * matrix._matrix[9];

        out._matrix[13] = matrix._matrix[0] * matrix._matrix[9] * matrix._matrix[14] -
            matrix._matrix[0] * matrix._matrix[10] * matrix._matrix[13] -
            matrix._matrix[8] * matrix._matrix[1] * matrix._matrix[14] +
            matrix._matrix[8] * matrix._matrix[2] * matrix._matrix[13] +
            matrix._matrix[12] * matrix._matrix[1] * matrix._matrix[10] -
            matrix._matrix[12] * matrix._matrix[2] * matrix._matrix[9];

        out._matrix[2] = matrix._matrix[1] * matrix._matrix[6] * matrix._matrix[15] -
            matrix._matrix[1] * matrix._matrix[7] * matrix._matrix[14] -
            matrix._matrix[5] * matrix._matrix[2] * matrix._matrix[15] +
            matrix._matrix[5] * matrix._matrix[3] * matrix._matrix[14] +
            matrix._matrix[13] * matrix._matrix[2] * matrix._matrix[7] -
            matrix._matrix[13] * matrix._matrix[3] * matrix._matrix[6];

        out._matrix[6] = -matrix._matrix[0] * matrix._matrix[6] * matrix._matrix[15] +
            matrix._matrix[0] * matrix._matrix[7] * matrix._matrix[14] +
            matrix._matrix[4] * matrix._matrix[2] * matrix._matrix[15] -
            matrix._matrix[4] * matrix._matrix[3] * matrix._matrix[14] -
            matrix._matrix[12] * matrix._matrix[2] * matrix._matrix[7] +
            matrix._matrix[12] * matrix._matrix[3] * matrix._matrix[6];

        out._matrix[10] = matrix._matrix[0] * matrix._matrix[5] * matrix._matrix[15] -
            matrix._matrix[0] * matrix._matrix[7] * matrix._matrix[13] -
            matrix._matrix[4] * matrix._matrix[1] * matrix._matrix[15] +
            matrix._matrix[4] * matrix._matrix[3] * matrix._matrix[13] +
            matrix._matrix[12] * matrix._matrix[1] * matrix._matrix[7] -
            matrix._matrix[12] * matrix._matrix[3] * matrix._matrix[5];

        out._matrix[14] = -matrix._matrix[0] * matrix._matrix[5] * matrix._matrix[14] +
            matrix._matrix[0] * matrix._matrix[6] * matrix._matrix[13] +
            matrix._matrix[4] * matrix._matrix[1] * matrix._matrix[14] -
            matrix._matrix[4] * matrix._matrix[2] * matrix._matrix[13] -
            matrix._matrix[12] * matrix._matrix[1] * matrix._matrix[6] +
            matrix._matrix[12] * matrix._matrix[2] * matrix._matrix[5];

        out._matrix[3] = -matrix._matrix[1] * matrix._matrix[6] * matrix._matrix[11] +
            matrix._matrix[1] * matrix._matrix[7] * matrix._matrix[10] +
            matrix._matrix[5] * matrix._matrix[2] * matrix._matrix[11] -
            matrix._matrix[5] * matrix._matrix[3] * matrix._matrix[10] -
            matrix._matrix[9] * matrix._matrix[2] * matrix._matrix[7] +
            matrix._matrix[9] * matrix._matrix[3] * matrix._matrix[6];


        out._matrix[7] = matrix._matrix[0] * matrix._matrix[6] * matrix._matrix[11] -
            matrix._matrix[0] * matrix._matrix[7] * matrix._matrix[10] -
            matrix._matrix[4] * matrix._matrix[2] * matrix._matrix[11] +
            matrix._matrix[4] * matrix._matrix[3] * matrix._matrix[10] +
            matrix._matrix[8] * matrix._matrix[2] * matrix._matrix[7] -
            matrix._matrix[8] * matrix._matrix[3] * matrix._matrix[6];

        out._matrix[11] = -matrix._matrix[0] * matrix._matrix[5] * matrix._matrix[11] +
            matrix._matrix[0] * matrix._matrix[7] * matrix._matrix[9] +
            matrix._matrix[4] * matrix._matrix[1] * matrix._matrix[11] -
            matrix._matrix[4] * matrix._matrix[3] * matrix._matrix[9] -
            matrix._matrix[8] * matrix._matrix[1] * matrix._matrix[7] +
            matrix._matrix[8] * matrix._matrix[3] * matrix._matrix[5];

        out._matrix[15] = matrix._matrix[0] * matrix._matrix[5] * matrix._matrix[10] -
            matrix._matrix[0] * matrix._matrix[6] * matrix._matrix[9] -
            matrix._matrix[4] * matrix._matrix[1] * matrix._matrix[10] +
            matrix._matrix[4] * matrix._matrix[2] * matrix._matrix[9] +
            matrix._matrix[8] * matrix._matrix[1] * matrix._matrix[6] -
            matrix._matrix[8] * matrix._matrix[2] * matrix._matrix[5];
    }

    auto det = Matrix4x4::Determinant(matrix);

    //Not all matrices have an inverse; The implementing function is expected to validate this. 
    (det == 0) ? inverseExists = false : inverseExists = true;

    det = 1.0f / det;

    for (int i = 0; i < 16; i++) {
        out._matrix[i] = out._matrix[i] * det;
    }

    return out;
}

float Dewdrop::Math::Matrix4x4::Determinant(const Matrix4x4& matrix) {
    Matrix3x3 _a = {};
    {
        _a._matrix[0] = matrix._matrix[5];
        _a._matrix[1] = matrix._matrix[6];
        _a._matrix[2] = matrix._matrix[7];
        _a._matrix[3] = matrix._matrix[9];
        _a._matrix[4] = matrix._matrix[10];
        _a._matrix[5] = matrix._matrix[11];
        _a._matrix[6] = matrix._matrix[13];
        _a._matrix[7] = matrix._matrix[14];
        _a._matrix[8] = matrix._matrix[15];
    }

    Matrix3x3 _b = {};
    {
        _b._matrix[0] = matrix._matrix[4];
        _b._matrix[1] = matrix._matrix[6];
        _b._matrix[2] = matrix._matrix[7];
        _b._matrix[3] = matrix._matrix[8];
        _b._matrix[4] = matrix._matrix[10];
        _b._matrix[5] = matrix._matrix[11];
        _b._matrix[6] = matrix._matrix[12];
        _b._matrix[7] = matrix._matrix[14];
        _b._matrix[8] = matrix._matrix[15];
    }
    Matrix3x3 _c = {};
    {
        _c._matrix[0] = matrix._matrix[4];
        _c._matrix[1] = matrix._matrix[5];
        _c._matrix[2] = matrix._matrix[7];
        _c._matrix[3] = matrix._matrix[8];
        _c._matrix[4] = matrix._matrix[9];
        _c._matrix[5] = matrix._matrix[11];
        _c._matrix[6] = matrix._matrix[12];
        _c._matrix[7] = matrix._matrix[13];
        _c._matrix[8] = matrix._matrix[15];
    }
    Matrix3x3 _d = {};
    {
        _d._matrix[0] = matrix._matrix[4];
        _d._matrix[1] = matrix._matrix[5];
        _d._matrix[2] = matrix._matrix[6];
        _d._matrix[3] = matrix._matrix[8];
        _d._matrix[4] = matrix._matrix[9];
        _d._matrix[5] = matrix._matrix[10];
        _d._matrix[6] = matrix._matrix[12];
        _d._matrix[7] = matrix._matrix[13];
        _d._matrix[8] = matrix._matrix[14];
    }

    return (
        (matrix._matrix[0] * Matrix3x3::Determinant(_a)) -
        (matrix._matrix[1] * Matrix3x3::Determinant(_b)) +
        (matrix._matrix[2] * Matrix3x3::Determinant(_c)) -
        (matrix._matrix[3] * Matrix3x3::Determinant(_d))
        );
}

Dewdrop::Math::Vector4f Dewdrop::Math::Matrix4x4::MMult_V4f_M4x4(const Vector4f& a, const Matrix4x4& b) {
    Vector4f out = {};

    if constexpr (ORDERING == Dewdrop::Math::EMMultOrdering::Row) {
        //dot vector by Columns
        for (int i = 0; i < 4; i++) {
            out.arr[i] = Vector4f::Dot(a, b.Column(i));
        }
    }
    else if constexpr (ORDERING == Dewdrop::Math::EMMultOrdering::Column) {
        //dot vector by rows
        for (int i = 0; i < 4; i++) {
            out.arr[i] = Vector4f::Dot(a, b.Row(i));
        }
    }
    return out;
}

Dewdrop::Math::Matrix4x4 Dewdrop::Math::Matrix4x4::MMult_M4x4_M4x4(const Matrix4x4& a, const Matrix4x4& b) {
    Matrix4x4 out = {};

    if constexpr (ORDERING == Dewdrop::Math::EMMultOrdering::Row) {
        //Multiply A's rows by B's columns
        for (int r = 0; r < 4; r++) {
            const auto row = MMult_V4f_M4x4(a.Row(r), b);
            out._matrix[(r * 4) + 0] = row.arr[0];
            out._matrix[(r * 4) + 1] = row.arr[1];
            out._matrix[(r * 4) + 2] = row.arr[2];
            out._matrix[(r * 4) + 3] = row.arr[3];
        }
    }
    else if constexpr (ORDERING == Dewdrop::Math::EMMultOrdering::Column) {
        //Multiply A's columns by B's rows
        for (int c = 0; c < 4; c++) {
            const auto col = MMult_V4f_M4x4(a.Column(c), b);
            out._matrix[c + 0] = col.arr[0];
            out._matrix[c + 4] = col.arr[1];
            out._matrix[c + 8] = col.arr[2];
            out._matrix[c + 12] = col.arr[3];
        }
    }
    return out;
}

