#ifndef __DEWDROP_MATH_VECTOR_H
#define __DEWDROP_MATH_VECTOR_H
#include <type_traits>

namespace Dewdrop{
    namespace Math {

        template<typename T>
        struct Vector2 {
            Vector2(T x = static_cast<T>(0), T y = static_cast<T>(0));

            struct _XY { T x, y; };
            union {     //Data alignment should be implementation defined!
                _XY xy;
                T arr[2];
            };

            Vector2<T> operator +(const Vector2<T>& rhs);
            Vector2<T> operator -(const Vector2<T>& rhs);
            Vector2<T> operator *(const T& rhs);
            Vector2<T> operator /(const T& rhs);

            static float Dot(const Vector2<T>& a, const Vector2<T>& b);
            static float Length(const Vector2<T>& vector);
            static Vector2<T> Normalize(const Vector2<T>& vector);
            static Vector2<T> Set(const T& val);

        };


        template<typename T>
        struct Vector3 {
            Vector3(T x = static_cast<T>(0), T y = static_cast<T>(0), T z = static_cast<T>(0));

            union {
                struct { T x, y, z; };  //TODO: <-- Use a union of anonymous structs within other Vector implementations?
                struct { T r, g, b; };
                T arr[3];
            };

            Vector3<T> operator +(const Vector3<T>& rhs);
            Vector3<T> operator -(const Vector3<T>& rhs);
            Vector3<T> operator *(const T& rhs);
            Vector3<T> operator /(const T& rhs);

            static float Dot(const Vector3<T>& a, const Vector3<T>& b);
            static Vector3<T> Cross(const Vector3<T>& a, const Vector3<T>& b);
            static float Length(const Vector3<T>& vector);

            static Vector3<T> Set(const T& val);
            static Vector3<T> Normalize(const Vector3<T>& vector);

            static float Angle(const Vector3<T>& a, const Vector3<T>& b);
            static float Distance(const Vector3<T>& a, const Vector3<T>& b);

            static void OrthoNormalize(Vector3<T>& normal, Vector3<T>& tangent, Vector3<T>& binormal);

            static Vector3<T> Reflect(const Vector3<T>& vector, const Vector3<T>& plane);


        };

        template<typename T>
        struct Vector4 {
            Vector4(T x = static_cast<T>(0), T y = static_cast<T>(0), T z = static_cast<T>(0), T w = static_cast<T>(0));

            struct _XYZW { T x, y, z, w; };
            struct _RGBA { T r, g, b, a; };
            union {
                _XYZW xyzw;
                _RGBA rgba;
                T arr[4];
            };

            Vector4<T> operator +(const Vector4<T>& rhs);
            Vector4<T> operator -(const Vector4<T>& rhs);
            Vector4<T> operator *(const T& rhs);
            Vector4<T> operator /(const T& rhs);

            static float Dot(const Vector4<T>& a, const Vector4<T>& b);
            static float Length(const Vector4<T>& vector);
            static Vector4<T> Normalize(const Vector4<T>& vector);

            static Vector4<T> Set(const T& val);

        };

        typedef Vector2<float> Vector2f;        //A Two-Component Floating Point Vector. 
        typedef Vector2<double> Vector2d;       //A Two-Component Double Precision Vector. 
        typedef Vector2<int> Vector2i;          //A Two-Component Integral Vector. 
        typedef Vector3<float> Vector3f;
        typedef Vector3<double> Vector3d;
        typedef Vector3<int> Vector3i;
        typedef Vector4<float> Vector4f;
        typedef Vector4<double> Vector4d;
        typedef Vector4<int> Vector4i;

    }
}

#include "Vector.inl"

#endif
