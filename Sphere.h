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
class Sphere
{

public:

	std::string itsSphere = "itsSphere";
	ColorDbl color;

	glm::vec3 albedo = glm::vec3(1.0f, 1.0f, 1.0f);
	float radius;
	glm::vec3 point;


	Sphere( float rad, glm::vec3 p, ColorDbl c) : radius { rad }, point{ p }, color{ c }{
		//std::cout << "Creating Sphere" << std::endl;
	
	}

	~Sphere() {
	}

	void rayIntersection(Ray* ray) {
		
		float minDist = 1000;
		float discriminant;
		float d1, d2;

		//Vertex o = ray->start.; ray.pos
		//Direction l = ray.getDirection(); l är ray direc
		
		float a = 1; //Since the direction is normalized
		float b = 2.0f * glm::dot(ray->direction.vec, (ray->start.position - point));
		float c = glm::dot((ray->start.position - point), (ray->start.position - point)) - pow(radius, 2);

		discriminant = b * b - 4.0f * a * c;
		glm::vec3 tempIntersection;

		// No solutions
		if (discriminant < 0) {
			return;
		}
	
		//One solution
		else if (discriminant < DBL_EPSILON) {
			d1 = -(b / 2.0f);
			tempIntersection = ray->start.position + d1 * ray->direction.vec;
		}
		//Two solutions
		else {
			d1 = -(b / 2.0f) + sqrt(pow((b / 2.0f), 2) - a * c);
			d2 = -(b / 2.0f) - sqrt(pow((b / 2.0f), 2) - a * c);

			if (d2 > 0.0f) {
				tempIntersection = ray->start.position + d2 * ray->direction.vec;
			}
			else if (d1 > 0.0f) {
				tempIntersection = ray->start.position + d1 * ray->direction.vec;
			}
			else return;
		}

		if (glm::length(tempIntersection - ray->start.position) < minDist) {
			minDist = glm::length(tempIntersection - ray->start.position);
			Direction normal = glm::normalize(tempIntersection - point);
			ray->triangleIntersectNormal = normal.vec;
			ray->color = color;
			ray->end.position = tempIntersection + normal.vec* 0.001f;
			ray->objectType = itsSphere;
			ray->tLength = abs(glm::length(ray->start.position - ray->end.position));
		}
	

	}


};