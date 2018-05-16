#include "mathGL_graphics.h"
#include <iostream>
#include <string>
#include <cmath>
#include <list>


using namespace std;

/**
 * This code is an example of MathGl_Graphics module usage. Basics
 * are explained here.
 *
 * Module is used to visualize dynamics of luminescence spectra
 */

int sample(mglGraph *gr)
{
    gr->Box();
    gr->Axis();
    gr->FPlot("sin(x)");
    return 0;
}

int main()
{
//    mglQT gr(sample,"test");
//    gr.Run();
//    return 0;

    OneArgumentFunction_Plot_SyntaxParser p("sin(x)");
    OneArgumentFunction_Plot_SyntaxParser p2("tan(x)");
    MathGLGraphics gr;

    gr.link(&p);
    gr.parametres().setRanges(-4,4,-2,2,0,0);

    gr.newFrame();
    gr.link(&p2);

   gr.plotQT("Test");


    //return 0;
}