#include "perceptron.h"
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
	data_node * head;

	ifstream fin;
	fin.open("mnist_train.csv");

	float results[785] = {};

	// fin.ignore
	
	if (!fin.eof())
	{
		char buf[3140];
		fin.getline(buf, 3140);

		char * token = new char[4]; 

		
		strcpy(token, strtok(buf, ","));

		int result = 0;
		for (int k = 0; k < strlen(token); ++k)
		{
			result *= 10;
			result += token[k] - 48;
		}
		results[0] = result;

		delete [] token;

//		results[0] = std::stoi(token);

		result = 0;
		for (int i = 1; i < 785; ++i)
		{
			token = new char[4];
			strcpy(token, strtok(buf, ","));
			result = 0;
			for (int k = 0; k < strlen(token); ++k)
			{
				result *= 10;
				result += token[k] - 48;
			}
			results[i] = (float) result / 255;
			delete [] token;
		}




//		data_node * curr = new data_node;
//		curr->head = new pixel_node; 
//		curr->actual_value = results[0];

//		curr->head->value = results[1];
//		curr->head->next = NULL;

//		curr->data[0] = results[0];
//		curr->data[1] = results[1];
/*
		for (i = 0; i < 785; ++i)
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
*/
	}

	for (int j = 0; j < 785; ++j)
	{
		cout << results[j] << " ";//"results[" << j << "] = " << results[j] << endl;
	}
	


}	
