#include "../include/mathGL_graphics.h"
#include <cmath>
#include <list>
#include <string>

/**
 *
 * Example of plotting two arguments function f(x,t) = cos(x) - t,
 * using syntax parser
 *
 */

int main()
{
    MathGLGraphics gr;
    TwoArgumentsFunction_Surf_SyntaxParser obj("cos(x) - y");

    gr.parametres()->setRanges(-10, 10, -5, 5,-7,7);
    gr.parametres()->setRotation(70,45);

    gr.link(&obj);
    gr.plotQT("cos(x) - t");

    return 0;
}
