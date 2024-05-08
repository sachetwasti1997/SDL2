//
// Created by SACHET WASTI on 05/05/24.
//

#ifndef SDLINTRO_VEC2D_H
#define SDLINTRO_VEC2D_H
#include <iostream>
using namespace std;

class Vec2D {
public:
    static const Vec2D Zero;

    Vec2D():Vec2D(0, 0){}
    Vec2D(float x, float y):mX(x), mY(y){}

    inline void SetX(float x){mX = x;}
    inline void SetY(float y){mY = y;}
    inline float GetX() const {return mX;}
    inline float GetY() const {return mY;}

    bool operator==(const Vec2D& vec2D) const;
    bool operator!=(const Vec2D& vec2D) const;
    Vec2D operator-() const;
    Vec2D operator*(float scale) const;
    Vec2D operator/(float scale) const;
    Vec2D& operator*=(float scale);
    Vec2D& operator/=(float scale);
    Vec2D operator+(const Vec2D & vec) const;
    Vec2D operator-(const Vec2D& vec) const;
    Vec2D& operator+=(const Vec2D& vec);
    Vec2D& operator-=(const Vec2D& vec);
    Vec2D GetUnitVector() const;
    Vec2D& Normalize();
    Vec2D ProjectOnto(const Vec2D& vec2D) const;

    float Mag2() const;
    float Mag() const;
    float Distance(const Vec2D& vec) const;
    float Dot(const Vec2D& vec2D) const;
    float AngleBetween(const Vec2D& vec) const;
    Vec2D Reflect(const Vec2D& normal) const;

    friend Vec2D operator*(float scalar, Vec2D vec);
    friend ostream& operator<<(ostream& consoleOut, const Vec2D& vec2D);

private:
    float mX, mY;
};


#endif //SDLINTRO_VEC2D_H
