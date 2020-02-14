// File: bartest.cpp
// Purpose: Draw each of the bar colors
// Author: Robert Lowe
#include <iostream>
#include <iomanip>
#include "bar.h"

using namespace std;

int main()
{
    cout << setw(9) << "black: " 
         << bar::draw_bar(bar::BLACK, 20) << endl;
    cout << setw(9) << "red: " 
         << bar::draw_bar(bar::RED, 20) << endl;
    cout << setw(9) << "green: " 
         << bar::draw_bar(bar::GREEN, 20) << endl;
    cout << setw(9) << "yellow: " 
         << bar::draw_bar(bar::YELLOW, 20) << endl;
    cout << setw(9) << "blue: " 
         << bar::draw_bar(bar::BLUE, 20) << endl;
    cout << setw(9) << "magenta: " 
         << bar::draw_bar(bar::MAGENTA, 20) << endl;
    cout << setw(9) << "cyan: " 
         << bar::draw_bar(bar::CYAN, 20) << endl;
    cout << setw(9) << "white: " 
         << bar::draw_bar(bar::WHITE, 20) << endl;
}
