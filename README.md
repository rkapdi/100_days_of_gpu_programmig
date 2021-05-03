# 100_days_of_gpu_programmig
I am committing to a 100 day challenge where I will learn graphics programming by implementing things from Learn OpenGL by Joey de Vries

How to setup openGL project in Visual Studio:

1. Download the following libraries:

- GLFW
https://www.glfw.org/download.html

-GLAD
https://glad.dav1d.de/

#Installing GLFW & GLAD in VS project

1. Add glad.c as existing item to source fils in solution exploerer.

2. Configure project properties
  - C/C++ drop-down menu:
      General > Additional Include Directories
      Add:
        C:\GL\glfw\include
        C:\GL\glad\include
        
        
  - Linker drop-down menu:
      
      Additional Library Directories entry:
        Navigate to C: > GL > glfw > lib-vc2019
     
      Additional Dependencies:
      Add opengl32.lib; glfw3.lib; glfw3dll.lib
