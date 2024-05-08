//
// Created by SACHET WASTI on 05/05/24.
//

#include "Vec2D.h"
#include "Utils.h"
#include <cassert>
#include <cmath>

ostream& operator<<(ostream& consoleOut, const Vec2D& vec2D) {
    consoleOut<<"X: "<<vec2D.mX<<" Y: "<<vec2D.mY;
    return consoleOut;
}

bool Vec2D::operator==(const Vec2D &vec2D) const {
    return isEqual(mX, vec2D.mX) && isEqual(mY, vec2D.mY);
}

bool Vec2D::operator!=(const Vec2D &vec2D) const {
    return !(*this == vec2D);
}

Vec2D Vec2D::operator-() const {
    return {-mX, -mY};
}

Vec2D Vec2D::operator*(float scale) const {
    return {scale * mX, scale * mY};
}

Vec2D Vec2D::operator/(float scale) const {
    assert(fabsf(scale) > EPSILON);
    return {mX / scale, mY / scale};
}

Vec2D &Vec2D::operator*=(float scale) {
    *this = *this * scale;
    return *this;
}

Vec2D &Vec2D::operator/=(float scale) {
    assert(fabsf(scale) > EPSILON);
    *this = *this / scale;
    return *this;
}

Vec2D operator*(float scalar, Vec2D vec) {
    return vec * scalar;
}

Vec2D Vec2D::operator+(const Vec2D &vec) const {
    return {vec.mX + mX, vec.mY + mY};
}

Vec2D Vec2D::operator-(const Vec2D& vec) const {
    return {mX - vec.mX, mY - vec.mY};
}

Vec2D &Vec2D::operator+=(const Vec2D &vec) {
    *this = *this + vec;
    return *this;
}

Vec2D &Vec2D::operator-=(const Vec2D &vec) {
    *this = *this - vec;
    return *this;
}

float Vec2D::Mag2() const {
    return mX * mX + mY * mY;
}

float Vec2D::Mag() const {
    return sqrt(mX * mX + mY * mY);
}

Vec2D Vec2D::GetUnitVector() const {
    float mag = Mag();

    if(mag > EPSILON) {
        return * this / mag;
    }

    return Vec2D::Zero;
}

Vec2D &Vec2D::Normalize() {
    float mag = Mag();

    if(mag > EPSILON) {
        *this /= mag;
    }
    return *this;
}

float Vec2D::Distance(const Vec2D &vec) const {
    return (vec-*this).Mag();
}

float Vec2D::Dot(const Vec2D &vec2D) const {
    return mX * vec2D.mX + mY * vec2D.mY;
}

Vec2D Vec2D::ProjectOnto(const Vec2D &vec2D) const {
    Vec2D unitVec = vec2D.GetUnitVector();
    float dot = Dot(unitVec);
    return unitVec * dot;
}

float Vec2D::AngleBetween(const Vec2D &vec) const {
    return acos(GetUnitVector().Dot(vec.GetUnitVector()));
}

Vec2D Vec2D::Reflect(const Vec2D &normal) const {
    return *this - 2.0f * ProjectOnto(normal);
}
