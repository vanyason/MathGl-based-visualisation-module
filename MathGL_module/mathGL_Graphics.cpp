//
// Created by ivan on 5/10/18.
//

#include "mathGL_Graphics.h"
#include <iostream>

MathGLGraphics::MathGLGraphics()
        : objectsList(1)
{}

/*
 * Functions, working with lists,
 */
void MathGLGraphics::newFrame()
{
    objectsList.push_back(std::list<const MathGLGraphicsObject *>());
}
void MathGLGraphics::add(const MathGLGraphicsObject *obj)
{
    objectsList.back().push_back(obj);
}

/*
 * Visualisation funcs
 */
int MathGLGraphics::Draw(mglGraph *gr)
{
    //  Iterator that goes through outer list,
    //  which represents frames
    std::list<std::list<const MathGLGraphicsObject *>>::iterator jt = objectsList.begin();

    //  Iterator, which goes though inner list,
    //  which represents MathGLGraphicObjects in a frame
    std::list<const MathGLGraphicsObject *>::iterator it;

    //  Loop which goes through frames and draws
    //  all the object in the frame
    //  (outer list = frames, inner list = objects)
    while (jt != objectsList.end())
    {
        it = jt->begin();

        //  Creating fame
        gr->NewFrame();

        //  Setting properties
        gr->Title(titleMessage);

        gr->SetRanges(rx0, rx1, ry0, ry1, rz0, rz1);
        if (originIsSet)
            gr->SetOrigin(ox, oy, oz);
        gr->Rotate(rx, ry, rz);
        gr->Label('x', xlabelMes);
        gr->Label('y', ylabelMes);
        gr->Label('z', zlabelMes);
        if (boxisSet)
            gr->Box();
        if (axisIsSet)
            gr->Axis();

        //  Drawing graph objects
        while (it != jt->end())
        {
            (*it)->draw(gr);
            it++;
        }

        //  Saving to file if necessary
        static int frameCount = 0;
        if (saveImageBMP)
        {
            gr->WriteBMP((std::to_string(frameCount) + "_frame.bmp").c_str());
            frameCount++;
        }

        //  End of the frame;
        gr->EndFrame();
        jt++;
    }
    return gr->GetNumFrame();
}
int MathGLGraphics::plotQT(const char *windowName)
{
    mglQT gr(this, windowName);
    return gr.Run();
}
void MathGLGraphics::saveBMP()
{
    saveImageBMP = true;
    mglGraph gr;
    Draw(&gr);
    saveImageBMP = false;
}

/*
 * Properties
 */
void MathGLGraphics::setRanges(double x0, double x1, double y0, double y1, double z0, double z1)
{
    rx0 = x0;
    rx1 = x1;
    ry0 = y0;
    ry1 = y1;
    rz0 = z0;
    rz1 = z1;
}
void MathGLGraphics::setOrigin(double x, double y, double z)
{
    originIsSet = true;
    ox = x;
    oy = y;
    oz = z;
}
void MathGLGraphics::setRotation(double x, double y, double z)
{
    rx = x;
    ry = y;
    rz = z;
}
void MathGLGraphics::setTitle(const char *title)
{
    titleMessage = title;
}
void MathGLGraphics::setXAxisLabel(const char *message)
{
    xlabelMes = message;
}
void MathGLGraphics::setYAxisLabel(const char *message)
{
    ylabelMes = message;
}
void MathGLGraphics::setZAxisLabel(const char *message)
{
    zlabelMes = message;
}
void MathGLGraphics::setBox(bool state)
{
    boxisSet = state;
}
void MathGLGraphics::setAxis(bool state)
{
    axisIsSet = state;
}
