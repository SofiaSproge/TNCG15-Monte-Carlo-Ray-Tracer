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

//----
#include "Triangle.h"
#include "Stuff_n_Things.h"


class Scene
{
public:

	Scene();
	
	~Scene();
	std::string itsScene = "itsScene";

	glm::vec3 albedo = glm::vec3(0.8f,0.8f,0.8f);

	void rayIntersection(Ray *ray);
	
	// vector storing all triangles that build upp the scene
	std::vector<Triangle*> sceneRoom;

	std::vector<Triangle*>::iterator pointer;


	void createScene();
	// All vertices for the scene/room
	Vertex v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14;
	

};