#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;


// Node to hold data when read from file
struct data_node
{
	int actual_value; // What number handwritten image is supposed to be
	float data[784]; // Pixels of image (normalized to be between 0 and 1)
	data_node * next; // Next image 
};

class perceptron
{
	public:
		perceptron(float learning_rate, int );
		~perceptron(void);

		// Functions to check data and I/O
		int add_data(data_node * & head);
		int print_data(void);
		int print_weights(void);

		int train(data_node *);
		float accuracy(void);
		int get_accuracy(data_node *);

		int change_weights(perceptron);
		int print_confusion_matrix(void);
		int get_values(data_node *, int &, int &);
	private:
		float learning_rate;
		int data_count;
		data_node * head; // Pointer to LLL of data read from file

		// Weights for each individual perceptron, from 0 to 9
		// Turn this into a 2D array? To elminate code bulk
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
