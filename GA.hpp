#ifndef GA_HPP
#define GA_HPP
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class GA
{
public:
    GA(int popsize_, int chromosome_length_, int rand_max_, int rand_min_, int generations_, int elitism_);
    ~GA();
    std::vector<std::vector<float> > createPopulation();
    std::vector<std::vector<float> > decode(std::vector<float> chromosome);
    std::vector<float> crossover(std::vector<float> parent_x, std::vector<float> parent_y);
    std::vector<float> mutate(std::vector<float> parent);
    std::vector<std::vector<float> > nextGeneration(std::vector<std::vector<float> > previous_pop, std::vector<int> fitness, int tournament_size);


  private:
    std::vector<float> createChromosome();
    int popsize, chromosome_length, rand_max, rand_min, generations, elitism;

};
#endif
