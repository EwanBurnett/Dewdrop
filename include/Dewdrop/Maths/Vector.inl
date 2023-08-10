#include "../include/Dewdrop/Maths/Vector.h"

//VECTOR 2

/**
 * @brief A Two-component Vector (XY). 
 * @tparam T The underlying component type of the vector. 
*/
template<typename T>
Dewdrop::Math::Vector2<T>::Vector2(T x, T y)
{
    xy.x = x;
    xy.y = y;
}

template<typename T>
Dewdrop::Math::Vector2<T> Dewdrop::Math::Vector2<T>::operator+(const Vector2<T>& rhs)
{    
    return { xy.x + rhs.xy.x, xy.y + rhs.xy.y };
}

template<typename T>
Dewdrop::Math::Vector2<T> Dewdrop::Math::Vector2<T>::operator-(const Vector2<T>& rhs)
{
    return { xy.x - rhs.xy.x, xy.y - rhs.xy.y };
}

template<typename T>
Dewdrop::Math::Vector2<T> Dewdrop::Math::Vector2<T>::operator*(const T& rhs)
{
    return { xy.x * rhs.xy.x, xy.y * rhs.xy.y };
}

template<typename T>
Dewdrop::Math::Vector2<T> Dewdrop::Math::Vector2<T>::operator/(const T& rhs)
{
    return { xy.x / rhs.xy.x, xy.y / rhs.xy.y };
}

/**
 * @brief Computes the Dot product of two Vector2 objects, defined as \f$(a_x * b_x) + ($a_y * b_y)\f$.
 * @return The floating point dot product.
*/
template<typename T>
float Dewdrop::Math::Vector2<T>::Dot(const Vector2<T>& a, const Vector2<T>& b)
{
    return { a.xy.x * b.xy.x + a.xy.y * b.xy.y };
}

/**
 * @brief Computes the Length (or Magnitude) of a Vector2, defined as \f$sqrt(x^2 + y^2)\f$. 
 * @return The Length of the Vector. 
*/
template<typename T>
float Dewdrop::Math::Vector2<T>::Length(const Vector2<T>& vector)
{
    return sqrtf((vector.xy.x * vector.xy.x) + (vector.xy.y * vector.xy.y));
}

/**
 * @brief Normalizes a Vector2, clamping each of its values to [0, 1]. Defined as \f$\frac{(x, y)}{|(x, y)|}\f$.
 * @return A Normalized Vector2. 
*/
template<typename T>
Dewdrop::Math::Vector2<T> Dewdrop::Math::Vector2<T>::Normalize(const Vector2<T>& vector)
{
    const auto length = Dewdrop::Math::Vector2<T>::Length(vector);

    return { vector / length };
}

/**
 * @brief Sets a single value in each component (XY) of the vector. 
 * @param val The value to clone
 * @return A Vector containing \f$(val, val)\f$
*/
template<typename T>
Dewdrop::Math::Vector2<T> Dewdrop::Math::Vector2<T>::Set(const T& val)
{
    return { val, val };
}

//VECTOR 3


template<typename T>
Dewdrop::Math::Vector3<T>::Vector3(T X, T Y, T Z) 
{
    x = x;
    y = y;
    z = z;
}

template<typename T>
Dewdrop::Math::Vector3<T> Dewdrop::Math::Vector3<T>::operator+(const Vector3<T>& rhs)
{
    return { x + rhs.x, y + rhs.y, z + rhs.z };
}

template<typename T>
Dewdrop::Math::Vector3<T> Dewdrop::Math::Vector3<T>::operator-(const Vector3<T>& rhs)
{
    return { x - rhs.x, y - rhs.y, z - rhs.z };
}

template<typename T>
Dewdrop::Math::Vector3<T> Dewdrop::Math::Vector3<T>::operator*(const T& rhs)
{
    return { xy.x * rhs.x, y * rhs.y, z * rhs.z };
}

template<typename T>
Dewdrop::Math::Vector3<T> Dewdrop::Math::Vector3<T>::operator/(const T& rhs)
{
    return { xy.x / rhs.x, xy.y / rhs.y, z / rhs.z};
}

template<typename T>
float Dewdrop::Math::Vector3<T>::Dot(const Vector3<T>& a, const Vector3<T>& b)
{
    return 0.0f;    //TODO
}

