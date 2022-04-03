<h1>Graphics_LW1</h1>
<h3>The first laboratory work on engineering graphics</h3>
<i>Introduction to OpenGL. Creating a window, drawing a point and a triangle.</i>

<h2>Main program</h2>

**1. GLUT initialization**
is performed by the command:
```cpp
  void glutInit(int* argcp, char** argv);
```
The first parameter is a pointer to the number of arguments in the command line, and the second is a pointer to an array of arguments. Usually these values are taken from the main function of the program.

**2. Specifying screen parameters**

_Window size:_

```cpp
  void glutInitWindowSize(int width, int height);
```
The first parameter is the width of the window in pixels, the second is the height of the window in pixels.

_Window position:_
```cpp
void glutInitWindowPosition(int x, int y); 
```
The position of the window being created relative to the upper-left corner of the screen. 

_Information display mode:_
```cpp
void glutInitDisplayMode(unsigned int mode);
```
Set parameters for the window such as: the color model used, the number of different buffers, etc. The command has a single parameter that can be represented by one of the constants or a combination of these constants using a bitwise OR.

**3. Creating window**
```cpp
int glutCreateWindow(const char *title);  
```
This command creates a window with a header that you specify as a parameter and returns the window ID as an int number. This ID is usually used for subsequent operations on this window, such as changing window parameters and closing the window.

**4. Set color**
```cpp
void glClearColor(GLclampf red,
 	GLclampf green,
 	GLclampf blue,
 	GLclampf alpha);
```
Specify the red, green, blue, and alpha values used when the color buffers are cleared. Using RGB color values, the background color of the image window is set.

**5. Redrawing the contents of the window**
```cpp
void glutDisplayFunc(void (*func)(void));
```
After the window into which graphical information will be displayed or, as they say, rendered, is prepared and created, it is necessary to associate with it procedures that will be responsible for displaying graphical information, monitor the size of the window, monitor keystrokes, etc. The very first and most necessary function is responsible for drawing. It will always be called by the operating system to draw (redraw) the contents of the window.

The only parameter of this function is a pointer to the function that will be responsible for drawing in the window. In our example, this function takes a pointer to the function RenderSceneCB().

**6. Entering the main GLUT loop**
```cpp
void glutMainLoop(void);
```
The main GLUT loop launches the so-called GLUT heart, which provides the relationship between the operating system and those functions that are responsible for the window, receive information from input/output devices.

<h3>Working with buffers</h3>

```cpp
glGenBuffer(1, &VBO);
```
Creating a "general type" buffer. The first argument defines the number of objects that you want to create, and the second is a reference to an array of GLuints type to store a pointer by which data will be stored. In the program, we created **GLuint VBO** as a global variable to store a pointer to the vertex buffer.

```cpp
glBindBuffer(GL_ARRAY_BUFFER, VBO);
```
Here we sort of indicate the purpose of using the buffer. Now VBO is a buffer that will store an array of vertices.

```cpp
glDataBuffer(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
```
Now we need to fill the object with data. The call above takes the name of the target (the same as when binding), the size of the data in bytes, the address of the vertex array, and a flag that indicates the use of patterns for this data. Since we are not going to change the buffer values, we specify **GL_STATIC_DRAW**.

<h2>Callback-function RenderSceneCB()</h2>

```cpp
glClear (GL_COLOR_BUFFER_BIT); 
```
The glClearColor command assigns a color to the image window, but does not put it on the screen. To see the image window on the screen, you need to call the glClear function. The argument of the **GL_COLOR_BUFFER_BIT** function is an OpenGL character constant indicating that the color buffer (regeneration buffer) contains the values of the bits that should be assigned to the variables specified in the glClearColor function.

```cpp
glEnableVertexAttribArray(0);  
```
With this function, we allow the use of vertex attributes. In our case, we use only the coordinates used in the buffer, which are treated as an attribute of a vertex with index 0.

```cpp
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); 
```
This call tells the pipeline how to perceive the data inside the buffer. The first parameter indicates the attribute index. In our case, we know that it is 0 by default. The second parameter is the number of components in the attribute (3 for X, Y and Z). The third parameter is the data type for each component. The fourth is whether we want to normalize attributes before using them in the pipeline. In our case, we want the data to be transmitted not by name. The fifth parameter is the number of bytes between 2 instances of the attribute. Since we store only one attribute (for example, the buffer stores only vertex coordinates) and the data is tightly packed, we pass a null value. The last parameter is the offset in the structure that our pipeline will receive.

```cpp
glDrawArrays(GL_POINTS, 0, 1);  
```
This is an ordinal rendering function. Accepts the data type, index of the first vertex and their number. The GPU bypasses the vertex buffer by passing through the vertices one by one and interprets them according to the type specified in the function call.

```cpp
glDisableVertexAttribArray(0);   
```
Disabling vertex attributes after using them is a good tone

```cpp
glutSwapBuffers();
```
This function asks GLUT to swap the background buffer and the frame buffer. In the next call, the render will occur in the current frame buffer, and the background buffer will be displayed.
