#include "houseWheel.h"
#include <stdio.h>
#include <random>
using namespace std;

/**
* Spins the wheel. If house loses, increases house slots.
* @param playerSpin The player's spin value. If negative, the house has already won once.
*/
int HouseWheel::spin(int playerSpin) {
    random_device rd;
    uniform_int_distribution<int> dist(minVal, maxVal);
    int houseSpin = dist(rd);
    
    if(houseSpin >= abs(playerSpin) && maxVal > minVal + 1 && playerSpin < 0) { // If the house wins for a second time in a row
        maxVal--;
    } else if (houseSpin < abs(playerSpin)) { // house loses
        maxVal++;
    }

    return houseSpin;
}