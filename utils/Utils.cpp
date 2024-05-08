//
// Created by SACHET WASTI on 05/05/24.
//
#include "Utils.h"
#include <cmath>

bool isEqual(float x, float y) {
    return fabsf(x-y) < EPSILON;
}

bool isGreaterThanOrEqual(float x, float y){
    return x > y || isEqual(x, y);
}
bool isLessThanOrEqual(float x, float y){
    return x < y || isEqual(x, y);
}