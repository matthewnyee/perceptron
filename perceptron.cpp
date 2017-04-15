#include "perceptron.h"

perceptron::perceptron(float learning_rate)
{
	learning_rate = 0.1;
	head = NULL;
 	srand(time(NULL));
	for (int i = 0; i < 785; ++i)
	{
		// get random number between 0 and 1
		// then subtract by 0.5 to get weights between -0.5 and 0.5 
		int n = rand() % 101;
		weights0[i] = (-0.5 + ((float) n / 100));
		weights1[i] = (-0.5 + ((float) (rand() % 101) / 100));
		weights2[i] = (-0.5 + ((float) (rand() % 101) / 100));
		weights3[i] = (-0.5 + ((float) (rand() % 101) / 100));
		weights4[i] = (-0.5 + ((float) (rand() % 101) / 100));
		weights5[i] = (-0.5 + ((float) (rand() % 101) / 100));
		weights6[i] = (-0.5 + ((float) (rand() % 101) / 100));
		weights7[i] = (-0.5 + ((float) (rand() % 101) / 100));
		weights8[i] = (-0.5 + ((float) (rand() % 101) / 100));
		weights9[i] = (-0.5 + ((float) (rand() % 101) / 100));
	}

//////////////////////////////////////////////////
// Printing random weights
////////////////////////////////////////////////////
/*	for (int i = 0; i < 785; ++i)
	{
		cout << "weights0:" << i << "   " << weights0[i] << " ";
		cout << "weights1:" << i << "   " << weights1[i] << endl;
		cout << "weights2:" << i << "   " << weights2[i] << endl;
		cout << "weights3:" << i << "   " << weights3[i] << endl;
		cout << "weights4:" << i << "   " << weights4[i] << endl;
		cout << "weights5:" << i << "   " << weights5[i] << endl;
		cout << "weights6:" << i << "   " << weights6[i] << endl;
		cout << "weights7:" << i << "   " << weights7[i] << endl;
		cout << "weights8:" << i << "   " << weights8[i] << endl;
		cout << "weights9:" << i << "   " << weights9[i] << endl;
	}*/
//////////////////////////////////////////////////
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



int perceptron::train(void)
{
	// weight DOT data (data = pixels + bias of 1))	
	// for each perceptron (0 thru 9)
	// get highest of these DOT products
	// if > 0, then that is the resulting "number" found by our perceptron(s)
	// find error and change weights accordingly
}
