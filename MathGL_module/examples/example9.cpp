//
// Created by ivan on 6/9/18.
//

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
    TwoArgumentsFunction_Surf_SyntaxParser obj("1/(1+x^2) + 1/(1+y^2)");

    gr.parametres()->setRanges(-1, 1, -1, 1,-1,3);
    gr.parametres()->setRotation(70,45);

    gr.link(&obj);
    gr.plotQT("1/(1+x^2) + 1/(1+y^2)");

    return 0;
}
