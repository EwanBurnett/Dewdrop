#include "Vector.h"

//VECTOR 2
template<typename T>
Math::Vector2<T>::Vector2(T x, T y)
{
    xy.x = x;
    xy.y = y;
}

template<typename T>
Math::Vector2<T> Math::Vector2<T>::operator+(const Vector2<T>& rhs)
{    
    return { xy.x + rhs.xy.x, xy.y + rhs.xy.y };
}

template<typename T>
Math::Vector2<T> Math::Vector2<T>::operator-(const Vector2<T>& rhs)
{
    return { xy.x - rhs.xy.x, xy.y - rhs.xy.y };
}

template<typename T>
Math::Vector2<T> Math::Vector2<T>::operator*(const T& rhs)
{
    return { xy.x * rhs.xy.x, xy.y * rhs.xy.y };
}

template<typename T>
Math::Vector2<T> Math::Vector2<T>::operator/(const T& rhs)
{
    return { xy.x / rhs.xy.x, xy.y / rhs.xy.y };
}

template<typename T>
float Math::Vector2<T>::Dot(const Vector2<T>& a, const Vector2<T>& b)
{
    return { a.xy.x * b.xy.x + a.xy.y * b.xy.y };
}

template<typename T>
float Math::Vector2<T>::Length(const Vector2<T>& vector)
{
    return sqrtf((vector.xy.x * vector.xy.x) + (vector.xy.y * vector.xy.y));
}

template<typename T>
Math::Vector2<T> Math::Vector2<T>::Normalize(const Vector2<T>& vector)
{
    const auto length = Math::Vector2<T>::Length(vector);

    return { vector / length };
}

/**
 * @brief Sets a single value in each component (XY) of the vector. 
 * @tparam T The type of the vector
 * @param val The value to clone
 * @return A Vector containing { val, val }
*/
template<typename T>
Math::Vector2<T> Math::Vector2<T>::Set(const T& val)
{
    return { val, val };
}

//VECTOR 3

/**
 * @brief Sets a single value in each component (XYZ) of the vector. 
 * @tparam T The type of the vector
 * @param val The value to clone
 * @return A Vector containing { val, val, val }
*/
template<typename T>
Math::Vector3<T> Math::Vector3<T>::Set(const T& val) {
    return { val, val, val };
}

//VECTOR 4

template<typename T>
Math::Vector4<T>::Vector4(T x, T y, T z, T w)
{
    static_assert(std::is_standard_layout<T>::value, "Not Standard Layout");

    xyzw.x = x;
    xyzw.y = y;
    xyzw.z = z;
    xyzw.w = w;
}

template<typename T>
Math::Vector4<T> Math::Vector4<T>::operator +(const Vector4<T>& rhs) {
    return { xyzw.x + rhs.xyzw.x, xyzw.y + rhs.xyzw.y, xyzw.z + rhs.xyzw.z, xyzw.w + rhs.xyzw.w };
}

template<typename T>
Math::Vector4<T> Math::Vector4<T>::operator -(const Vector4<T>& rhs) {
    return { xyzw.x - rhs.xyzw.x, xyzw.y - rhs.xyzw.y, xyzw.z - rhs.xyzw.z, xyzw.w - rhs.xyzw.w };
}

template<typename T>
Math::Vector4<T> Math::Vector4<T>::operator *(const T& rhs) {
    return { xyzw.x * rhs, xyzw.y * rhs, xyzw.z * rhs, xyzw.w * rhs };
}

template<typename T>
Math::Vector4<T> Math::Vector4<T>::operator / (const T& rhs) {
    return { xyzw.x / rhs, xyzw.y / rhs, xyzw.z / rhs, xyzw.w / rhs };
}


//DOT PRODUCT
template<typename T>
float Math::Vector4<T>::Dot(const Vector4<T>& a, const Vector4<T>& b) {
    return { a.xyzw.x * b.xyzw.x + a.xyzw.y * b.xyzw.y + a.xyzw.z * b.xyzw.z + a.xyzw.w * b.xyzw.w };
}
