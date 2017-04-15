#include "perceptron.h"

int main(void)
{
	perceptron the_perceptron(0.1);
	data_node * head = NULL;

	ifstream fin;
	fin.open("mnist_train.csv");

	float results[785] = {};
	char buf[3140];

	// Get a data point (one line in the file = one data point)
	while (fin.getline(buf, 3140))	
	{
		//fin.getline(buf, 3140);

		char * token = new char[4];

		// Get first number from data point
		// This number is what handwritten image is supposed to represent
		token = strtok(buf, ","); // First strtok uses buf, then use NULL?
		results[0] = atoi(token);

		// Read rest of data point (pixels of image of handwritten letter)
		// Divide grayscale pixel by 255 to keep pixels between 0 and 1
		for (int i = 1; i < 785; ++i)
		{
			token = strtok(NULL, ","); // use NULL w/strtok here?
			results[i] = (float) atoi(token) / 255;
		}
		// results array finished now
		// contains all pixels for one datapoint

		// Now build LLL of this entire data point:
		if (!head)
		{

			head = new data_node;
			// Assign what number image is supposed to represent
			head->actual_value = results[0];
			// Assign rest of pixel data to "data" array
			head->data[0] = results[1];	
			for (int j = 1; j < 785; ++j)
			{
				head->data[j] = results[j + 1];
			}
			head->next = NULL;
		}
		else
		{
			data_node * curr = new data_node;
			curr->actual_value = results[0];
			curr->data[0] = results[1];
			for (int j = 2; j < 785; ++j)
			{
				curr->data[j] = results[j + 1];
			}
			curr->next = head;
			head = curr;
		}
	}
///////////////////////////////////////////////////////////////
// Prints all data points using results array
///////////////////////////////////////////////////////////////
/*
	for (int j = 0; j < 785; ++j)
	{
		cout << "results[" << j << "] = " << results[j] << endl;
	}
*/
///////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// Prints all data points from LLL
//////////////////////////////////////////////////////////////
/*
	data_node * current;
	current = head;

	int k = 0;
	while (current && k < 4)
	{
		cout << "k is " << k;
		cout << endl << current->actual_value << " ";
		for (int j = 0; j < 784; ++j)
		{
			cout << endl << j << ": " << current->data[j] << " ";
		}
		cout << endl;
		current = current->next;
		++k;
	}
*///////////////////////////////////////////////////////////////



	the_perceptron.add_data(head);
	the_perceptron.print_data();
	the_perceptron.train();


/////	int training_data_accuracy[50], test_data_accuracy[50];

/////	perceptron the_perceptron(learning_rate);
/*
	while (n < 50)
	{
		the_perceptron.train(training_data);
		training_data_accuracy[n] = the_perceptron.accuracy(training_data);
		test_data_accuracy[n] = the_perceptron.accuracy(test_data);
		++n;
	}
*/

	// repeat all w/new learning rate (.01, .001)
}

