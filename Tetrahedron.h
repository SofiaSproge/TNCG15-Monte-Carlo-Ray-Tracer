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
class Tetrahedron
{

public:

	std::string itsTetra = "itsTetra";

	std::vector<Triangle*> tetra;
	std::vector<Triangle*>::iterator tetraP;

	glm::vec3 albedo = glm::vec3(0.9f, 0.9f, 0.9f);

	//Tetrahederon 1
	Vertex vtop = Vertex(8.0f, -1.0f, 2.8f, 1.0);
	Vertex vfront = Vertex(7.0f, -1.0f, 4.5f, 1.0); 
	Vertex vbottom1 = Vertex(8.5f, 0.5f, 4.5f, 1.0);
	Vertex vbottom2 = Vertex(8.5f, -2.50f, 4.5f, 1.0);

	//Tetrahederon 2
	Vertex vtop_2 = Vertex(5.0f, -2.6f, 5.0f, 1.0);
	Vertex vfront_2 = Vertex(4.0f, -2.6f, 2.5f, 1.0); 
	Vertex vbottom1_2 = Vertex(5.5f, -1.1f, 2.5f, 1.0);
	Vertex vbottom2_2 = Vertex(5.5f, -4.1f, 2.5f, 1.0);

	//extra triangle
	/*
	Vertex v1a = Vertex(8.0f, 3.0f, 3.0f, 1.0);
	Vertex v2a = Vertex(8.0f, -3.0f, 3.0f, 1.0);
	Vertex v3a = Vertex(8.0f, 0.0f, -3.0f, 1.0);
	*/



	
	Tetrahedron() {

		createTetra();
		//std::cout << "Creating Tetrahedron" << std::endl;
	
	}

	void createTetra() {

	//	tetra.push_back(new Triangle(v1a, v3a, v2a, glm::vec3(0.88f, 0.607f, 0.607f), Direction(), itsTetra)); //fake triangle
		/*
		tetra.push_back(new Triangle(vfront, vbottom2, vbottom1, glm::vec3(1.0f, 0.278f, 0.384f), Direction(), itsTetra)); //bottom
		tetra.push_back(new Triangle(vfront, vtop, vbottom2, glm::vec3(1.0f, 0.278f, 0.384f), Direction(), itsTetra)); //wall3
		tetra.push_back(new Triangle(vfront, vbottom1, vtop, glm::vec3(1.0f, 0.278f, 0.384f), Direction(), itsTetra)); //wall2
		tetra.push_back(new Triangle(vbottom1, vbottom2, vtop, glm::vec3(1.0f, 0.278f, 0.384f), Direction(), itsTetra)); //wall1
		*/

		tetra.push_back(new Triangle(vbottom1, vbottom2, vfront , glm::vec3(0.902f, 0.224f, 0.275f), Direction(), itsTetra)); //bottom
		tetra.push_back(new Triangle(vfront, vtop, vbottom2, glm::vec3(0.902f, 0.224f, 0.275f), Direction(), itsTetra)); //wall3
		tetra.push_back(new Triangle(vfront, vbottom1, vtop, glm::vec3(0.902f, 0.224f, 0.275f), Direction(), itsTetra)); //wall2
		tetra.push_back(new Triangle(vbottom1, vbottom2, vtop, glm::vec3(0.902f, 0.224f, 0.275f), Direction(), itsTetra)); //wall1

		tetra.push_back(new Triangle(vbottom1_2, vbottom2_2, vfront_2, glm::vec3(0.0f, 1.0f, 1.0f), Direction(), itsTetra)); //bottom
		tetra.push_back(new Triangle(vfront_2, vtop_2, vbottom2_2, glm::vec3(0.0f, 1.0f, 1.0f), Direction(), itsTetra)); //wall3
		tetra.push_back(new Triangle(vfront_2, vbottom1_2, vtop_2, glm::vec3(0.0f, 1.0f, 1.0f), Direction(), itsTetra)); //wall2
		tetra.push_back(new Triangle(vbottom1_2, vbottom2_2, vtop_2, glm::vec3(0.0f, 1.0f, 1.0f), Direction(), itsTetra)); //wall1

	}

	~Tetrahedron() {

		for (tetraP = tetra.begin(); tetraP != tetra.end(); ++tetraP) {
			delete (*tetraP);
		}
		tetra.clear();
	}

	void rayIntersection(Ray* ray) {
		std::vector<Triangle*>::iterator tetraP2;

		//std::cout << "Inside RayIntersection in Tetrahederon.h" << std::endl;
		float rayLength = INFINITY;

		glm::vec3 intersectedP;

		//Triangle intersection wants startpos direction and t
		//We need a for loop to go through the vector tetra

		for (tetraP2 = tetra.begin(); tetraP2 != tetra.end(); tetraP2++) {



			float t = INFINITY;
	
			if ((*tetraP2)->intersection(ray->start.position, ray->direction, t) && (t < rayLength))
			{


				rayLength = t; // used as reference, maybe change in intersection, declare it again
				ray->color = (*tetraP2)->color; // giving the ray the color that the triangle has
				ray->end = Vertex(glm::vec3(ray->start.position + (ray->direction.vec * rayLength)));
				ray->triangleIntersectNormal = (*tetraP2)->normal.vec;

				//save the legth of the ray from startpoint to hitpoint
				ray->tLength = rayLength;

				ray->objectType = (*tetraP2)->type;
			}

		}

	}

};