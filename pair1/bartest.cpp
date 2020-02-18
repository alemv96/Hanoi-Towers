// File: bartest.cpp
// Purpose: Draw each of the bar colors
// Author: Robert Lowe
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bar.h"
using namespace std;
using namespace bar;
int main()
{
    cout<< setw(37) << "##"; 
    cout << setw(46) 
         << draw_bar(WHITE, 2) << setw(70) << bar::draw_bar(bar:: BLACK, 2) << endl;
    cout << setw(47)  
         << bar::draw_bar(RED, 4)<< setw(70) << bar::draw_bar(bar::RED , 4) << endl;
    cout << setw(48)  
         << bar::draw_bar(bar::GREEN, 6) << setw(70) << bar::draw_bar(bar::GREEN , 6) << endl;
    cout << setw(49) 
         << bar::draw_bar(bar::CYAN , 8) << setw(70) << bar::draw_bar(bar::YELLOW , 8) << endl;
       
}
