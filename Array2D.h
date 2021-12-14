#pragma once
// File and console I/O for logging and error reporting
#include <iostream>
using namespace std;
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
#include "Stuff_n_Things.h"


// Used for Image plane
class Array2D {
public:
	// constrcutorn
	Array2D(int wIn, int hIn) {
		HEIGHT = hIn;
		WIDTH = wIn;
		container.resize(HEIGHT * WIDTH);

		//std::cout << "creating Array2D" << endl;

		fillWithPixels();
	

	};

	void fillWithPixels() {

		//std::cout << "inside fillWithPixel" << endl;
		for (int x = 0; x < WIDTH; x++) {
			for(int y = 0; y < HEIGHT; y++ ){
			// declaring center of pixels
				float cX = 0; //andra sidan av rummet behöver dumb och 11
				float cY = x * 0.0025 - 0.99875;
				float cZ = y * 0.0025 - 0.99875;
				Pixel* currentPixel = this->get(x, y); // får postion, var denna punkt finns i container
				currentPixel->pixelCenter = Vertex(cX, cY, cZ,1);
			
			}
		}
	}

	void set(Pixel value, int x, int y) {
		container[getPosition(x, y)] = value;
	}

	// Sends back a reference
	Pixel* get(int x, int y) {

		return &(container[getPosition(x, y)]);
	}


	// It is 2 d matrix but it is built as a vector, therefore we return this
	int getPosition(int x, int y) {
		return x + WIDTH * y;
	}

	std::vector<Pixel> container;

	int HEIGHT, WIDTH;
	

	

};
