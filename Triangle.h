
#pragma once
#define GLEW_STATIC
#include <glew.h>

// GLFW 3.x, to handle the OpenGL window
#include <glfw3.h>

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

#include <vector>

// ---- 
#include "Stuff_n_Things.h"

class Triangle
{
public:

	Triangle(Vertex vertex0, Vertex vertex1, Vertex vertex2, ColorDbl colorIn, Direction direc, std::string stringIn);

	~Triangle();

	

	Vertex v0, v1, v2; // vertex
	glm::vec3 e1, e2; // vectors to use when calc normal

	//glm::vec3 normal; // normal :)
	Direction normal;

	ColorDbl color; // color

	std::string type = "";
	
	//Function that checks if you have an intersection point with a triangle when you shoot a ray
	//Set INF (infinity) to 9999999999, make the ray as long as possible to give it a change to intersect
	//sPos is the starting position, direction is a normal 
	bool intersection(glm::vec3 sPos, Direction direction, float &t);
	

};
