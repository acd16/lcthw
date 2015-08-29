#include "22.h"

static int Age = 30;
extern int Gsize;

int get_age(){
		return Age;
}

void set_age(int num){
Age = num;
}

void print_size(){
		log_info("Gsize is : %d", Gsize);
}

float update_ratio(double new_ratio)
{
		static float ratio = 1.0;
		float old_ratio = ratio;
		ratio = new_ratio;

		return old_ratio;
}

