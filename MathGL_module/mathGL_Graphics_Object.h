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
 * function with one argument
 */
class OneArgumentFunction : public MathGLGraphicsObject
{
public:
    /**
     * @param f Pointer to function, for example: double sin(double& x) { retrun sin(x); }
     * @param farg Const reference to FunctionArg object
     * @param params String with plot parameters
     * Creates data arrays (MathGl instances) using parameters.
     */
    OneArgumentFunction(double(*f)(const double &arg), const FunctionArg &farg, const char *params = "");
    void draw(mglGraph *&gr) const override;
private:
    double (*f)(const double &arg);
    mglData arg;
    mglData func;
    const char *params;
};

/**
 * Creates single-variable function graph
 * using syntax parser
 */
class OneArgumentFunction_SyntaxParser : public MathGLGraphicsObject
{
public:
    OneArgumentFunction_SyntaxParser(const char *func, const char *params = "");
    void draw(mglGraph *&gr) const override;
private:
    const char *params;
    const char *func;
};

/**
 * Calculates data and prepare graph for
 * function with two argument
 */
class TwoArgumentsFunction : public MathGLGraphicsObject
{
public:
    TwoArgumentsFunction(double (*f)(const double &arg1, const double &arg2),
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

class TwoArgumentsFunction_SyntaxParser : public MathGLGraphicsObject
{
public:
    TwoArgumentsFunction_SyntaxParser(const char *func, const char *params = "");
    void draw(mglGraph *&gr) const override;
private:
    const char *params;
    const char *func;
};

#endif //MATHGL_MODULE_MGLGRAPHICSOBJECT_H
