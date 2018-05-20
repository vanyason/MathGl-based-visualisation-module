#include "../include/mathGL_graphics.h"
#include <cmath>
#include <list>
#include <string>

/**
 *
 * Example of plotting two arguments function f(x,t) = sin(x) + t,
 * x[-10,10],   Dots amount: 100
 * t[0,5],      Step: 1
 *
 */
double f(const double& x, const double& t)
{
    return sin(x) + t;
}

int main()
{
    MathGLGraphics gr;
    FunctionArg x(-10,10,100);
    FunctionArg t(0,5,1.);
    TwoArgumentsFunction_Surf obj(f,x,t);

    gr.parametres()->setRanges(-10, 10, 0, 5,-2,7);
    gr.parametres()->setRotation(70,45);

    gr.link(&obj);
    gr.plotQT("sin(x) + t");

    return 0;
}
