#include "perceptron.h"

perceptron::perceptron(float the_learning_rate, int image_count)
{
	learning_rate = the_learning_rate;
	data_count = image_count;
	head = NULL;
 	srand(time(NULL));
	for (int i = 0; i < 785; ++i)
	{
		// Assign random weights to all individual perceptrons (0-9)
		// Get random number between 0 and 101, then divide by 100
		// Subtract by 0.5 to get weights between -0.5 and 0.5 
		float n = ((float) (rand() % 101)) / 100;
		weights0[i] = (-0.5 + n);
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
	}
*//////////////////////////////////////////////////
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



int perceptron::print_weights(void){
	for (int i = 0; i < 785; ++i)
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
	}
}



int perceptron::train(data_node * node)// trains one single data point (one image)
{
	// Dot products of weights of each perceptron (0-9) and data (plus bias)
	float sums[10] = {0};

	// Does each perceptron (0-9) fire? (Is dot product >= 0?)
	int outputs[10] = {0};

	int max = 0; // Index of perceptron of largest dot product 
	int max_result; // Does said perceptron fire? (Is the dot product >= 0?)

	// How much will each weight change, after this round of training?
	// 10 perceptrons, each with 785 weights for 784 pixels and 1 bias
	float changes[10][785];

	// Start sums by multiplying bias by bias weight (1 * weight[0])
	sums[0] = 1 * weights0[0];
	sums[1] =  weights1[0];
	sums[2] =  weights2[0];
	sums[3] =  weights3[0];
	sums[4] =  weights4[0];
	sums[5] =  weights5[0];
	sums[6] =  weights6[0];
	sums[7] =  weights7[0];
	sums[8] =  weights8[0];
	sums[9] =  weights9[0];

	// Dot product each weight times each pixel in image
	// Do for all perceptrons (weights 0-9 --> sums 0-9)
	int w = 0;
	for (int i = 0; i < 784; ++i) // Iterate through each pixel
	{
		++w;
		sums[0] += node->data[i] * weights0[w];
		sums[1] += node->data[i] * weights1[w];
		sums[2] += node->data[i] * weights2[w];
		sums[3] += node->data[i] * weights3[w];
		sums[4] += node->data[i] * weights4[w];
		sums[5] += node->data[i] * weights5[w];
		sums[6] += node->data[i] * weights6[w];
		sums[7] += node->data[i] * weights7[w];
		sums[8] += node->data[i] * weights8[w];
		sums[9] += node->data[i] * weights9[w];
	}

	// Does each perceptron (0-9) fire? (Is its weight-data dot product >= 0?)
	// 1 if yes, 0 if no.
	//cout << "sums[0] is " << sums[0] << endl;
	for (int i = 0; i < 10; ++i)
	{
		// printing out each sum
		//cout << "sums[" << i << "] is " << sums[i] << endl;
		if (sums[i] > 0) outputs[i] = 1;
		else outputs[i] = 0;
		//cout << "outputs[" << i << "] is " << outputs[i] << endl;
	}

	// Find largest dot product, set as max 
	// What our set of 10 perceptrons has decided the image represents
	for (int i = 1; i < 10; ++i)
	{
		if (sums[i] > sums[max]) max = i;
	}
	//cout << "max is " << max << endl;
	
	if (sums[max] <= 0) max_result = 0;
	else max_result = 1;

	for (int j = 0; j < 10; ++j) // For each individual perceptron (0-9)
	{	
		for (int i = 0; i < 785; ++i) // Iterate through each pixel 
		{
			if (node->actual_value != j) // If this perceptron is not supposed to fire 
			{
				changes[j][i] = learning_rate * (0 - outputs[j]) * node->data[i];	
				if (changes[j][i] != 0)
				{
				//	cout << "learning_rate: " << learning_rate << " outputs[" << j << "]: " << outputs[i] << "node->data[" << i << "]: " << node->data[i] <<  "changes[" << j << "][" << i << "] is " << changes[j][i] << endl;
				}
			}
			else 
			{
				changes[j][i] = learning_rate * (1 - outputs[j]) * node->data[i];
				if (changes[j][i] != 0) 
				{
				//	cout << "learning_rate: " << learning_rate << " outputs[" << j << "]: " << outputs[i] << "node->data[" << i << "]: " << node->data[i] << "changes[" << j << "][" << i << "] is " << changes[j][i] << endl;
				}
			}
		}
	}


	
	for (int i = 0; i < 785; ++i) weights0[i] += changes[0][i];
	for (int i = 0; i < 785; ++i) weights1[i] += changes[1][i];
	for (int i = 0; i < 785; ++i) weights2[i] += changes[2][i];
	for (int i = 0; i < 785; ++i) weights3[i] += changes[3][i];
	for (int i = 0; i < 785; ++i) weights4[i] += changes[4][i];
	for (int i = 0; i < 785; ++i) weights5[i] += changes[5][i];
	for (int i = 0; i < 785; ++i) weights6[i] += changes[6][i];
	for (int i = 0; i < 785; ++i) weights7[i] += changes[7][i];
	for (int i = 0; i < 785; ++i) weights8[i] += changes[8][i];
	for (int i = 0; i < 785; ++i) weights9[i] += changes[9][i];

	// delta change = learning_rate * (0/1 - 0/1) * data[]

	// max(a, max(b, max(c, (max, d(max, e(max, f...
	
	// weight DOT data (data = pixels + bias of 1))	
	// for each perceptron (0 thru 9)
	// get highest of these DOT products
	// if > 0, then that is the resulting "number" found by our perceptron(s)
	// find error and change weights accordingly
}



