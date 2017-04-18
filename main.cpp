///////////////////////////////////////////////////////////////////////////////
// Matt Yee
// CS 545
// Machine Learning
// 18 April 2017
// Homework 1
///////////////////////////////////////////////////////////////////////////////
// main.cpp
// Contains program main function
/////////////////////////////////////////////////////////////////////////////// 

#include "perceptron.h"

int main(void)
{
	///////////////////////////////////////////////////////////////////////
	// Read in data set used to train perceptrons (~60,000 data points)
	data_node * the_head = NULL;
	ifstream fin;
	fin.open("mnist_train.csv");
	float results[785] = {}; // Temporary storage for each pixel of a data point
	char buf[3140]; // Buffer holds one line from input file
	int data_count = 0; // Count of total number of data points in file

	///////////////////////////////////////////////////////////////////////
	// Getting each data point (one line in the file = one data point/image)
	while (fin.getline(buf, 3140))	
	{
		++data_count; // Counting total number of data points in file
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
		// Results array finished. All data read in.
		// Contains all pixels for one data point (one handwritten image)

		////////////////////////////////////////////////////////////////
		// Add to LLL this entire data point:
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

	///////////////////////////////////////////////////////////////////////
	// Read in test data into LLL held by 'test_head' pointer
	data_node * test_head = NULL;
	ifstream test_file;
	test_file.open("mnist_test.csv");
	float test_results[785] = {};
	char test_buf[3140];
	int test_data_count = 0; // Total number of data points (images) in file

	///////////////////////////////////////////////////////////////////////
	// Getting each data point (one line in the file = one data point)
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
		// Results array now finished. All data read in.
		// Contains all pixels for one data point (one handwritten image)

		///////////////////////////////////////////////////////////////	
		// Add to LLL this entire data point:
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

	///////////////////////////////////////////////////////////////////////
	// Build perceptrons, one for each learning rate.
	//
	// Variables train1 through train0001 are for training perceptrons
	// with learning rates 1, 0.1, 0.01, 0.001.
	perceptron train1(1, data_count);
	perceptron train01(0.1, data_count);
	perceptron train001(0.01, data_count);
	perceptron train0001(0.001, data_count);
	// Variables test1 through test0001 are for testing train1 through
	// train0001 on the test data. Used to determine accuracy of training.
	perceptron test1(1, test_data_count);;
	perceptron test01(0.1, test_data_count);
	perceptron test001(0.01, test_data_count);
	perceptron test0001(0.001, test_data_count);

	///////////////////////////////////////////////////////////////////////
	// Assigning the 'mnist_train.csv' data to training perceptrons
	train1.add_data(the_head);
	train01.add_data(the_head);
	train001.add_data(the_head);
	train0001.add_data(the_head);
	// Assigning 'mnist_test.csv' data to the testing objects
	test1.add_data(test_head);
	test01.add_data(test_head);
	test001.add_data(test_head);
	test0001.add_data(test_head);

	///////////////////////////////////////////////////////////////////////
	// Output file ("output.csv") for recording of results
	ofstream output;
	output.open("output.csv");
	// Store accuracy of each perceptron set (learning rates 1 through 0.001)
	// All accuracies output onto one comma separated line in output file
	//
	// CSV column headers. 4 perceptrons sets for training, 4 for test data
	output << "train1/training 1," << "train01/training 0.1,";
	output << "train001/training 0.01," << "train0001/training  0.001,";
	output << "test1/test 1," << "test01/test 0.1," << "test001/test 0.01,";
	output << "test0001/test 0.001\n";	
	// Each line in CSV represents one accuracy measurement
	// for all 4 perceptrons, plus 4 test data sets
	output << train1.accuracy() << "," << train01.accuracy() << ",";
	output << train001.accuracy() << "," << train0001.accuracy() << ",";
	output  << test1.accuracy() << "," << test01.accuracy() << ",";
	output  << test001.accuracy() << "," << test0001.accuracy() << endl;

	///////////////////////////////////////////////////////////////////////
	// Iterate 50 epochs
	// Train perceptrons 50 times on entire training data set
	// Measure accuracy after each epoch (each iteration through training data)
	// Output accuracy measurements into output file ("output.csv")
	for (int x = 0; x < 50; ++x)
	{
		// Print marker to let user how far program has reached 
		// Program takes roughly 20 minutes to finish
		cout << "Epoch: " << x << endl;

		// Iterate through each data value in training set (~60,000)
		data_node * curr = the_head;
		while (curr)
		{
			// Train all 4 perceptron sets with each data point 
			train1.train(curr);
			train01.train(curr);
			train001.train(curr);
			train0001.train(curr);
			curr = curr->next;
		}

		// Update weights on test objects to measure accuracy
		test1.change_weights(train1);
		test01.change_weights(train01);
		test001.change_weights(train001);
		test0001.change_weights(train0001);

		// Output to file accuracies after training on each data point
		output << train1.accuracy() << "," << train01.accuracy();
		output << "," << train001.accuracy() << ",";
		output << train0001.accuracy() << "," << test1.accuracy();
		output << "," << test01.accuracy() << "," << test001.accuracy();
		output << "," << test0001.accuracy() << endl;
	}

	///////////////////////////////////////////////////////////////////////
	// Print to screen confusion matrix of results
	// Print results of test data for all learning rates (0.1, 0.01, 0.001)
	// Horizontal axis is predicted result, 0 through 9, left to right
	// Vertical axis is actual result, 0 through 9, top to bottom
	// Top-left to bottom-right diagonal should be most populated,
	// indicating most images were categorized correctly.
	cout << "test01 ";
	test01.print_confusion_matrix();
	cout << "test001 ";
	test001.print_confusion_matrix();
	cout << "test0001 ";
	test0001.print_confusion_matrix();

}

