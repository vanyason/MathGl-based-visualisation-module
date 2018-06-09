//
// Created by ivan on 6/9/18.
//
#include "../include/mathGL_graphics.h"
#include <cmath>
#include <list>
#include <string>

/**
 *
 * Example of plotting two arguments function f(x) = e^(x^2/100) * cos(5*x),
 * using animation and saving to file
 * x[-10,10]    Dots amount: 1000
 *
 */
double f(const double &x)
{
    return exp(-x*x/100) * cos(5*x);
}

int main()
{
    MathGLGraphics gr;
    FunctionArg x(-10,10,1000);
    OneArgumentFunction_Plot func(f,x);
    gr.parametres()->setRanges(-10,10,-2,2);
    gr.link(&func);
    gr.plotQT("test");
    return 0;
}

