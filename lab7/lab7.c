/* Ruthann Biel */
/* Lab7.c main  */

#include "lab7.h"

int main(void)
{
    thrower_t throw_list[NCOMPETITORS]; 
    stats_t throw_stats = {0.0, 0.0};	
	
    FILE * out_file;    /* file pointer for the output file  */
			
    out_file = open_out_file ();
	
    get_data(IN_FILENAME, throw_list);
 
    get_stats(throw_list, &throw_stats); 
		      
    print_all(out_file, throw_list, &throw_stats);
	
    return EXIT_SUCCESS;
}