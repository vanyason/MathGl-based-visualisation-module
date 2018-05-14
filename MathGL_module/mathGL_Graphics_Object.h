//
// Created by ivan on 5/10/18.
//

#ifndef MATHGL_MODULE_MGLGRAPHICSOBJECT_H
#define MATHGL_MODULE_MGLGRAPHICSOBJECT_H
#include <mgl2/mgl.h>
#include "functionArg.h"

/**
 * Interface with abstract function draw() and virtual destructor;
 * This class is used in MathGLGraphics
 */
class MathGLGraphicsObject
{
public:
    virtual ~MathGLGraphicsObject();
    /**
     * @param gr mglGraph instance
     * Function is used inside int MathGlGraphics::Draw(mglGraph *gr) to plot graph
     */
    virtual void draw(mglGraph *&gr) const = 0;
};

/**
 * Calculates data and prepare graph for
 * function with one argument (2d Image)
 */
class OneArgumentFunction_Plot : public MathGLGraphicsObject
{
public:
    /**
     * @param f Pointer to function, for example: double sin(const double& x) { retrun sin(x); }
     * @param FunctionArg object (arg1)
     * @param params String with plot parameters
     * Creates data arrays (MathGl instances) using parameters.
     */
    OneArgumentFunction_Plot(double(*f)(const double &arg), const FunctionArg &farg, const char *params = "");
    void draw(mglGraph *&gr) const override;
private:
    double (*f)(const double &arg);
    mglData arg;
    mglData func;
    const char *params;
};

/**
 * Creates single-variable function graph
 * using syntax parser (2d Image)
 */
class OneArgumentFunction_Plot_SyntaxParser : public MathGLGraphicsObject
{
public:
    OneArgumentFunction_Plot_SyntaxParser(const char *func, const char *params = "");
    void draw(mglGraph *&gr) const override;
private:
    const char *params;
    const char *func;
};


/**
 * Calculates data and prepare graph for
 * function with two argument (2d Image)
 *
 * This object is a mix of OneArgumentObject and TwoArgumentsObject:
 * It plots 2d Image of two args at the certain moment (like a snapshot),
 * so one arg is changing and represented as a FunctionArg object and other one
 * is constant and represented as a double variable
 */
class TwoArgumentsFunction_Plot : public MathGLGraphicsObject
{
public:
    /**
     *
     * @param f Pointer to a function, for example: double f (const double &x, const double &y) { return sin(x) + y; }
     * @param farg1 FunctionArg object arg1
     * @param arg2 constant value of arg2
     * @param params String with plot parameters
     * Creates data arrays (MathGl instances) using parameters.
     */
    TwoArgumentsFunction_Plot(double (*f)(const double &arg1, const double &arg2),
                              const FunctionArg &farg1, const double &arg2,
                              const char *params = "");
    void draw(mglGraph *&gr) const override;
private:
    double (*f)(const double &arg1, const double &arg2);
    mglData arg;
    mglData func;
    const char *params;
};


/**
 * Calculates data and prepare graph for
 * function with two argument (3d Image)
 */
class TwoArgumentsFunction_Surf : public MathGLGraphicsObject
{
public:
    /**
     *
     * @param f Pointer to a function, for example: double f (const double &x, const double &y) { return sin(x) + y; }
     * @param farg1 FunctionArg object arg1
     * @param farg2 FunctionArg object arg2
     * @param params String with plot parameters
     * Creates data arrays (MathGl instances) using parameters.
     */
    TwoArgumentsFunction_Surf(double (*f)(const double &arg1, const double &arg2),
                              const FunctionArg &farg1, const FunctionArg &farg2,
                              const char *params = "");
    void draw(mglGraph *&gr) const override;
private:
    double (*f)(const double &arg1, const double &arg2);
    mglData arg1;
    mglData arg2;
    mglData func;
    const char *params;
};

/**
 * Creates two-variable function graph
 * using syntax parser (3d Image)
 */
class TwoArgumentsFunction_Surf_SyntaxParser : public MathGLGraphicsObject
{
public:
    TwoArgumentsFunction_Surf_SyntaxParser(const char *func, const char *params = "");
    void draw(mglGraph *&gr) const override;
private:
    const char *params;
    const char *func;
};

#endif //MATHGL_MODULE_MGLGRAPHICSOBJECT_H
