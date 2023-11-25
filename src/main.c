#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>


void frame_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void error_callback(int code, const char* value) {
    glfwTerminate();
}

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

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