float perceptron::accuracy(void)
{
	float results[data_count]; // accuracy for each data point
	data_node * curr = head;

	int i = 0;
	// iterate through all data points
	while (curr)
	{
		// Fetch accuracy for each data point (binary 1 or 0)
		results[i] = get_accuracy(curr);
		//cout << "accuracy was " << results[i] << endl;
		++i;
		curr = curr->next;
	}

	// Iterate through results (accuracy for each data point: 1 or 0)
	// Get mean by summing all, dividing by total;
	int sum = 0;
	for (int j = 0; j < data_count; ++j) sum += results[j];
	return (float) sum / (float) data_count;
}

int perceptron::get_accuracy(data_node * node)
{
	float sums[10] = {0};
	int outputs[10]; // Does each perceptron (0-9) fire? (Is dot product >= 0?)
	int max = 0; // Index of perceptron of largest dot product 
	int result; // Does said perceptron fire? (is dot product >= 0)

	// Start sums by multiplying bias by bias weight (1 * weight[0])
	sums[0] = 1 * weights0[0];
	sums[1] = weights1[0];
	sums[2] = weights2[0];
	sums[3] = weights3[0];
	sums[4] = weights4[0];
	sums[5] = weights5[0];
	sums[6] = weights6[0];
	sums[7] = weights7[0];
	sums[8] = weights8[0];
	sums[9] = weights9[0]; 

	
	// Dot product each weight times each pixel in image
	// Do for all perceptrons (weights 0-9 --> sums 0-9)
	int w = 0;
	for (int i = 0; i < 785; ++i)
	{
		++w;	
		sums[0] += node->data[i] * weights0[w];
		sums[1] += node->data[i] * weights1[w];
		sums[2] += node->data[i] * weights2[w];
		sums[3] += node->data[i] * weights3[w];
		sums[4] += node->data[i] * weights4[w];
		sums[5] += node->data[i] * weights5[w];
		sums[6] += node->data[i] * weights6[w];
		sums[7] += node->data[i] * weights7[w];
		sums[8] += node->data[i] * weights8[w];
		sums[9] += node->data[i] * weights9[w];
	}

	// This loop maybe not necessary for get_accuracy?
	// Does each perceptron (0-9) fire? (Is its weight-data dot product >= 0?)
	// 1 if yes, 0 if no.
	for (int i = 0; i < 10; ++i)
	{
		if (sums[i] > 0) outputs[i] = 1;
		else outputs[i] = 0;
	}


	// Find largest dot proudct, set as max
	// (to start, max = 0);
	for (int i = 1; i < 10; ++i)
	{
		if (sums[i] > sums[max]) max = i;
	}

	// if biggest dot product <= 0, no perceptron fired, so accuracy is zero
	if (sums[max] <=0) return 0; 
	// if biggest dot product matches intended written number, accuracy = 1
	if (max == node->actual_value) return 1;
	// else, accuracy is zero
	else return 0;
}

