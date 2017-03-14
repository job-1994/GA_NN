#include <stdio.h>
#include <cstdlib>
#include <vector>
#include "NN.hpp"
#include "GA.hpp"
#include "FitnessFunction.hpp"

const int size_input_layer_main = 6;
const int size_hidden_layer_main = 4;
const int size_output_layer_main = 2;
const int in_size = size_input_layer_main*size_hidden_layer_main;
const int hidden_size = size_hidden_layer_main*size_hidden_layer_main;
const int out_size = size_hidden_layer_main*size_output_layer_main;
const int epoch = 4;
const int popsize = 100; //500;
const int rand_max = 1;
const int rand_min = -1;
const int generations = 1500;
const int elitism = 2;

std::vector<float>  weights_main_in(in_size), weights_main_hidden(hidden_size), weights_main_out(out_size), sensors_main(size_input_layer_main);
std::vector<std::vector<float> > weights_main(3);

int main()
{
  srand(time(NULL));
  NN nn;
  GA ga(popsize, in_size + hidden_size + out_size, rand_max, rand_min, generations, elitism);
  FitnessFunction ff;

  float value = 0.1;
  for(int i = 0; i < size_input_layer_main; i++)
  {
    sensors_main[i] = value;
    value = value + 0.1;
  }
  std::vector<std::vector<float> > pop = ga.createPopulation();
  std::vector<int> fit(pop.size());
  for(int i = 0; i < fit.size(); i++)
  {
    fit[i] = rand()%20 + 1;
  }
  for(int i = 0; i < fit.size(); i++)
  {
    printf("Fitness %i: %i\n", i, fit[i]);
  }

  pop = ga.nextGeneration(pop, fit, 5);
  
  // for(int i = 0; i < popsize; i++)
  // {
  //   weights_main = ga.decode(pop[i]);
  //   std::vector<float> result;
  //   nn.setData(epoch, size_input_layer_main, size_hidden_layer_main, size_output_layer_main, sensors_main, weights_main);
  //   nn.printData();
  //   result = nn.getReaction();
  //
  //   printf("Output Wheel Speeds, Left: %f, Right: %f \n",result[0], result[1]);
  // }




}







// for (int i = 0; i < pop.size(); i++)
// {
//   printf("\nPop Member %i: ", i);
//   for (int j = 0; j < pop[i].size(); j++)
//   {
//     printf("%f, ", pop[i][j]);
//   }
// }
