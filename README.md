# Visualization module based on MathGL library

## Description
These classes written in C++11 provide functions for easy plotting one/two arguments functions using data arrays and syntax parser. Classes are based on  [MathGl library](http://mathgl.sourceforge.net/doc_ru/Main.html#Main) and act like wrappers for the most common MathGl functions to simplify the process of visualization


## Installation
#### Common part

 1. Add source files to your project from the **MathGL_module/src**  and **MathGL_module/include** folders
 2. Install the original  [MathGl library](http://mathgl.sourceforge.net/doc_ru/Main.html#Main) . There is an instruction on the website, how to compile it from source.

#### Linux (Debian based distros) MathGl library installation (lazy way)

 3. Get the MathGL library (version with the QT) installed on the computer using Synaptic Packet Manager. Find **mathgl** and **mathgl-dev** packages and get them
 4. You are ready to go. To compile your program use``g++ your_files_and_compilation_flags functionArg.cpp mathGL_Graphics.cpp mathGL_Graphics_Object.cpp -lmgl -lmgl-qt -std=gnu++11``

#### Windows (Visual Studio) MathGl library installation (lazy way)

 3. You can try to use precompiled binaries form the **Binary versions** folder (from the repo). In this folder you can find versions for the **Visual Studio 2012, 2013, 2015, 2017 under Windows 7**.
 4. Make a C++ project and link it to the MathGl binary version. How to link a library you can easily find on the Internet. Don`t forget to **copy the bin folder contents** to the folder with your executable
 5. Change the build type of your project to **Release** if you use precompiled binaries

## Quick usage guide

 1. Create a plotting object that inherits from **MathGLGraphicsObject**
 2. Create grapher - **MathGLGraphics** 
 3. Setup grapher if needed
 4. Link grapher to the object you are going to plot
 5. Plot with QT window or save to file

**Code example:**

    #include "../include/mathGL_graphics.h"
    #include <cmath>
    #include <list>
    #include <string>
    
    /**
     *
     * Example of plotting one argument function f(x) = sin(x) + 1,
     * x [-10,10],
     * Dots amount : 100
     */
    
    double f(const double &x)
    {
        return sin(x) + 1;
    }
    
    int main()
    {
        MathGLGraphics gr;
        OneArgumentFunction_Plot obj(f, FunctionArg(-10, 10, 100));
    
        gr.parametres()->setRanges(-10, 10, 0, 2);
    
        gr.link(&obj);
        gr.plotQT("sin(x)");
    
        return 0;
    }

**Result:**
![Result](https://github.com/vanyason/MathGl-based-visualization-module/blob/master/Screenshots/example1.png)

## Check the Wiki to find more examples and to understand the project structure

[Visit this one](https://github.com/vanyason/MathGl-based-visualization-module/wiki)


## Known bugs

[Check here](https://github.com/vanyason/MathGl-based-visualization-module/issues)

