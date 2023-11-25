#include <callback.h>

void frame_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void error_callback(int code, const char* value) {
    glfwTerminate();
}