template<typename T>
Dewdrop::Math::Vector3<T> Dewdrop::Math::Vector3<T>::Cross(const Vector3<T>& a, const Vector3<T>& b)
{
    return Vector3<T>();    //TODO
}

template<typename T>
float Dewdrop::Math::Vector3<T>::Length(const Vector3<T>& vector)
{
    return 0.0f;    //TODO
}

/**
 * @brief Sets a single value in each component (XYZ) of the vector. 
 * @param val The value to clone
 * @return A Vector containing \f$(val, val, val)\f$ 
*/
template<typename T>
Dewdrop::Math::Vector3<T> Dewdrop::Math::Vector3<T>::Set(const T& val) {
    return { val, val, val };
}


template<typename T>
Dewdrop::Math::Vector3<T> Dewdrop::Math::Vector3<T>::Normalize(const Vector3<T>& vector)
{
    return Vector3<T>();    //TODO
}

template<typename T>
float Dewdrop::Math::Vector3<T>::Angle(const Vector3<T>& a, const Vector3<T>& b)
{
    return 0.0f;    //TODO
}

template<typename T>
float Dewdrop::Math::Vector3<T>::Distance(const Vector3<T>& a, const Vector3<T>& b)
{
    return 0.0f;    //TODO
}

template<typename T>
void Dewdrop::Math::Vector3<T>::OrthoNormalize(Vector3<T>& normal, Vector3<T>& tangent, Vector3<T>& binormal)
{
    //TODO
}

template<typename T>
Dewdrop::Math::Vector3<T> Dewdrop::Math::Vector3<T>::Reflect(const Vector3<T>& vector, const Vector3<T>& plane)
{
    return Vector3<T>();    //TODO
}




//VECTOR 4

template<typename T>
Dewdrop::Math::Vector4<T>::Vector4(T x, T y, T z, T w)
{
    static_assert(std::is_standard_layout<T>::value, "Not Standard Layout");

    xyzw.x = x;
    xyzw.y = y;
    xyzw.z = z;
    xyzw.w = w;
}

template<typename T>
Dewdrop::Math::Vector4<T> Dewdrop::Math::Vector4<T>::operator +(const Vector4<T>& rhs) {
    return { xyzw.x + rhs.xyzw.x, xyzw.y + rhs.xyzw.y, xyzw.z + rhs.xyzw.z, xyzw.w + rhs.xyzw.w };
}

template<typename T>
Dewdrop::Math::Vector4<T> Dewdrop::Math::Vector4<T>::operator -(const Vector4<T>& rhs) {
    return { xyzw.x - rhs.xyzw.x, xyzw.y - rhs.xyzw.y, xyzw.z - rhs.xyzw.z, xyzw.w - rhs.xyzw.w };
}

template<typename T>
Dewdrop::Math::Vector4<T> Dewdrop::Math::Vector4<T>::operator *(const T& rhs) {
    return { xyzw.x * rhs, xyzw.y * rhs, xyzw.z * rhs, xyzw.w * rhs };
}

template<typename T>
Dewdrop::Math::Vector4<T> Dewdrop::Math::Vector4<T>::operator / (const T& rhs) {
    return { xyzw.x / rhs, xyzw.y / rhs, xyzw.z / rhs, xyzw.w / rhs };
}


//DOT PRODUCT
template<typename T>
float Dewdrop::Math::Vector4<T>::Dot(const Vector4<T>& a, const Vector4<T>& b) {
    return { a.xyzw.x * b.xyzw.x + a.xyzw.y * b.xyzw.y + a.xyzw.z * b.xyzw.z + a.xyzw.w * b.xyzw.w };
}

template<typename T>
float Dewdrop::Math::Vector4<T>::Length(const Vector4<T>& vector)
{
    return 0.0f;    //TODO
}

template<typename T>
Dewdrop::Math::Vector4<T> Dewdrop::Math::Vector4<T>::Normalize(const Vector4<T>& vector)
{
    return Vector4<T>();    //TODO
}

template<typename T>
Dewdrop::Math::Vector4<T> Dewdrop::Math::Vector4<T>::Set(const T& val)
{
    return Vector4<T>();    //TODO
}


