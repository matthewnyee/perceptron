#include "perceptron.h"

using namespace std;

int main(void)
{

// read in grayscale data into LLL (test data, training data)
// divide all by 255 so between 0/1
// can't use array, b/c don't know data set size...
// keep count of size as int to use for forumlas 

// make LLL of weights (randomized, between -0.5/0.5)
// maybe put this in perceptron class?
// b/c need to generate 10 weight lists for 10 perceptrons

	float learning_rate = 0.1;
	int n;

	int training_data_accuracy[50], test_data_accuracy[50];

	perceptron the_perceptron(learning_rate, weights);

	while (n < 50)
	{
		the_perceptron.train(training_data);
		training_data_accuracy[n] = the_perceptron.accuracy(training_data);
		test_data_accuracy[n] = the_perceptron.accuracy(test_data);
		++n;
	}

	// repeat all w/new learning rate (.01, .001)
	
}
