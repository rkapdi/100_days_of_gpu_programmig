#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{


    glfwInit();



    // define the function's prototype
    typedef void (*GL_GENBUFFERS) (GLsizei, GLuint*);
    // find the function and assign it to a function pointer
    GL_GENBUFFERS glGenBuffers = (GL_GENBUFFERS)wglGetProcAddress("glGenBuffers");
    // function can now be called as normal
    unsigned int buffer;
    glGenBuffers(1, &buffer);

    /*
    * Configure GLFW
    * arg1: which option to config
    *   where we can select from large enum of possible GLFW_ options
    * arg2: Integer which sets value of option
    * setting both major & minor ver to 3
    */
   
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //telling GLFW to use core profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    //Creating a window
    
    /*
    * function return a GLFWwindow object
    */
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    /*
    GLAD manages function pointers to OpenGL, init before using OpenGL funcs
    pass GLAD the function to load the address of the OpenGL function
    pointers which is OS-specific

    GLFW gives glfwGetProcAddress w/c defs correct func based on curr OS
    */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //ViewPort
    //tell OpenGL the size of the rendering window

    /*
    firs two params: location of the lower left corner of the window
    last two parsms: set w & h of  rendering window in pixels,
    which we set equal to GLFW's window size
    */
    glViewport(0, 0, 800, 600);

    /*
    NOTE ABOUT VIEWPORTS:
        viewport dimensions can be smaller than GLFW dimensions
        then all objs rendering will be  displayed in a smaller window 
        and we could display other elements outside the OpenGL viewport.
    */



    //tell GLFW to call this func on every wind resize by registering it
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    while (!glfwWindowShouldClose(window))
    {
        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

//to make the window responsive
/*
 Whenever the window changes in size, GLFW calls this function
 and fills in the proper arguments for you to process.
*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
