/*--------------------------------------------------------*/
/* Ruthann Biel 					  */
/*  print_all is a function to print things out.          */
/*	all of its arguments are input                    */

#include "lab7.h"

void print_all(FILE * out_file,
	       thrower_t throw_list[NCOMPETITORS],
	       stats_t *throw_stats)		 
{
    int r,c;

    fprintf(out_file, "\nTrack Results");

    fprintf(out_file,"\n\nName               Try 1   Try 2   Try 3   Try 4  "
		"Best throw  Deviation");
    fprintf(out_file,  "\n----------------   -----   -----   -----   -----  "
		"---------   ---------\n");

    for (r = 0; r< NCOMPETITORS; r++)
    {
	fprintf(out_file, "%-16s  ", throw_list[r].name);
	for (c = 0; c < N_TRIES; c++)
	    fprintf(out_file, "%6.2f  ", throw_list[r].tries[c] );
		
	fprintf(out_file, "  %6.2f   ", throw_list[r].best_throw );
	fprintf(out_file, "  %6.2f   \n", throw_list[r].deviation );
    }

    fprintf(out_file, "\n\nBest Throw Average  = %6.2f meters ", throw_stats->average_of_best_throws);
    fprintf(out_file, "\n\nWinning Throw       = %6.2f meters\n\n", throw_stats->winning_throw);

    return;
}
/*--------------------------------------------------------*/
