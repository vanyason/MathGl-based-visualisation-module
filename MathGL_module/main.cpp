#include "mathGL_Graphics.h"
#include <cmath>

using namespace std;

double f2(const double &x)
{
    return sqrt(x);
}

int sample(mglGraph *gr)
{
    gr->Rotate(40, 40);
    gr->Box();
}

double f(const double &x, const double &y)
{
    return sin(x) + y;
}

int main()
{
//
//    mglQT grr(sample, "Test");
//    grr.Run();

    MathGLGraphics gr;

    TwoArgumentsFunction_SyntaxParser spp("sin(x) + y");
    OneArgumentFunction_SyntaxParser sp("sin(x)", "b4");
    gr.add(&spp);
    gr.add(&sp);

//    TwoArgumentsFunction f1(f,FunctionArg(-4,4,100), FunctionArg(0,5,1.));
//    gr.add(&f1);

    gr.setRanges(-10, 10, -0, 10, -1, 10);
    gr.setRotation(70, 40, 0);
    gr.setXAxisLabel("x");
    gr.setYAxisLabel("y");
    gr.setZAxisLabel("f(x,y)");
    // gr.setTitle("Message");

    gr.plotQT("Title");


    return 0;
}