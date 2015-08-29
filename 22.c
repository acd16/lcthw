#include "22.h"

const char * Name = "acd16";
int Gsize = 1000;

void scope_demo(int count){
		log_info("count in is : %d", count);
		if(count>10){
				int count = 100;
				log_info("count in braces : %d", count);
		}
		log_info("count out is : %d", count);
		count = 3000;
		log_info("count end : %d", count);
}

int main(int argc, char ** argv){
		log_info("name %s, age %d", Name, get_age());
		set_age(100);
		log_info("age now : %d", get_age());
	    print_size();
		Gsize = 9;
		print_size();
		log_info("Ratio 1 : %f", update_ratio(2.0));	
		log_info("Ratio 2 : %f", update_ratio(10.0));	
		log_info("Ratio 3 : %f", update_ratio(300.0));	
		int count = 4;
		scope_demo(count);
		scope_demo(count * 20);
		log_info("final count : %d", count);
		return 0;
}
