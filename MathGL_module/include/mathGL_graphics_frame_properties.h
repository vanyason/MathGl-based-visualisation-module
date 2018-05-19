//
// Created by ivan on 5/15/18.
//

#ifndef MATHGL_MODULE_MATHGL_GRAPHICS_PROPERTIES_H
#define MATHGL_MODULE_MATHGL_GRAPHICS_PROPERTIES_H
#include <mgl2/mgl.h>
#include <memory>

/**
 * Frame Parameters diagram:
 *
 *  ---------------------------------                 ------------
 *  | MathGLGraphicsFrameParametres |      has       | Parameter |
 *  ---------------------------------     ----->     ------------
 *
 *                                                         |
 *                                             (extends)   |
 *                                                         |
 *                                                        \/
 *                                                   ---------------
 *                                                  | Decorators * |
 *                                                  ---------------
 *  Description:
 *  MathGLGraphicsFrameParametres works as a controller. Class provides setters,
 *  that create new Decorator objects. Function "draw" delegates func. call to the
 *  decorator
 */

/**
 * Concrete Parameter that draws Axis and Box
 */
class Parameter
{
public:
    virtual void draw(mglGraph *&gr);
    virtual ~Parameter();
};

/**
 * Adds Ranges to the existing parameter
 */
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
 * Adds Rotation to the existing parameter
 */
class RotationDecorator : public Parameter
{
    std::shared_ptr<Parameter> param;
    double rotx;
    double roty;
    double rotz;
public:
    RotationDecorator(double rotx, double roty, double rotz, Parameter *param);
    virtual void draw(mglGraph *&gr);
};

/**
 * Adds Origin to the existing parameter
 */
class OriginDecorator : public Parameter
{
    std::shared_ptr<Parameter> param;
    double ox;
    double oy;
    double oz;
public:
    OriginDecorator(double ox, double oy, double oz, Parameter *param);
    virtual void draw(mglGraph *&gr);
};

/**
 * Adds Title to the existing parameter
 */
class TitleDecorator : public Parameter
{
    std::shared_ptr<Parameter> param;
    const char *titleMessage;
public:
    TitleDecorator(const char *titleMessage, Parameter *param);
    virtual void draw(mglGraph *&gr);
};

/**
 * Adds x axis Label to the existing parameter
 */
class XLabelDecorator : public Parameter
{
    std::shared_ptr<Parameter> param;
    const char *xLabel;
public:
    XLabelDecorator(const char *xLabel, Parameter *param);
    virtual void draw(mglGraph *&gr);
};

/**
 * Adds y axis Label to the existing parameter
 */
class YLabelDecorator : public Parameter
{
    std::shared_ptr<Parameter> param;
    const char *yLabel;
public:
    YLabelDecorator(const char *yLabel, Parameter *param);
    virtual void draw(mglGraph *&gr);
};

/**
 * Adds z axis Label to the existing parameter
 */
class ZLabelDecorator : public Parameter
{
    std::shared_ptr<Parameter> param;
    const char *zLabel;
public:
    ZLabelDecorator(const char *zLabel, Parameter *param);
    virtual void draw(mglGraph *&gr);
};


/**
 * Class-Controller, where setters wrap existing parameter with decorators
 * and "draw" function delegates func. calls to the Parameter. *
 */
class MathGLGraphicsFrameParametres
{
    Parameter *param;
public:
    MathGLGraphicsFrameParametres();
    ~MathGLGraphicsFrameParametres();

    void draw(mglGraph *&gr);

    void setRanges(double rx0, double rx1 = 1,
                   double ry0 = -1, double ry1 = 1,
                   double rz0 = -1, double rz1 = 1);
    void setRotation(double rotx, double roty = 0, double rotz = 0);
    void setOrigin(double ox, double oy, double oz);
    void setTitle(const char *titleMessage);
    void setXLabel(const char *xLabel);
    void setYLabel(const char *yLabel);
    void setZLabel(const char *zLabel);
};

#endif //MATHGL_MODULE_MATHGL_GRAPHICS_PROPERTIES_H
