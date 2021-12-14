
#pragma once

#include "Triangle.h"


#define EPSILON 0.000001


Triangle::Triangle(Vertex vertex0, Vertex vertex1 , Vertex vertex2, ColorDbl colorIn, Direction direc, std::string stringIn)
{
	type = stringIn;

	v0 = vertex0;
	v1 = vertex1;
	v2 = vertex2;
	color = colorIn;

	// LINK:-https://www.khronos.org/opengl/wiki/Calculating_a_Surface_Normal
	// How to calc a normal

	// Cross product thing, should be modified, for direction
	e1 = v1.position - v0.position;
	e2 = v2.position - v0.position;


	// Normal for every vertice
	/*normal.x = (e1.y * e2.z) - (e1.z - e2.y);
	normal.y = (e1.z * e2.x) - (e1.x - e2.z);
	normal.z = (e1.x * e2.y) - (e1.y - e2.x);*/

	direc = Direction(glm::normalize(glm::cross(e1,e2)));
	normal = direc;
	
}

// MOLLER TRUMBORE
bool Triangle::intersection(glm::vec3 sPos, Direction direction, float& t) {
	
/* Remove !! from https!!
https!!://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/moller-trumbore-ray-triangle-intersection
https!!://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/barycentric-coordinates
*/
// Möller Ma boy

//	std::cout << std::endl << "You are inside Intersection in Triangle.cpp" << std::endl;
	
	glm::vec3 trumboreT = sPos - v0.position;

	//glm::vec3 trumboreD = v2.position - v0.position;// ska int eha sen?
	glm::vec3 trumboreP = glm::cross(e2, direction.vec);

	float determinant = glm::dot(trumboreP,e1); // ska inte determinanten vara possitiv

	//check if triangle and ray are parallel or if the tringals normal is backfacing
	if ((determinant > -EPSILON) && (determinant < EPSILON)) {
		return false;
	}

	//calc the inverse of the determinant

	float inverseDet = 1.0f / determinant;

	
	//create world coordinate u
	float U = glm::dot( trumboreP,trumboreT) * inverseDet;


//	std::cout << "U: " << U << std::endl;
	//check if u intersects the triangle
	//U ska vara ett decimaltal mellan 0 och 1 för att en intersection ska finnas
	if (U < 0.0f || U > 1.0f) {
		return false;
	}

	//create world coordinate v
	glm::vec3 trumboreQ = glm::cross(e1,trumboreT);
	//direc trumbT
	float V = glm::dot(trumboreQ, direction.vec) * inverseDet;

	//std::cout << "V: " << V << std::endl;
	//std::cout << "U+V: " << U+V << std::endl;
	//check if V intersects the triangle
	if (V < 0.0f || U + V > 1.0f) {
		return false;
	}

	//create world coordinate t
	//	här ändrar vi t yeeeeeyy
	t = glm::dot(e2,trumboreQ)*inverseDet;

	//Make sure that the ray intersect with something else than the starting point
	if (t > EPSILON) {
		return true;
	}

	return false;

}

Triangle::~Triangle() {}

