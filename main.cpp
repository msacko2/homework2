#include <iostream>
#include "player.h"
#include "houseWheel.h"

using namespace std;

void printPlayerBalance(Player &player) {
    cout << "Current balance: $" << player.money << "\n";
}

int getBet(Player &player) {
    int bet = 0;
    cout << "What amount would you like to bet? $";
    cin >> bet;
    return bet;
}

void runRound(Player &player, Wheel *houseWheel, bool isHard) 
{
    // Player bets
    printPlayerBalance(player);
    int bet = getBet(player);
    player.money -= bet;

    // Player rolls
    int playerSpin = player.wheel.spin();
    cout << "Spinning...\n";
    cout << "The wheel has landed on " << playerSpin << "\n";

    // Make a choice
    int wager = 0;
    
    while(wager != 1 && wager != 2 && wager != 3)
    {
        cout << "What would you like to do?\n1. Halve your wager\n2. Double your wager\n3. Keep your bet the same\n";
        cin >> wager;

        if (wager != 1 && wager != 2 && wager != 3) 
        {
            cout << "Invalid input.\n";
        }
    }
    
    // House spins
    int houseSpin1;
    int houseSpin2;
    if (isHard) {
        houseWheel->spin()
    }
    int houseSpin1 = houseWheel->spin();
    int houseSpin2 = houseWheel->spin();
    
    switch(wager) {
        case 1: { // wager is halved
            cout << "You've havled your bet\n";
            player.money += bet * 0.5;
            if (playerSpin <= houseSpin1 && playerSpin <= houseSpin2) {
                // yippee, player wins!
                cout << "House spins " << houseSpin1 << "\n";
                cout << "House spins " << houseSpin2 << "\n";
                player.money += bet * 0.5;
                cout << "You won back your bet. Your total remains unchanged\n";
            } else {
                cout << "You lost $" << bet * 0.5 << "\n";
            }
        }
        case 2: { // wager is doubled
            cout << "You've doubled your bet.\n";
            if (playerSpin > houseSpin1 && playerSpin > houseSpin2) {
                // yippee, player wins!
                cout << "House is spinning...\nHouse spins " << houseSpin1 << "\n";
                cout << "House is spinning...\nHouse spins " << houseSpin2 << "\n";
                player.money += bet * 3;
                cout << "You won $" << bet << "\n";
            }
        }
        case 3: { // if no change is made to the wager
            cout << "House is spinning...\nHouse spins " << houseSpin1 << "\n";
            if (playerSpin > houseSpin1) {
                player.money += bet * 2;
                cout << "You won $" << bet << "\n";
            }
        }
    }
    printPlayerBalance(player);
    if (player.money > 0) {
        int playerChoice = 0;     
        while(playerChoice != 1 && playerChoice != 2)
        {
            cout << "Would you like to play another round?\n1. Yes\n2. No\n";
            cin >> playerChoice;
            if (playerChoice == 1) { // if player chooses yes
                cout << "That's the spirit! Another round!\n";
                runRound(player, houseWheel, isHard);
            } else if (playerChoice == 2) {
                cout << "Leaving so soon? Come again!\n";
            }
        }
    } else if (player.money == 0) {
        cout << "You ran out of money!\nGAME OVER\n\n";
    }
    return;
}

void runGame(Player &player, Wheel *houseWheel, bool isHard) 
{
    int minVal = 0;
    int maxVal = 0;
    
    while (minVal >= maxVal || (minVal < 6 || maxVal > 20)) {
        cout << "Enter the minimum value on the wheel. ";
        cin >> minVal;
        cout << "Enter the maximum value on the wheel. ";
        cin >> maxVal;
        
        if (minVal >= maxVal) {
            cout << "Minimum value must be less than maximum value.\n";
        } else if (minVal < 6 || maxVal > 20) {
            cout << "Minimum value must be greater than 5 and maximum value must be less than 21.\n";
        }
    }
    
    player.wheel.setMinVal(minVal);
    player.wheel.setMaxVal(maxVal);
    houseWheel->setMinVal(minVal);
    houseWheel->setMaxVal(maxVal);

    cout << "Beginning the game...\n";
    runRound(player, houseWheel, isHard);
}

int main(void) 
{
    Player player;
    player.wheel = Wheel();
    Wheel *houseWheel;
    int mode;
    

    cout << "Welcome to Roullette!\n" << "Enter the number of the mode you like to play in:\n" << "1. Normal Mode\n2. Hard Mode\n";
    cin >> mode;
    
    switch(mode) {
        case 1:
            houseWheel = new Wheel;
            runGame(player, houseWheel, false);
            break;
        case 2:
            houseWheel = new HouseWheel;
            runGame(player, houseWheel, true);
            break;
        default:
            cout << "Invalid input." << endl;
            break;
    }
    
    return 0;
}
