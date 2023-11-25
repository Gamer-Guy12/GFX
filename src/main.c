#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <callback.h>
#include <loop.h>

int main(void)
{

    GLFWwindow* window;
    int initResult;
    initResult = glfwInit();

    /* Initialize the library */
    if (initResult == GL_FALSE) {
        printf("Failed to initialize GLFW\n");
        return -1;
    } else if (initResult == GL_TRUE) {
        printf("GLFW inited correctly\n");
    } else {
        printf("GLFW init returned bogus result\n");
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
        printf("Failed to create window\n");
        return -3;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
	    printf("Failed to initialize GLAD\n");
	    return -4;
    }

    glViewport(0, 0, 800, 600);
    
    glfwSetFramebufferSizeCallback(window, frame_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        loop(window);

    }

    glfwTerminate();
    return 0;
}
