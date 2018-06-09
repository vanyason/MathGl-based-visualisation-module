//
// Created by ivan on 6/9/18.
//

#include "../include/mathGL_graphics.h"
#include <cmath>
#include <list>
#include <string>

/**
 * Example of plotting two arguments function f(x,t) = sin(x)*cos(t),
 * x[-10,10],   Dots amount: 1000
 * t[-10, 10],  Dots amount: 1000
 *
 */
double f(const double& x, const double& t)
{
    return sin(x)*cos(t);
}

int main()
{
    MathGLGraphics gr;
    FunctionArg x(-10,10,500);
    FunctionArg t(-10,10,500);
    TwoArgumentsFunction_Surf obj(f,x,t);

    gr.parametres()->setRanges(-10, 10, -10, 10,-2,2);
    gr.parametres()->setRotation(60,40);

    gr.link(&obj);
    gr.plotQT("sin(x)*cos(t)");

    return 0;
}
