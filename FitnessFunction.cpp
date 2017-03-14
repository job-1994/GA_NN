#include "FitnessFunction.hpp"
#include <math.h>

bool visited[11][11]={false};
int fitness_array[11][11];

FitnessFunction::FitnessFunction(){}

FitnessFunction::~FitnessFunction(){}

void FitnessFunction::return_visited()
{
	for(int i=1;i<13;i++)
	{
		for(int j=1;j<13;j++)
		{
			printf("%i ",visited[i][j]);
		}
		printf("\n\r");
	}
}

void FitnessFunction::initialise()
{
	visited[11][11] = {false};
}

bool FitnessFunction::update_location(double x_coordinate_current, double y_coordinate_current, double x_coordinate_past, double y_coordinate_past)
{
	//NEED A CHECK OUTSIDE LOOP FOR Z COORDINATE
	
	bool i_have_been_here_before = false;
	bool i_have_visited_here = false;
	
	int pos=0;
	
	int x_block = 0;
	int y_block = 0;
	int x_block_past = 0;
	int y_block_past = 0;
	
    for(float x = -0.6; x < 0.6; x = x + 0.1)
	  {
		y_block = 0;
		for(float y = -0.1; y < 1.1; y = y + 0.1)
		{
		 // printf(" x < pos_x < x + 0.1: %f < %f < %f\n", x,x_coordinate_current, x + 0.1);
		//  printf(" y < pos_y < y + 0.1: %f < %f < %f\n", y,y_coordinate_current, y + 0.1);
		  // if(pos_x > x && pos_x < x + 0.1 && pos_y > y && pos_y < y + 0.1)
		  if(x_coordinate_past > x && x_coordinate_past < x + 0.1)
		  {
			  if(y_coordinate_past > y && y_coordinate_past < y + 0.1)
			  {
				//  printf("Reached point\n");
				  x = 1;
				  y = 2;
			  } 
		  }
		  else
		  {
			pos++;
		  }
		  y_block_past++;
		}
		x_block_past++;	
	  }
	  
	pos = 0;
	
  for(float x = -0.6; x < 0.6; x = x + 0.1)
  {
	  //x_block starts at 1 and ends at 12
	y_block = 0;
    for(float y = -0.1; y < 1.1; y = y + 0.1)
    {
     // printf(" x < pos_x < x + 0.1: %f < %f < %f\n", x,x_coordinate_current, x + 0.1);
    //  printf(" y < pos_y < y + 0.1: %f < %f < %f\n", y,y_coordinate_current, y + 0.1);
      // if(pos_x > x && pos_x < x + 0.1 && pos_y > y && pos_y < y + 0.1)
      if(x_coordinate_current > x && x_coordinate_current < x + 0.1)
      {
		  if(y_coordinate_current > y && y_coordinate_current < y + 0.1)
		  {
            //  printf("Reached point\n");
              x = 1;
              y = 2;
		  } 
	  }
      else
      {
		pos++;
      }
	  y_block++;
    }
	x_block++;	
  }
  
  printf("X block: %i\n\r",x_block);
  printf("Y block: %i\n\r",y_block);
  if(x_block==x_block_past&&y_block==y_block_past)
  {}
  else
  {
	if(visited[x_block][y_block]==1)
	{
		i_have_been_here_before = true;
	}
	
  }
	  
  visited[y_block][x_block]=true;
  
  return i_have_been_here_before;
}

bool FitnessFunction::get_visited(double x_coordinate,double z_coordinate,double y_coordinate,double x_coordinate_past,double y_coordinate_past)
{
	//printf("x-coordinate before rounding: %f\n\r",x_coordinate);
	//printf("y-coordinate before rounding: %f\n\r",y_coordinate);
	//printf("z-coordinate: %f\n\r",z_coordinate);
	
	bool i_have_visited_here = false;

	if(z_coordinate<1.3||z_coordinate>1.4)
		printf("Yeah, you've fallen off the edge mate\n\r");
	else
	{
		i_have_visited_here = update_location(x_coordinate,y_coordinate,x_coordinate_past,y_coordinate_past);
		if(i_have_visited_here == true)
			printf("I have been here before");
			
	}
	
	return i_have_visited_here;
}
