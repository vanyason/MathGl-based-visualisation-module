//
// Created by ivan on 6/9/18.
//

#include "../include/mathGL_graphics.h"
#include <cmath>
#include <list>
#include <string>

/**
 *
 * Example of plotting one argument function f(x) = "10*sin(x)/x",
 * using syntax parser
 *
 */

int main()
{
    MathGLGraphics gr;
    OneArgumentFunction_Plot_SyntaxParser obj("10*sin(x)/x");
    gr.parametres()->setRanges(-20, 20, -5, 15);
    gr.link(&obj);
    gr.plotQT("10*sin(x)/x");

    return 0;
}
