#include "../include/mathGL_graphics.h"
#include <cmath>
#include <list>
#include <string>

/**
 *
 * Example of plotting one argument function f(x) = (x)^2 + 1,
 * using syntax parser
 *
 */


int main()
{
    MathGLGraphics gr;
    OneArgumentFunction_Plot_SyntaxParser obj("x*x + 1");

    gr.parametres()->setRanges(-3, 3, 0, 10);

    gr.link(&obj);
    gr.plotQT("x^2 + 1");

    return 0;
}
