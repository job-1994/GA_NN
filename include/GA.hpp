#ifndef GA_HPP
#define GA_HPP
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class GA
{
public:
    GA(int popsize_, int chromosome_length_, int rand_max_, int rand_min_);
    ~GA();
    std::vector<std::vector<float> > createPopulation();
    std::vector<std::vector<float> > decode(std::vector<float> chromosome);

  private:
    std::vector<float> createChromosome(float min, float max);
    int popsize, chromosome_length, rand_max, rand_min;

};
#endif
