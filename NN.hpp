#ifndef NN_HPP
#define NN_HPP

#include <vector>
#include <math.h>
#include <stdio.h>

class NN
{
public:
	NN();
	~NN();
	void printData();
	void setData(int epoch_, int size_input_layer_, int size_hidden_layer_, int size_output_layer_, std::vector<float> speeds_, std::vector<std::vector<float> > weights_);
	float activationFunction(float neuron_input, const int gradient = 1);
	std::vector<float> getReaction();
private:
	int epoch;
	float in_left, in_right, out_left, out_right;
	std::vector<float>  sensors, weights_in, weights_out, weights_hidden;
	std::vector<std::vector<float> > weights;
	std::vector<float> inputLayer();
	std::vector<float> hiddenLayer(std::vector<float> in_output);
	std::vector<float> outputLayer(std::vector<float> hidden_output);
};
#endif
