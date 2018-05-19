#include "include/mathGL_graphics.h"
#include <cmath>
#include <list>
#include <string>


/**********************************************************
 * This code is an example of MathGl_Graphics module usage.
 * Module is used to visualize dynamics of luminescence
 * spectra. All the equations can be found at:
 *
 **********************************************************
 * Basics are explained on github/WIKI :
 * https://github.com/vanyason/MathGl-based-visualisation-module/wiki
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
template<class T>
const T &min(const T &a, const T &b)
{
    return !(b < a) ? a : b;
}
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

//  I: Plotting S_solv surface
void example1()
{
    //  1) Creating objects;
    FunctionArg hw(0, 3, 200);
    FunctionArg t(0, 3, 200);
    TwoArgumentsFunction_Surf surface(S_vibr, hw, t);
    MathGLGraphics grapher;

    //  2) Setting properties
    grapher.parametres()->setRanges(0,3,0,3,0,3);
    grapher.parametres()->setRotation(70,45);
    grapher.parametres()->setXLabel("hw");
    grapher.parametres()->setYLabel("t");
    grapher.parametres()->setTitle("F(hw, t)");

    //  3) Link and plot
    grapher.link(&surface);
    grapher.plotQT("S_vibr");
}

//  II: Plotting S_vibr animation

void example2()
{
    //  1) Creating objects;
    FunctionArg hw(0, 3, 200);
    double t = 0;
    MathGLGraphics grapher;
    std::list<TwoArgumentsFunction_Plot> frames_with_objs;    //  Objects have to be stored outside the grapher

    //  2) Animation loop, where setting properties and linking
    for(t = 0; t < 3; t += 0.5)
    {
        frames_with_objs.push_back(TwoArgumentsFunction_Plot(S_solv,hw,t));

        grapher.parametres()->setTitle((std::to_string(t).c_str()));
        grapher.parametres()->setRanges(0,3,0,3,0,3);
        grapher.parametres()->setXLabel("hw");
        grapher.parametres()->setYLabel("t");


        grapher.link(&frames_with_objs.back());

        grapher.newFrame();
    }

    //  3) Plot
    grapher.plotQT("S_solv");
}
int main()
{
    example1();
    example2();

    return 0;
}
