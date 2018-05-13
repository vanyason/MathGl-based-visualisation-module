//
// Created by ivan on 5/10/18.
//

#ifndef MATHGL_MODULE_MGLGRAPHICS_H
#define MATHGL_MODULE_MGLGRAPHICS_H
#include <mgl2/qt.h>
#include "mathGL_Graphics_Object.h"
#include <list>
#include <string>

/**
 * Visualisation module based on MathGl library.
 * This class is a wrapper of the most common MathGl functions.
 *
 * All the functions can be divided into 3 types:
 * 1) adding objects : funcs to create frames and add graphics to the result image
 * 2) visualisation : func to output image using QT windows or save to file
 * 3) properties : setting axis, ranges, origins, etc...
 *
 * HOWTO use this class:
 * 1)   Create an object that is going to be visualised (instance of MathGLGraphicsObject)
 * 2)   Set properties using setters
 * 3)   Add an object to the graph using the "add" function.
 * 4)   Plot or save image using appropriate methods
 */
class MathGLGraphics : public mglDraw
{
public:
    MathGLGraphics();

    //  Methods to add objects to graphics
    /**
     * Creates new blank frame. All the objects added before stays on the previous frame.
     * All the graph properties remains
     */
    void newFrame();
    /**
     * @param obj pointer to an MathGLGraphicsObject object.
     *
     * Adds graphic to a current frame.
     * MathGLGraphics class doesn`t track the memory allocation and doesn`t provide
     * getters to access data.
     *
     * So DO NOT allocate memory via argument add(new(...)) because of the loss of a pointer.
     *
     * The solution is to pass a reference to an object created before calling;
     */
    void add(const MathGLGraphicsObject *obj);

    //  Methods to visualize graphics
    /**
     * @param windowName Window title
     *
     * Creates QT window with data;
     */
    int plotQT(const char *windowName);
    /**
     * Save image to a bmp file named "'frame_count'_frame.bmp"
     */
    void saveBMP();

    //  Graphics properties
    void setRanges(double x0 = -1., double x1 = 1.,
                   double y0 = -1., double y1 = 1.,
                   double z0 = -1., double z1 = 1.);
    void setOrigin(double x = -1., double y = -1., double z = -1.);
    void setRotation(double x, double y, double z);
    void setTitle(const char *title);
    void setXAxisLabel(const char *message);
    void setYAxisLabel(const char *message);
    void setZAxisLabel(const char *message);
    void setBox(bool state);
    void setAxis(bool state);
private:
    int Draw(mglGraph *gr) override;

    //  List of lists,  where
    //  outer list for frames,
    //  inner list for graphic objects
    std::list<std::list<const MathGLGraphicsObject *>> objectsList;

    //  Properties variables:
    //
    //  Range variables
    double rx0 = -1., rx1 = 1.;
    double ry0 = -1., ry1 = 1.;
    double rz0 = -1., rz1 = 1.;

    //  Origin variables
    bool originIsSet = false;
    double ox = -1., oy = -1., oz = -1.;

    //  Rotation variables
    double rx = 0., ry = 0., rz = 0.;

    //  Title
    const char *titleMessage = "";

    //  Label`s variables
    const char *xlabelMes = "";
    const char *ylabelMes = "";
    const char *zlabelMes = "";

    //  Box, Axis
    bool boxisSet = true, axisIsSet = true;

    //  Save to bmp;
    bool saveImageBMP = false;
};

#endif //MATHGL_MODULE_MGLGRAPHICS_H
