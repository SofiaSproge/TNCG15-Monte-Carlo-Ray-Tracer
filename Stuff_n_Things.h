#pragma once
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


//Struct for a vertex
struct Vertex {
	// --> initlaize vector
	
	Vertex() : position(glm::vec3(0.0, 0.0, 0.0)), weight(1.0) {}

	Vertex(float x, float y, float z, float w) : position(glm::vec3(x,y,z)), weight(w){}

	Vertex(glm::vec3(positionFull)) :position(positionFull) , weight(1.0) {}

	//Values used in the vertex
	glm::vec3 position;
	float weight;

};

struct Direction {
	Direction(float x, float y, float z) {
		vec = glm::normalize(glm::vec3(x, y, z));
	}

	Direction(glm::vec3 inVec) {
		vec = glm::normalize(inVec);
	}
	Direction() {
		vec = glm::vec3(0.0, 0.0, 0.0);
	}

	glm::vec3 vec;
	

};

struct ColorDbl {
	// Three different ways --> initlaize ColorDbl
	// TYPE 1
	ColorDbl() : red(1.0), green(1.0), blue(1.0) {}
	//Type 2
	ColorDbl(double redIn, double greenIn, double blueIn) : red(redIn), green(greenIn), blue(blueIn) {}
	//Type 3
	// Vec3 är typ menat för r,g,b därför finns variablerna finns fast vi inte har skapat dom själva
	ColorDbl(glm::vec3 color) : red(color.r), green(color.g), blue(color.b) {}

	// The type colorDbl is built up by 3 values
	double red, green, blue;


};

struct Ray {

	Ray(Vertex startIn, Vertex endIn, Direction directionIn, ColorDbl rayColorIn, glm::vec3 importanceIn, float tLengthIn, Ray* parentIn , Ray* reflectedIn , Ray* transmittedIn , glm::vec3 (triangleIntersectNormalIn) , std::string(objectTypeIn) , float(sRL))
		:start(startIn) , end(endIn) , direction(directionIn), color(rayColorIn), tLength(tLengthIn), triangleIntersectNormal(triangleIntersectNormalIn), objectType(objectTypeIn), shadowRayLength(sRL){
		
	}
	
	// atm vertex is default in vertex struct constructor
	Ray(): start(Vertex()), end(Vertex()), direction(Direction()), color(ColorDbl()), tLength(INFINITY), triangleIntersectNormal(glm::vec3(0.0f,0.0f,0.0f)), objectType(""), shadowRayLength(INFINITY){}

	Ray(Vertex startIn, Direction dirIn) :start(startIn), end(Vertex()), direction(dirIn), color(ColorDbl()), tLength(INFINITY), triangleIntersectNormal(glm::vec3(0.0f, 0.0f, 0.0f)) , objectType(""), shadowRayLength(INFINITY){}

	//Triangle* triRef;
	Direction direction;
	Vertex start;
	Vertex end;

	ColorDbl color;

	float tLength;

	glm::vec3 triangleIntersectNormal;
	std::string objectType;
	//std::string 
	
	float shadowRayLength;


};




struct Pixel {
	Pixel(): colorP(ColorDbl()) , pixelCenter(Vertex()) {}

	Pixel(ColorDbl color, Vertex inVertex): colorP(color), pixelCenter(inVertex){}


	ColorDbl colorP;
	Vertex pixelCenter;

};

