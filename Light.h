
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

//----
#include "Triangle.h"
#include "Stuff_n_Things.h"


//make it lambertian
class Light
{

public:

	std::string itsLamp = "itsLamp";
	std::vector<Triangle*> lightVec;
	std::vector<Triangle*>::iterator lightP;
	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	

	Vertex vL1 = Vertex(7.0f, 1.5f, -4.999f, 1.0);
	Vertex vL2 = Vertex(10.0f, 1.5f, -4.999f, 1.0);
	Vertex vL3 = Vertex(10.0f, -1.5f, -4.999f, 1.0);
	Vertex vL4 = Vertex(7.0f, -1.5f, -4.999f, 1.0);

	glm::vec3 albedo = glm::vec3(1.0f, 1.0f, 1.0f);


	//Create local or world coordinates

	Light() {
		createLight();
		//std::cout << "Creating Tetrahedron" << std::endl;

	}

	void createLight() {
		lightVec.push_back(new Triangle(vL1, vL2, vL3, glm::vec3(1.0f, 1.0f, 1.0f), Direction(), itsLamp)); //w1
		lightVec.push_back(new Triangle(vL1, vL3, vL4, glm::vec3(1.0f, 1.0f, 1.0f), Direction(), itsLamp)); //w1
		
	}

	~Light() {

		for (lightP = lightVec.begin(); lightP != lightVec.end(); ++lightP) {
			delete (*lightP);
		}
		lightVec.clear();

	}

	void rayIntersection(Ray* ray) {

		std::vector<Triangle*>::iterator lightP2;
		
		//std::cout << "Inside RayIntersection in Tetrahederon.h" << std::endl;
		float rayLength = INFINITY;

		glm::vec3 intersectedP;

		//Triangle intersection wants startpos direction and t
		//We need a for loop to go through the vector tetra

		for (lightP2 = lightVec.begin(); lightP2 != lightVec.end(); lightP2++) {



			float t = INFINITY;
			

			if ((*lightP2)->intersection(ray->start.position, ray->direction, t) && (t < rayLength))
			{

				//ska tillföra ljus till objektet

				rayLength = t; // used as reference, maybe change in intersection, declare it again

				ray->color = (*lightP2)->color; // giving the ray the color that the triangle has
				
				ray->end = Vertex(glm::vec3(ray->start.position + (ray->direction.vec * rayLength)));

				ray->triangleIntersectNormal = (*lightP2)->normal.vec;
				//save the legth of the ray from startpoint to hitpoint
				ray->tLength = rayLength;

				ray->objectType = (*lightP2)->type;

			}

		}


	}


};