int perceptron::change_weights(perceptron copy_from)
{
	for (int i = 0; i < 785; ++i)
	{
		weights0[i] = copy_from.weights0[i];
		weights1[i] = copy_from.weights1[i];
		weights2[i] = copy_from.weights2[i];
		weights3[i] = copy_from.weights3[i];
		weights4[i] = copy_from.weights4[i];
		weights5[i] = copy_from.weights5[i];
		weights6[i] = copy_from.weights6[i];
		weights7[i] = copy_from.weights7[i];
		weights8[i] = copy_from.weights8[i];
		weights9[i] = copy_from.weights9[i];
	}
	return 1;
}

int perceptron::print_confusion_matrix(void)
{
	int matrix[10][10] = {0};
	data_node * curr = head;
	int actual, predict;
	while (curr)
	{
		get_values(curr, actual, predict);
		matrix[actual][predict] += 1;
		curr = curr->next;
	}
	
	for (int x = 0; x < 10; ++x)
	{
		for (int y = 0; y < 10; ++y)
		{
			cout << "  " << matrix[x][y];
		}
		cout << endl;
	}
	return 1;
}

int perceptron::get_values(data_node * node, int &actual, int &predict)
{
	float sums[10] = {0};
	int outputs[10]; // Does each perceptron (0-9) fire? (Is dot product >= 0?)
	int max = 0; // Index of perceptron of largest dot product 
	int result; // Does said perceptron fire? (is dot product >= 0)

	// Start sums by multiplying bias by bias weight (1 * weight[0])
	sums[0] = 1 * weights0[0];
	sums[1] = weights1[0];
	sums[2] = weights2[0];
	sums[3] = weights3[0];
	sums[4] = weights4[0];
	sums[5] = weights5[0];
	sums[6] = weights6[0];
	sums[7] = weights7[0];
	sums[8] = weights8[0];
	sums[9] = weights9[0]; 

	
	// Dot product each weight times each pixel in image
	// Do for all perceptrons (weights 0-9 --> sums 0-9)
	int w = 0;
	for (int i = 0; i < 785; ++i)
	{
		++w;	
		sums[0] += node->data[i] * weights0[w];
		sums[1] += node->data[i] * weights1[w];
		sums[2] += node->data[i] * weights2[w];
		sums[3] += node->data[i] * weights3[w];
		sums[4] += node->data[i] * weights4[w];
		sums[5] += node->data[i] * weights5[w];
		sums[6] += node->data[i] * weights6[w];
		sums[7] += node->data[i] * weights7[w];
		sums[8] += node->data[i] * weights8[w];
		sums[9] += node->data[i] * weights9[w];
	}

	// Does each perceptron (0-9) fire? (Is its weight-data dot product >= 0?)
	// 1 if yes, 0 if no.
	for (int i = 0; i < 10; ++i)
	{
		if (sums[i] > 0) outputs[i] = 1;
		else outputs[i] = 0;
	}


	// Find largest dot proudct, set as max
	// (to start, max = 0);
	for (int i = 1; i < 10; ++i)
	{
		if (sums[i] > sums[max]) max = i;
	}

	actual = node->actual_value;
	predict = max;	
}
