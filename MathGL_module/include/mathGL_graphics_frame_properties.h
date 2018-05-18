//
// Created by ivan on 5/15/18.
//

#ifndef MATHGL_MODULE_MATHGL_GRAPHICS_PROPERTIES_H
#define MATHGL_MODULE_MATHGL_GRAPHICS_PROPERTIES_H
#include <mgl2/mgl.h>
#include <memory>

//  Draws Box and Axis
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

class TitleDecorator : public Parameter
{
    std::shared_ptr<Parameter> param;
    const char *titleMessage;
public:
    TitleDecorator(const char *titleMessage, Parameter *param);
    virtual void draw(mglGraph *&gr);
};

class XLabelDecorator : public Parameter
{
    std::shared_ptr<Parameter> param;
    const char *xLabel;
public:
    XLabelDecorator(const char *xLabel, Parameter *param);
    virtual void draw(mglGraph *&gr);
};

class YLabelDecorator : public Parameter
{
    std::shared_ptr<Parameter> param;
    const char *yLabel;
public:
    YLabelDecorator(const char *yLabel, Parameter *param);
    virtual void draw(mglGraph *&gr);
};

class ZLabelDecorator : public Parameter
{
    std::shared_ptr<Parameter> param;
    const char *zLabel;
public:
    ZLabelDecorator(const char *zLabel, Parameter *param);
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
