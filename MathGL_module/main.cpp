#include "mathGL_graphics.h"
#include <iostream>
#include <string>
#include <cmath>
#include <list>
#include "mathGL_graphics_frame_properties.h"


using namespace std;

/**
 * This code is an example of MathGl_Graphics module usage. Basics
 * are explained here.
 *
 * Module is used to visualize dynamics of luminescence spectra
 */

int sample(mglGraph *gr)
{
    gr->NewFrame();
    gr->SetRanges(-10,10,-2,2);
    gr->Box();
    gr->Axis();
    gr->FPlot("sin(x)");
    gr->EndFrame();

    gr->NewFrame();
    gr->SetRanges(-2,2);
    gr->Box();
    gr->Axis();
    gr->FPlot("tan(x)");
    gr->EndFrame();

    return 0;
}

int main()
{
 /*   mglQT gr(sample,"test");
    gr.Run();
    return 0;*/


    OneArgumentFunction_Plot_SyntaxParser p("sin(x)");
    OneArgumentFunction_Plot_SyntaxParser p2("tan(x)");
    MathGLGraphics gr;

    gr.link(&p);
    gr.parametres()->setRanges(-6,4,-2,2,0,0);

    gr.newFrame();
    gr.parametres()->setRanges(-8,8,-2,2,-1,1);
    gr.link(&p2);

   gr.plotQT("Test");

    return 0;
}
