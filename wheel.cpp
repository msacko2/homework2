#include "wheel.h"
#include <random>
#include <iostream>
using namespace std;

Wheel::Wheel() {
    minVal = 1;
    maxVal = 10;
}

int Wheel::getMinVal()
{
    return minVal;
}

void Wheel::setMinVal(int value)
{
    minVal = value;
}

int Wheel::getMaxVal()
{
    return maxVal;
}

void Wheel::setMaxVal(int value)
{
    maxVal = value;
}

/**
* @param spin 0 if the house is spinning, 1 if the player is spinning
*/
int Wheel::spin()
{
    random_device rd;
    uniform_int_distribution<int> dist(minVal, maxVal);
    return dist(rd);
}