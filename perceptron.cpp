#include "perceptron.h"

perceptron::perceptron(float learning_rate)
{
	learning_rate = 0.1;
	head = NULL;
	for (int i = 0; i < 785; ++i)
	{
 		srand(time(NULL));
		int n = rand() % 101;
		weights[i] = (-0.5 + ((float) n / 100));
		// get btwn 0 and 1, then subtarct 0.5 
	}
}

perceptron::~perceptron(void)
{
}

int perceptron::add_data(data_node * & data_head)
{
	head = data_head;
	return 1;
}

int perceptron::print_data(void)
{
	data_node * current = head;

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
	return 1;
}


int perceptron::train(data_node * training_data)
{
	// weight DOT data (data = pixels + bias of 1))	
	// 
}

