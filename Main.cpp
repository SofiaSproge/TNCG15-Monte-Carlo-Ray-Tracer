#define GLEW_STATIC

//#include <glew.h>

// GLFW 3.x, to handle the OpenGL window
//#include <glfw3.h>

// File and console I/O for logging and error reporting
#include <iostream>
// Math header for trigonometric functions
#include <cmath>

// another thing instead of GLFW
#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x2.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>


#include "Triangle.h"
#include "Stuff_n_Things.h"
#include "Camera.h"


int main(void)
{


	std::cout << "Creating Camera in Main" << std::endl;

	Camera* myCamera = new Camera();


	return 0;
}


