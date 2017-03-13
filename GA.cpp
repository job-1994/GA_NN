#include "GA.hpp"

GA::GA(int popsize_, int chromosome_length_, int rand_max_, int rand_min_, int generations_, int elitism_)
{
  popsize = popsize_;
  chromosome_length = chromosome_length_;
  rand_max = rand_max_;
  rand_min = rand_min_;
  generations = generations_;
  elitism = elitism_;
}

GA::~GA(){}

std::vector<std::vector<float> > GA::createPopulation()
{
  std::vector<std::vector<float> > pop(popsize);
  std::vector<float> pop_member;
  for (int i = 0; i < popsize; i++)
  {
    srand(time(NULL)+ i + 1);
    pop_member = createChromosome();
    pop[i] = pop_member;
  }
  return pop;
}

std::vector<float> GA::createChromosome()
{
  std::vector<float> chromosome(chromosome_length);
  for(int i = 0; i < chromosome_length; i++)
  {
    chromosome[i] = (rand_max - rand_min) * ((float)rand() / RAND_MAX) + rand_min;
  }
  return chromosome;
}

std::vector<std::vector<float> > GA::decode(std::vector<float> chromosome)
{
  std::vector<std::vector<float> > decoded_chromosome(3);
  std::vector<float> weights_in_chromosome(24);
  for (int i = 0; i < 24; i++)
  {
    weights_in_chromosome[i] = chromosome[i];

  }

  std::vector<float> weights_hidden_chromosome(16);
  for (int i = 0; i < 16; i++)
  {
    int j = i + 24;
    weights_hidden_chromosome[i] = chromosome[j];
  }

  std::vector<float> weights_out_chromosome(8);
  for (int i = 0; i < 8; i++)
  {
    int j = i + 40;
    weights_out_chromosome[i] = chromosome[j];
  }

  decoded_chromosome[0] = weights_in_chromosome;
  decoded_chromosome[1] = weights_hidden_chromosome;
  decoded_chromosome[2] = weights_out_chromosome;

  return decoded_chromosome;
}

std::vector<float> GA::crossover(std::vector<float> parent_x, std::vector<float> parent_y)
{
  std::vector<float> child(parent_x.size());
  srand(time(NULL));
  int index = rand()%parent_x.size() + 1;
  for(int i = 0; i < index; i++)
    child[i] = parent_x[i];
  for(int i = index; i < parent_x.size(); i++)
    child[i] = parent_y[i];
  return child;
}

std::vector<float> GA::mutate(std::vector<float> parent)
{
  std::vector<float> child = parent;
  srand(time(NULL));
  int index = rand()%parent.size() + 1;
  child[index] = (rand_max - rand_min) * ((float)rand() / RAND_MAX) + rand_min;
  return child;
}

std::vector<std::vector<float> > nextGeneration(std::vector<std::vector<float> > previous_pop)
{

}
