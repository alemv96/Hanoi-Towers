// File: draw.cpp
// Purpose: This function draws solid color bars on your terminal.
// Author: Robert Lowe
#include <iomanip>
#include <sstream>
#include "bar.h"

namespace bar 
{

std::string
draw_bar(bar_color color, unsigned int width)
{
    std::ostringstream bar;

    //set the background color
    bar << "\033[" << color << "m";

    //fill the bar
    bar << std::setw(width) << "";

    //return to normal mode.
    bar << "\033[0m";

    //return the magic string
    return bar.str();
}


}
