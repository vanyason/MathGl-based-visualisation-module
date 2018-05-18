//
// Created by ivan on 5/15/18.
//

#include "../include/mathGL_graphics_frame_properties.h"
#include <iostream>

/*
 * Base component
 */
void Parameter::draw(mglGraph *&gr)
{
    gr->Axis();
    gr->Box();
}
Parameter::~Parameter()
{ std::cout << "dest" << std::endl; }
/*
 * Decorators :
 */
//  Ranges
RangeDecorator::RangeDecorator(double rx0, double rx1,
                               double ry0, double ry1,
                               double rz0, double rz1,
                               Parameter *param) :
        rx0(rx0), rx1(rx1), ry0(ry0), ry1(ry1), rz0(rz0), rz1(rz1), param(param)
{}
void RangeDecorator::draw(mglGraph *&gr)
{
    gr->SetRanges(rx0, rx1, ry0, ry1, rz0, rz1);
    param->draw(gr);
}

//  Rotation
RotationDecorator::RotationDecorator(double rotx, double roty, double rotz, Parameter *param) :
        rotx(rotx), roty(roty), rotz(rotz), param(param)
{}
void RotationDecorator::draw(mglGraph *&gr)
{
    param->draw(gr);
    gr->Rotate(rotx, roty, rotz);
}
//  Origin
OriginDecorator::OriginDecorator(double ox, double oy, double oz, Parameter *param) :
        ox(ox), oy(oy), oz(oz), param(param)
{}
void OriginDecorator::draw(mglGraph *&gr)
{
    param->draw(gr);
    gr->SetOrigin(ox, oy, oz);
}

//  Title
TitleDecorator::TitleDecorator(const char *titleMessage, Parameter *param) :
        titleMessage(titleMessage), param(param)
{}
void TitleDecorator::draw(mglGraph *&gr)
{
    param->draw(gr);
    gr->Title(titleMessage);
}

//  XLabel
XLabelDecorator::XLabelDecorator(const char *xLabel, Parameter *param) :
        xLabel(xLabel), param(param)
{}
void XLabelDecorator::draw(mglGraph *&gr)
{
    param->draw(gr);
    gr->Label('x', xLabel);
}

//  YLabel
YLabelDecorator::YLabelDecorator(const char *yLabel, Parameter *param) :
        yLabel(yLabel), param(param)
{}
void YLabelDecorator::draw(mglGraph *&gr)
{
    param->draw(gr);
    gr->Label('y', yLabel);
}

//  ZLabel
ZLabelDecorator::ZLabelDecorator(const char *zLabel, Parameter *param) :
        zLabel(zLabel), param(param)
{}
void ZLabelDecorator::draw(mglGraph *&gr)
{
    param->draw(gr);
    gr->Label('z', zLabel);
}

/*
 * Parametres object
 */
MathGLGraphicsFrameParametres::MathGLGraphicsFrameParametres()
{
    param = new Parameter();
}
MathGLGraphicsFrameParametres::~MathGLGraphicsFrameParametres()
{
    delete param;
}
void MathGLGraphicsFrameParametres::draw(mglGraph *&gr)
{
    param->draw(gr);
}
void MathGLGraphicsFrameParametres::setRanges(double rx0, double rx1, double ry0, double ry1, double rz0, double rz1)
{
    param = new RangeDecorator(rx0, rx1, ry0, ry1, rz0, rz1, param);
}
void MathGLGraphicsFrameParametres::setRotation(double rotx, double roty, double rotz)
{
    param = new RotationDecorator(rotx, roty, rotz, param);
}
void MathGLGraphicsFrameParametres::setOrigin(double ox, double oy, double oz)
{
    param = new OriginDecorator(ox, oy, oz, param);
}
void MathGLGraphicsFrameParametres::setTitle(const char *titleMessage)
{
    param = new TitleDecorator(titleMessage, param);
}
void MathGLGraphicsFrameParametres::setXLabel(const char *xLabel)
{
    param = new XLabelDecorator(xLabel, param);
}
void MathGLGraphicsFrameParametres::setYLabel(const char *yLabel)
{
    param = new XLabelDecorator(yLabel, param);
}
void MathGLGraphicsFrameParametres::setZLabel(const char *zLabel)
{
    param = new XLabelDecorator(zLabel, param);
}
