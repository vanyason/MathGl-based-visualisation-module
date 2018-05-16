//
// Created by ivan on 5/15/18.
//

#ifndef MATHGL_MODULE_MATHGL_GRAPHICS_PROPERTIES_H
#define MATHGL_MODULE_MATHGL_GRAPHICS_PROPERTIES_H
#include <mgl2/mgl.h>
#include <memory>

class Parameter
{
public:
    virtual void draw(mglGraph *&gr);
    virtual ~Parameter();
};

class RangeDecorator : public Parameter
{
    std::shared_ptr<Parameter> param;
    double rx0, rx1;
    double ry0, ry1;
    double rz0, rz1;
public:
    RangeDecorator(double rx0, double rx1,
                   double ry0, double ry1,
                   double rz0, double rz1,
                   Parameter *param);
    virtual void draw(mglGraph *&gr);

};

/**
 * Frame parameters implemented with "Decorator" pattern.
 *
 */
class MathGLGraphicsFrameParametres
{
    Parameter *param;
public:
    MathGLGraphicsFrameParametres();
    ~MathGLGraphicsFrameParametres();

    void draw(mglGraph *&gr);

    void setRanges(double rx0, double rx1,
                   double ry0, double ry1,
                   double rz0, double rz1);
};


#endif //MATHGL_MODULE_MATHGL_GRAPHICS_PROPERTIES_H
