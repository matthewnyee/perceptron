///////////////////////////////////////////////////////////////////////////////
// Matt Yee
// CS 545
// Machine Learning
// 18 April 2017
// Homework 1
///////////////////////////////////////////////////////////////////////////////
// perceptron.h
// Function declarations for perceptron class
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

// Node to hold data when read from file
struct data_node
{
	int actual_value; // What number handwritten image is supposed to represent
	float data[784]; // Grayscale pixels of image (normalized to between 0 and 1)
	data_node * next; // Next image 
};

// Perceptron class
class perceptron
{
	public:
		perceptron(float learning_rate, int total_image_count);
		~perceptron(void);

		// Functions to I/O, data and weights
		int add_data(data_node * & head);
		int print_data(void);
		int print_weights(void);

		// Train entire perceptron set (0-9) on a single image/data point
		int train(data_node * current_node);

		// Get accuracy for perceptron set (0-9) across entire data set
		float accuracy(void);
		// Helper function: gets accuracy for one node in data set
		int get_accuracy(data_node * current_node);

		// "Setter" function, assigns weights from perceptron to_copy
		int change_weights(perceptron to_copy);

		// Prints confusion matrix 
		int print_confusion_matrix(void);
		// Helper function: gets matrix data for a single data point 
		int get_values(data_node * current_node, int &actual, int &predict);

	private:
		float learning_rate; // Learning rate (0.1, 0.01, or 0.001)
		int data_count; // Number of images in entire data set
		data_node * head; // Pointer to LLL of data read in from file

		// Weights for each individual perceptron, from 0 to 9
		// Turn this into a 2D array? To eliminate code bulk
		float weights0[785];
		float weights1[785];
		float weights2[785];
		float weights3[785];
		float weights4[785];
		float weights5[785];
		float weights6[785];
		float weights7[785];
		float weights8[785];
		float weights9[785];
};
