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
  int index = rand()%parent.size() + 1;
  child[index] = (rand_max - rand_min) * ((float)rand() / RAND_MAX) + rand_min;
  return child;
}

std::vector<int> tournamentOutcome()
{

}


std::vector<std::vector<float> > GA::nextGeneration(std::vector<std::vector<float> > previous_pop, std::vector<int> fitness, int tournament_size)
{
  std::vector<std::vector<float> > new_pop(previous_pop.size());
  std::vector<float> parent_x, parent_y, child;
  std::vector<int> tournament_index(tournament_size);
  std::vector<std::vector<float> > tournament_entries(tournament_size);

  for (int i = 0; i < tournament_size; i++)
  {
    tournament_index[i] = rand()%previous_pop.size() + 1;
    tournament_entries[i] = previous_pop[tournament_index[i]];
    printf("Tournament entry %i index: %i\n", i, tournament_index[i]);
  }



  // for(int i = 0; i < previous_pop.size() - 2; i++)
  // {
  //   for (int j = 0; j < tournament_size; j++)
  //   {
  //
  //   srand(time(NULL)+ i + 1);
  //   index_x = rand()%previous_pop.size() + 1;
  //   srand(time(NULL)+ i + 2);
  //   index_y = rand()%previous_pop.size() + 1;
  //   tournamentOutcome();
  //   printf("parent x index: %i, parent y index: %i\n", index_x, index_y);
  //   parent_x = previous_pop[index_x];
  //   parent_y = previous_pop[index_y];
  // }
  //
  // }


  return new_pop;
}
