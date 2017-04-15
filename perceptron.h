#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;


struct data_node
{
	int actual_value;
	float data[784];
	data_node * next;
};


class perceptron
{
	public:
		perceptron(float learning_rate);
		~perceptron(void);

		int add_data(data_node * & head);
		int print_data(void);

		int train(data_node * training_data);
	private:
		float learning_rate;
		data_node * head;
		float weights_0[785];
		float weights_1[785];
		float weights_2[785];
		float weights_3[785];
		float weights_4[785];
		float weights_5[785];
		float weights_6[785];
		float weights_7[785];
		float weights_8[785];
		float weights_9[785];
};
