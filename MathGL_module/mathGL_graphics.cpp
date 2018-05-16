//
// Created by ivan on 5/10/18.
//

#include "mathGL_graphics.h"
#include <iostream>

MathGLGraphics::MathGLGraphics()
        : objectsList(1), frameParameters(1)
{
    std::list<MathGLGraphicsFrameParametres*>::iterator pt = frameParameters.begin();
    (*pt) = new MathGLGraphicsFrameParametres();
}
MathGLGraphics::~MathGLGraphics()
{
    std::list<MathGLGraphicsFrameParametres*>::iterator pt = frameParameters.begin();
    while(pt!=frameParameters.end())
        delete (*pt++);
}

MathGLGraphicsFrameParametres *MathGLGraphics::parametres()
{
    return frameParameters.back();
}

/*
 * Functions, working with lists,
 */
void MathGLGraphics::newFrame()
{
    objectsList.push_back(std::list<const MathGLGraphicsObject *>());
    frameParameters.push_back(new MathGLGraphicsFrameParametres());
}
void MathGLGraphics::link(const MathGLGraphicsObject *obj)
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
    std::list<MathGLGraphicsFrameParametres*>::iterator pt = frameParameters.begin();

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

        //  Drawing parameters
        (*pt)->draw(gr);

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
        pt++;
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
