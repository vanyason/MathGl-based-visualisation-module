#include "../include/mathGL_graphics.h"
#include <cmath>
#include <list>
#include <string>

/**
 *
 * Example of plotting two arguments function f(x,t) = cos(x) - t,
 * using animation and saving to file
 * x[-10,10]    Dots amount: 100
 * t[0,5]       Step: 1
 *
 */
double f(const double &x, const double &t)
{
    return cos(x) - t;
}

int main()
{
    MathGLGraphics gr;
    FunctionArg x(-10,10,100);
    double t;

    //  All the objects will be stored here
    std::list<TwoArgumentsFunction_Plot> list1;

    for(t=0; t <=5; t+= 1)
    {
        list1.push_back(TwoArgumentsFunction_Plot(f,x,t));

        gr.parametres()->setRanges(-10,10, -10, 2);
        gr.link(&list1.back());
        gr.newFrame();

    }

    gr.saveBMP();

    return 0;
}
