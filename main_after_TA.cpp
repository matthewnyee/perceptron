#include "perceptron.h"
#include <string>

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

	data_node * head;

	ifstream fin;
	fin.open("mnist_train.csv");
int i = 0;
while (!fin.eof())
{
	char buf[3140];
	fin.getline(buf, 3140);


	char * token = new char[4];
	float results[785] = {};

	token = strtok(buf, ",");
	cout << atoi(token);	
	head = new data_node;
	head->actual_value = atoi(token);
	head->next = NULL;
	cout << "           " << head->actual_value << endl;

	token = strtok(NULL, ",");
	while (token != NULL)
	{
		++i;
		cout << (float) atoi(token) / 255;	
		head = new data_node;
		head->actual_value = atoi(token);
		head->next = NULL;
		cout << "      " << i << "     " << head->actual_value << endl;
		token = strtok(NULL, ",");
	}
	i = 0;
	cout << "=========================================================" << endl;
}

/*	while (!fin.eof())
	{
		char buf[3140];
		fin.getline(buf, 3140);
		int i = 0;

		char * token[785] = {};
		float results[785] = {};

		token[0] = strtok(buf, ",");
		for (i = 1; i < 785; ++i)
		{
			token[i] = strtok(0, ",");

			int result = 0;
			for (int k = 0; k < strlen(token[i]); ++k)
			{
				result *= 10;
				result += token[i][k] - 48;
			}

			results[i] = (float) result / 255;
		}
		// results arr finished now
		// contains all pixels for one point of data

		if (!head)
		{

			head = new data_node;
			head->actual_value = results[0];
			head->data[0] = results[0];
			head->data[1] = results[1];
	
			for (int j = 2; j < 785; ++j)
			{
				head->data[j] = results[j];
			}
			head->next = NULL;
		}
		else
		{
			data_node * curr = new data_node;
		//curr->head = new pixel_node; 
			curr->actual_value = results[0];

		//curr->head->value = results[1];
		//curr->head->next = NULL;

			curr->data[0] = results[0];
			curr->data[1] = results[1];
			
			for (int j = 2; j < 785; ++j)
			{
				curr->data[j] = results[j];
			}

			curr->next = head;
			head = curr;
		}

*/
/*		for (int j = 2; j < 785; ++j)
		{

			//curr->data[j] = results[j];

	
			pixel_node * get_last = curr->head;
			if (get_last)
			{
				while (get_last->next)
				{
					get_last = get_last->next;
				}
			}
			pixel_node * new_pixel = new pixel_node;
			new_pixel->value = results[j];
			get_last->next = new_pixel;
			new_pixel->next = NULL;
*/		

/*		for (int j = 0; j < i; ++j)
		{
			cout << "results[" << j << "] = " << results[j] << endl;
		}*/
	
/*	data_node * current;

	current = head;

	while (current)
	{
		cout << current->actual_value << " ";
		for (int j = 0; j < 785; ++j)
		{
			cout << current->data[j] << " ";
		}
		current = current->next;
	}
*/
/*	
}*/

	float learning_rate = 0.1;
	int n;


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
/*
			data_node * curr = new data_node;
			curr->head = NULL;
			curr->actual_value = results[0];

			for (int j = 1; j < 785; ++j)
			{
				pixel_node * get_last = curr->head;
				if (get_last->next)
				{
					while (get_last->next)
					{
						get_last = get_last->next;
					}
				}
				pixel_node * new_pixel = new pixel_node;
				new_pixel->value = results[j];
				get_last->next = new_pixel;
				new_pixel->next = NULL;
			}*/


