// File: draw.h
// Purpose: This function draws solid color bars on your terminal.
// Author: Robert Lowe
#ifndef BAR_H
#define BAR_H
#include <string>

namespace bar 
{
    enum bar_color{BLACK=40, RED, GREEN, YELLOW, 
                   BLUE, MAGENTA, CYAN, WHITE};

    std::string draw_bar(bar_color color, unsigned int width);
}
#endif
