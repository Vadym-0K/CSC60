/*----------------------------------------------------------*/
/* Ruthann Biel                                             */
/* This function will open the output file and return the   */
/* file pointer name to the main program.                   */

#include "lab7.h"

FILE * open_out_file (void)
{
    FILE * outfile;

    outfile = fopen(OUT_FILENAME, "w");
    if (outfile == NULL)
    {
	printf("Error on fopen of %s \n", OUT_FILENAME);
	exit(EXIT_FAILURE);
    }
    fprintf(outfile, "\nVadym Kharchenko, Lab 7 output. \n");

    return outfile;
}

/*-----------------------------------------------------------*/
