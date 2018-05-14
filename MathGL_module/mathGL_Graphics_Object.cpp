//
// Created by ivan on 5/10/18.
//

#include "mathGL_Graphics_Object.h"

/*
 * MathGLGraphicsObject
 */
MathGLGraphicsObject::~MathGLGraphicsObject()
{}

/*
 * OneArgumentFunction_Plot
 */
OneArgumentFunction_Plot::OneArgumentFunction_Plot(double (*f)(const double &),
                                                   const FunctionArg &farg,
                                                   const char *params) :
        f(f), arg(farg.N), func(farg.N), params(params)
{
    //  Filling arrays (mglData instances) with data
    double x = farg.v0;
    for (int i = 0; i < farg.N; i++)
    {
        arg.a[i] = x;
        func.a[i] = f(x);
        x += farg.h;
    }
}
void OneArgumentFunction_Plot::draw(mglGraph *&gr) const
{
    gr->Plot(arg, func, params);
}

/*
 * OneArgumentFunction_Plot_SyntaxParser
 */
OneArgumentFunction_Plot_SyntaxParser::OneArgumentFunction_Plot_SyntaxParser(const char *func, const char *params) :
        params(params), func(func)
{}
void OneArgumentFunction_Plot_SyntaxParser::draw(mglGraph *&gr) const
{
    gr->FPlot(func, params);
}

/*
 * TwoArgumentsFunction_Plot
 */
TwoArgumentsFunction_Plot::TwoArgumentsFunction_Plot(double (*f)(const double &, const double &),
                                                     const FunctionArg &farg1,
                                                     const double &arg2,
                                                     const char *params) :
        f(f), arg(farg1.N), func(farg1.N), params(params)
{
    double x = farg1.v0;
    for (int i = 0; i < farg1.N; i++)
    {
        arg.a[i] = x;
        func.a[i] = f(x, arg2);
        x += farg1.h;
    }
}
void TwoArgumentsFunction_Plot::draw(mglGraph *&gr) const
{
    gr->Plot(arg, func, params);
}

/*
 * TwoArgumentsFunction_Surf
 */
TwoArgumentsFunction_Surf::TwoArgumentsFunction_Surf(double (*f)(const double &, const double &),
                                                     const FunctionArg &farg1,
                                                     const FunctionArg &farg2,
                                                     const char *params) :
        f(f), arg1(farg1.N), arg2(farg2.N),
        func(farg1.N, farg2.N), params(params)
{
    double it = farg1.v0;
    for (int i = 0; i < farg1.N; i++)
    {
        arg1.a[i] = it;
        it += farg1.h;
    }

    it = farg2.v0;
    for (int i = 0; i < farg2.N; i++)
    {
        arg2.a[i] = it;
        it += farg2.h;
    }

    for (int i = 0; i < farg1.N; i++)
        for (int j = 0; j < farg2.N; j++)
            func.a[i + farg1.N * j] = f(arg1.a[i], arg2.a[j]);

}
void TwoArgumentsFunction_Surf::draw(mglGraph *&gr) const
{
    gr->Surf(arg1, arg2, func, params);
}

/*
 * TwoArgumentsFunction_Surf_SyntaxParser
 */
TwoArgumentsFunction_Surf_SyntaxParser::TwoArgumentsFunction_Surf_SyntaxParser(const char *func, const char *params) :
        params(params), func(func)
{}
void TwoArgumentsFunction_Surf_SyntaxParser::draw(mglGraph *&gr) const
{
    gr->FSurf(func, params);
}
