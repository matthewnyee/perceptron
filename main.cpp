#include "perceptron.h"

int main(void)
{
	data_node * the_head = NULL;
	ifstream fin;
	fin.open("mnist_train.csv");

	float results[785] = {};
	char buf[3140];

	int data_count = 0; // Total number of data points (images) in file

	// Get a data point (one line in the file = one data point)
	while (fin.getline(buf, 3140))	
	{
		++data_count; // Counting total number of values (images) in file
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
		if (!the_head)
		{

			the_head = new data_node;
			// Assign what number image is supposed to represent
			the_head->actual_value = results[0];
			// Assign rest of pixel data to "data" array
			the_head->data[0] = results[1];	
			for (int j = 1; j < 785; ++j)
			{
				the_head->data[j] = results[j + 1];
			}
			the_head->next = NULL;
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
			curr->next = the_head;
			the_head = curr;
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
	current = the_head;

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
*/
// Data is printing fine
/////////////////////////////////////////////////////////////////
	data_node * test_head = NULL;
	ifstream test_file;
	test_file.open("mnist_test.csv");

	float test_results[785] = {};
	char test_buf[3140];

	int test_data_count = 0; // Total number of data points (images) in file

	// Get a data point (one line in the file = one data point)
	while (test_file.getline(test_buf, 3140))	
	{
		++test_data_count; // Counting total number of values (images) in file
		//fin.getline(buf, 3140);

		char * token = new char[4];

		// Get first number from data point
		// This number is what handwritten image is supposed to represent
		token = strtok(test_buf, ","); // First strtok uses buf, then use NULL?
		test_results[0] = atoi(token);

		// Read rest of data point (pixels of image of handwritten letter)
		// Divide grayscale pixel by 255 to keep pixels between 0 and 1
		for (int i = 1; i < 785; ++i)
		{
			token = strtok(NULL, ","); // use NULL w/strtok here?
			test_results[i] = (float) atoi(token) / 255;
		}
		// results array finished now
		// contains all pixels for one datapoint

		// Now build LLL of this entire data point:
		if (!test_head)
		{

			test_head = new data_node;
			// Assign what number image is supposed to represent
			test_head->actual_value = test_results[0];
			// Assign rest of pixel data to "data" array
			test_head->data[0] = test_results[1];	
			for (int j = 1; j < 785; ++j)
			{
				test_head->data[j] = test_results[j + 1];
			}
			test_head->next = NULL;
		}
		else
		{
			data_node * curr = new data_node;
			curr->actual_value = test_results[0];
			curr->data[0] = test_results[1];
			for (int j = 2; j < 785; ++j)
			{
				curr->data[j] = test_results[j + 1];
			}
			curr->next = test_head;
			test_head = curr;
		}
	}



	perceptron train1(1, data_count);
	perceptron train01(0.1, data_count);
	perceptron train001(0.01, data_count);
	perceptron train0001(0.001, data_count);

	perceptron test1(1, test_data_count);;
	perceptron test01(0.1, test_data_count);
	perceptron test001(0.01, test_data_count);
	perceptron test0001(0.001, test_data_count);
//
//	the_perceptron.print_weights();
//	he_perceptron.print_weights();
//	e_perceptron.print_weights();
//	perceptron.print_weights();
// weights look fine
//
	train1.add_data(the_head);
	train01.add_data(the_head);
	train001.add_data(the_head);
	train0001.add_data(the_head);
	test1.add_data(test_head);
	test01.add_data(test_head);
	test001.add_data(test_head);
	test0001.add_data(test_head);
/*	cout << "train1 acc: " << train1.accuracy() << endl;
	cout << "train01 acc: " << train01.accuracy() << endl;
	cout << "train001 acc: " << train001.accuracy() << endl;
	cout << "train0001 acc: " << train0001.accuracy() << endl;
	cout << "test1 acc: " << test1.accuracy() << endl;
	cout << "test01 acc: " << test01.accuracy() << endl;
	cout << "test001 acc: " << test001.accuracy() << endl;
	cout << "test0001 acc: " << test0001.accuracy() << endl;
*/

//	the_perceptron.print_data();

	for (int x = 0; x < 50; ++x)
	{
		cout << "Epoch: " << x << " _____________________________________________________________" << endl;
		data_node * curr = the_head;
		while (curr)
		{
	
			train1.train(curr);
			train01.train(curr);
			train001.train(curr);
			train0001.train(curr);
			curr = curr->next;
		}
		test1.change_weights(train1);
		test01.change_weights(train01);
		test001.change_weights(train001);
		test0001.change_weights(train0001);
		cout << "train1 acc: " << train1.accuracy() << endl;
		cout << "train01 acc: " << train01.accuracy() << endl;
		cout << "train001 acc: " << train001.accuracy() << endl;
		cout << "train0001 acc: " << train0001.accuracy() << endl;
		cout << "test1 acc: " << test1.accuracy() << endl;
		cout << "test01 acc: " << test01.accuracy() << endl;
		cout << "test001 acc: " << test001.accuracy() << endl;
		cout << "test0001 acc: " << test0001.accuracy() << endl;

	}

	test1.print_confusion_matrix();

	








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

