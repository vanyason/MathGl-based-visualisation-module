//
// Created by ivan on 5/15/18.
//

#include "mathGL_graphics_frame_properties.h"

/*
 * Base component
 */
void Parameter::draw(mglGraph *&gr)
{
    gr->Axis();
    gr->Box();
}
Parameter::~Parameter()
{}
/*
 * Decorators :
 */
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
