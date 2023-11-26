#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <callback.h>
#include <loop.h>
#include <logger/logger.h>
#include <logger/defaults.h>
#include <init.h>

int main(void)
{

    bindLogger(&fileLog);
    GLFWwindow* window;
    int initResult;
    initResult = glfwInit();

    /* Initialize the library */
    if (initResult == GL_FALSE) {
        logError(-1, "Failed to initialize GLFW");
        return -1;
    } else if (initResult == GL_TRUE) {
        logInfo("GLFW inited correctly");
    } else {
        logError(-2, "GLFW init returned bogus result");
        return -2;
    }

    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "GFX", NULL, NULL);
    if (window == NULL)
    {
        glfwTerminate();
        logError(-3, "Failed to create window");
        return -3;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
	    logError(-4, "Failed to initialize GLAD");
	    return -4;
    }

    glViewport(0, 0, 800, 600);
    
    glfwSetFramebufferSizeCallback(window, frame_callback);

    init();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        loop(window);

    }

    glfwTerminate();
    return 0;
}
