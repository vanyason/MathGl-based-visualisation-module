#include "../include/mathGL_graphics.h"
#include <cmath>
#include <list>
#include <string>

/**
 *
 * Example of plotting one argument function f(x) = sin(x) + 1,
 * x [-10,10],
 * Dots amount : 100
 */

double f(const double &x)
{
    return sin(x) + 1;
}

int main()
{
    MathGLGraphics gr;
    OneArgumentFunction_Plot obj(f, FunctionArg(-10, 10, 100));

    gr.parametres()->setRanges(-10, 10, 0, 2);

    gr.link(&obj);
    gr.plotQT("sin(x)");

    return 0;
}
