#include "include/NN.hpp"

int epoch, size_input_layer, size_hidden_layer, size_output_layer;
float sensor_left, sensor_right, out_left, out_right;
std::vector<float>  weights_in, weights_out, weights_hidden;


NN::NN(){}

NN::~NN(){}

void NN::setData(int epoch_, int size_input_layer_, int size_hidden_layer_, int size_output_layer_, std::vector<float> sensors_, std::vector<std::vector<float> > weights_)
{
	epoch = epoch_ - 1;
	size_input_layer = size_input_layer_;
	size_hidden_layer = size_hidden_layer_;
	size_output_layer = size_output_layer_;
	sensors = sensors_;
	weights_in = weights_[0];
	weights_hidden = weights_[1];
	weights_out = weights_[2];
	// printData();
}

void NN::printData()
{
	printf("Printing all Variable Data \n");
	printf("-------------------------------- \n");
	printf("-------------------------------- \n");
	printf("Epochs: %i \n", epoch + 1);
	printf("-------------------------------- \n");
	printf("Sizes of Layers: \n");
	printf("Input Layer: %i \n", size_input_layer);
	printf("Hidden Layer: %i \n", size_hidden_layer);
	printf("Output Layer: %i \n", size_output_layer);
	printf("-------------------------------- \n");
	for(int i = 0; i < sensors.size(); i++)
		printf("Sensor %i : %f \n", i, sensors[i]);
	printf("-------------------------------- \n");

	for(int i = 0; i < weights_in.size(); i++)
		printf("Weights In %i : %f \n", i, weights_in[i]);

	printf("-------------------------------- \n");
	for(int i = 0; i < weights_hidden.size(); i++)
		printf("Weight Hidden %i : %f \n", i, weights_hidden[i]);

	printf("-------------------------------- \n");
	for(int i = 0; i < weights_out.size(); i++)
		printf("Weights Out %i : %f \n", i, weights_out[i]);

	printf("-------------------------------- \n");
	printf("-------------------------------- \n");
	printf(" \n");
}

std::vector<float> NN::inputLayer()
{
	std::vector<float> inputLayer_output(3);
	float neuron_value;
	printf("Input Layer: \n");
	printf("-------------------------- \n");
	int l = 0;
	for(int i = 0; i < size_hidden_layer; i++)
	{
		for (int j = 0; j < size_input_layer; j++)
		{
			inputLayer_output[i] = inputLayer_output[i] + sensors[j]*weights_in[j + l];
			// printf("sensor %i : %f, weight %i : %f\n", j, sensors[j], j + l, weights_in[j + l]);
			// printf("New value for Neuron %i : %f\n", i, inputLayer_output[i]);
		}
		l = l + size_input_layer;
	}

	printf("Input Layer Fire Value: \n");
	for(int i = 0; i < size_hidden_layer; i++)
	{
		inputLayer_output[i] = activationFunction(inputLayer_output[i]);
		printf("Neuron %i : %f\n", i, inputLayer_output[i]);
	}
	return inputLayer_output;
}

std::vector<float> NN::hiddenLayer(std::vector<float> inputLayer_output)
{
	std::vector<float> hiddenLayer_output(inputLayer_output);
	float neuron_tmp[4];
	printf("\nHidden Layer: \n");
	printf("-------------------------- \n");
	for (int i = 0; i < epoch; i++)
	{
		// printf("Epoch : %i\n", i);
			for (int a = 0; a < size_hidden_layer; a++) {
				neuron_tmp[a] = hiddenLayer_output[a];
			}

		int l = 0;
		for (int j = 0; j < size_hidden_layer; j++)
		{
				for (int k = 0; k < size_hidden_layer; k++)
				{
					hiddenLayer_output[j] = hiddenLayer_output[j] + neuron_tmp[k]*weights_hidden[k + l];
					// printf("neuron %i : %f, weight %i : %f\n", k, neuron_tmp[j], k + l, weights_hidden[k + l]);
					// printf("New value for Neuron %i : %f\n", j, hiddenLayer_output[j]);
				}
				l = l + size_hidden_layer;
		}
	}
	printf("Hidden Layer Fire Value: \n");
	for(int i = 0; i < size_hidden_layer; i++)
	{
		hiddenLayer_output[i] = activationFunction(hiddenLayer_output[i]);
		printf("Neuron %i : %f\n", i, hiddenLayer_output[i]);
	}
	return hiddenLayer_output;
}

std::vector<float> NN::outputLayer(std::vector<float> hidden_output)
{
	printf("\nOutput Layer: \n");
	printf("-------------------------- \n");

	std::vector<float> outputLayer_output(size_input_layer);
	int l = 0;

	for (int i = 0; i < size_output_layer; i++)
	{
		for (int j = 0; j < size_hidden_layer; j++)
		{
			outputLayer_output[i] = outputLayer_output[i] + hidden_output[j]*weights_out[j + l];
			// printf("neuron %i : %f, weight %i : %f\n", i, outputLayer_output[i], j + l, weights_out[j + l]);
			// printf("New value for Neuron %i : %f\n", i, outputLayer_output[i]);
		}
		l = l + size_hidden_layer;
	}

	printf("Output Layer Fire Value\n");
	for (int i = 0; i < size_output_layer; i++)
	{
		outputLayer_output[i] = activationFunction(outputLayer_output[i]);
		printf("Neuron %i: %f\n", i, outputLayer_output[i]);
	}
	return outputLayer_output;
}

float NN::activationFunction(float neuron_input, const int gradient) //returns fire value
{
	float neuron_output;
	// neuron_output = gradient * (2/(1+exp(-2*neuron_input))) - 1;
	neuron_output = neuron_input;
	return neuron_output;
}

std::vector<float> NN::getReaction()
{
	printf("\n/*---------------------------------------*/\n");
	printf("Start Neural Network\n");
	printf("/*---------------------------------------*/\n");
	std::vector<float> layer_in, layer_hidden, layer_out;
	std::vector<float> reaction(size_input_layer);
	layer_in = inputLayer();
	layer_hidden = hiddenLayer(layer_in);
	layer_out = outputLayer(layer_hidden);
	reaction[0] = layer_out[0];
	reaction[1] = layer_out[1];
	printf("/*---------------------------------------*/\n");
	printf("End of Neural Network\n");
	printf("/*---------------------------------------*/\n\n");
	return reaction;
}
