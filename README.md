# Visualization module based on MathGL library

## Description
These classes written in C++11 provide functions for easy plotting one/two arguments functions using data arrays and syntax parser. Classes are based on  [MathGl library](http://mathgl.sourceforge.net/doc_ru/Main.html#Main) and act like wrappers for the most common MathGl functions to simplify the process of visualization


## Installation

#### Linux (Debian based distros)

 1. Get the MathGL library (version with the QT) installed on the computer. To do this, you can try Synaptic Packet Manager to find **mathgl** and **mathgl-dev** packages. Other way is to get  MathGL and compile with CMake building tool from [sources](http://mathgl.sourceforge.net/doc_ru/Main.html#Main) 
 2. Clone the repo and copy files from the directory **MathGL_module** to your project
 3. You are ready to go. To compile your program use``g++ your_files_and_compilation_flags functionArg.cpp mathGL_Graphics.cpp mathGL_Graphics_Object.cpp -lmgl -lmgl-qt -std=gnu++11``

#### Windows (Visual Studio)

 1. You have to get MathGL library first as well. You can compile it using CMake building system from sources for your version of the Visual Studio. The other way you can try to use precompiled binaries form the **Binary versions** folder (from the repo). In this folder you can find versions for the **Visual Studio 2012, 2013, 2015, 2017 under Windows 7**.
 2. Make a C++ project and link it to the MathGl binary version. How link library you can easily find on the Internet. Don`t forget to **copy the bin folder contents** to the folder with your executable
 3. Copy the module source files to your project and  change the build type of your project to **Release** if you use precompiled binaries

## Quick usage guide

 1. Create a plotting object that inherits from **MathGLGraphicsObject**
 2. Create grapher - **MathGLGraphics** 
 3. Setup grapher if needed
 4. Link grapher to the object you are going to plot
 5. Plot with QT window or save to file

**Code example:**

    int main()
    {
    //  Creating QT window with a surface image to visualize S_vibr function
    //	Prototype is below:
    //	double S_vibr(const double& hw , const double& t) {
    //	    double s_vibr; /*some calc*/ return s_vibr; }

    //  1. Create grapher, graph object and arguments
    MathGLGraphics grapher;
    FunctionArg hw(0, 3, 200);
    FunctionArg t(0, 3, 200);
    TwoArgumentsFunction_Surf surface(S_vibr, hw, t);

    //  2.  Set properties. By default there is no rotation, ranges doesnt fit our purpose
    //  and so on
    grapher.setRotation(70, 40, 0);
    grapher.setRanges(0, 3, 0, 3, -1, 3);
    grapher.setXAxisLabel("hw");
    grapher.setYAxisLabel("t");
    grapher.setZAxisLabel("f(hw,t)");
    grapher.setTitle("luminescence spectra");

    //  3.  Add object and Plot !
    //  U can use mouse inside window to change size, location and more
    grapher.add(&surface);
    grapher.plotQT("3D Image");
    return 0;
    }

**Result:**
![enter image description here](https://lh3.googleusercontent.com/Z-Eoy41zhQZWLhijiupwMX4WIJVePth-zYUD_dHyNDDlstHoDVBQKXzi0aDePFckRnUvkMggZx4R "3d Image")



## Known bugs

 - Sometimes setRanges() function causes program crash. This problem is inherited from original MathGL library. To avoid crash - change ranges just a little bit, so it doesn`t really affect your plot

