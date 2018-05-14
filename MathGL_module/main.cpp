#include "mathGL_Graphics.h"
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

//  Variables
double L_v = 0.15;          //   [0 ; 0.5]
double hOmg = 0.15;         //   [0.1 ; 0.25]
double S = L_v / hOmg;
double L_s = 0.5;           //    [0.2 ; 1.2]
double dG_CR = -1.91;       //    [-1 ; 2]
double kT = 0.025;          //    [0.025]
double A0 = 1.;             //    [1]
int n0 = 1;                 //    [0 ; 10]
double Tl = 0.5;            //    [0.5]
double Tv = 0.3;            //    [0.5 ; 5]

//  Functions
int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
double F(int n, int m) //  [0 ; 1]
{
    double summ = 0;
    for (int k = 0; k <= min(n, m); k++)
    {
        summ +=
                (pow(-1, n - k) * pow(sqrt(S), n + m - 2 * k)) /
                (factorial(k) * factorial(n - k) * factorial(m - k));
    }
    return exp(-S) * factorial(n) * factorial(m) * summ * summ;
}
double Q_shrp(int n, int m)
{
    return L_s + dG_CR + (m - n) * hOmg;
}
double S_solv(const double &hw, const double &t)
{
    double summ = 0;
    for (int m = 0; m <= 20; m++)
    {
        summ += F(n0, m) * exp(
                pow((Q_shrp(n0, m) + hw - 2 * L_s * exp(-t / Tl)), 2) /
                (-4 * L_s * kT));
    }

    return A0 / sqrt(4 * M_PI * kT) * summ;
}
double S_vibr(const double &hw, const double &t)
{
    double summ1 = 0;
    for (int m = 0; m <= 20; m++)
    {
        double tempSumm = 0;
        for (int n = 1; n <= n0; n++)
        {
            tempSumm += pow((t / Tv), (n0 - n)) / (factorial(n0 - n));
        }
        summ1 += F(0, m) * (1. - (exp(-t / Tv) * tempSumm)) *
                 exp(-pow((Q_shrp(0, m) - 2 * L_s + hw), 2) / (4 * L_s * kT));
    }

    double summ2 = 0;
    for (int n = 1; n <= n0; n++)
    {
        for (int m = 0; m <= 20; m++)
        {
            summ2 += F(n, m) * exp(-t / Tv) * pow((t / Tv), (n0 - n)) / (factorial(n0 - n)) *
                     exp(-pow((Q_shrp(0, m) - 2 * L_s + hw), 2) / (4 * L_s * kT));
        }
    }

    return A0 / sqrt(4 * M_PI * L_s * kT) * (summ1 + summ2);
}


int main()
{
    //  Firstly I create QT window with a surface image to visualize S_vibr

    //  1. Create grapher, graph object and arguments
    MathGLGraphics grapher;
    FunctionArg hw(0, 3, 200);
    FunctionArg t(0, 3, 200);
    TwoArgumentsFunction_Surf surface(S_vibr, hw, t);

    //  2.  Set properties. By default there is no rotation, ranges doesnt fit our purpose
    //  and so on
    grapher.setRotation(70, 40, 0);
    grapher.setRanges(0, 3, 0, 3, -1, 3);
    grapher.setXAxisLabel("hw");
    grapher.setYAxisLabel("t");
    grapher.setZAxisLabel("f(hw,t)");
    grapher.setTitle("luminescence spectra");

    //  3.  Add object and Plot !
    //  U can use mouse inside window to change size, location and more
    grapher.add(&surface);
    grapher.plotQT("3D Image");

    //-------------------------------------

    //  Now I `m animating S-solv

    //  1. Create new grapher. We will use the same FunctionArg (hw)
    MathGLGraphics grapher2;

    // 2.  Now in the loop through the second argument (t)
    // I`m going to create frames, objects, set properties (each frame has to be sut up individually)
    // and pass it to the grapher.
    //
    // Attention! Grapher works with pointers, so linking a
    // temporary object will cause a crash. All the Grapher objects should be alive;
    //
    //  I will save objects into a list
    std::list<MathGLGraphicsObject *> objects;
    for (double t = 0; t < 1; t += .1)
    {
        TwoArgumentsFunction_Plot *tmp = new TwoArgumentsFunction_Plot(S_solv, hw, t);
        objects.push_back(tmp);
        grapher2.add(objects.back());
        grapher2.newFrame();
    }

    //  Setting properties
    grapher2.setTitle("S_solv Animation");
    grapher2.setRanges(0,2,0,2);
    grapher2.plotQT("Animation");
    std::list<MathGLGraphicsObject *>::iterator it = objects.begin();

    //  deallocate memory from list
    while (it != objects.end())
    {
        delete *it;
        it++;
    }

    return 0;
}