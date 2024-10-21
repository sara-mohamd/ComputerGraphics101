# OpenGL Sample Programs

  

This repository contains three basic OpenGL programs written in C using the `GLUT` library.

  

## Requirements

  

To compile and run these programs, you need to have OpenGL and GLUT installed on your system. Below are the general steps to install these libraries on Linux. For other platforms, please refer to the appropriate instructions.

  

### Linux Installation

```bash

sudo apt-get update

sudo apt-get install freeglut3 freeglut3-dev

sudo apt-get install binutils-gold

sudo apt-get install g++ cmake

```

  

### Compilation and Execution

  

```bash

g++ filename.cpp -o outputname -lGL -lGLU -lglut

```

  

Replace `filename.cpp` with the corresponding file name and `outputname` with the desired output name. For example:

  

```bash

g++ main.cpp -o a.exe -lGL -lGLU -lglut

./blank

```

  

### Program 1: Blank Window

  

#### Description

This program creates a blank OpenGL window with a specified background color. It sets up the display mode to support double buffering, RGB color, and depth testing.

  

#### Code

```CPP

#include <GL/glut.h>

  

void dispaly() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();

}

  

int main(int argc, char **argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

  

    glutInitWindowPosition(50, 50);

    glutInitWindowSize(500, 500);

    glutCreateWindow("Blank Window");

  

    glClearColor(0.6, 0.4, 1.0, 0.0);

    glutDisplayFunc(dispaly);

    glutMainLoop();

}

```

#### Key Functions

- `glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)`: Clears specific buffers before rendering a new frame. Here's a breakdown of the parameters:

	- **`GL_COLOR_BUFFER_BIT`**: This flag clears the **color buffer**, which stores the colors for all the pixels on the screen. Clearing this buffer ensures that the screen starts with a fresh frame, typically filling it with the background color set by `glClearColor()`.
    
	- **`GL_DEPTH_BUFFER_BIT`**: This flag clears the **depth buffer**, which is used to keep track of the depth (or distance) of objects in the scene. The depth buffer helps render objects in the correct order, with nearer objects obscuring those farther away. Clearing it ensures that old depth values don’t interfere with the new frame being rendered.


- `glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH)`: Sets the initial display mode for the GLUT window, specifying how the frame buffer should be configured. Here's a breakdown of the parameters:
	
	-  **`GLUT_DOUBLE`**: Enables **double buffering**, which means two buffers (front and back) are used for rendering. The scene is drawn in the back buffer and then swapped to the front buffer to be displayed, reducing flickering and making animations smoother.
    
	- **`GLUT_RGBA`**: Specifies that the color mode for the window should use the **RGBA color model**, which includes red, green, blue, and alpha channels. This allows for color representation and transparency.
    
	- **`GLUT_DEPTH`**: Enables a **depth buffer** (also known as a z-buffer). The depth buffer is used to keep track of the depth of objects in the scene, allowing for proper rendering of 3D scenes where objects are behind or in front of others.


- `glutInit`: Initializes the GLUT library.

- `glutCreateWindow(("Window name")`:Creates a window

- `glClearColor(red, green, blue, alpha)`: Sets the window background color.

- `glutDisplayFunc(display)`: Registers the display callback function.
	- Here, the `display` function will be called whenever GLUT needs to update the window content. Inside the `display` function, you'll typically clear the buffers, draw the objects (like points or lines), and swap buffers if using double buffering.