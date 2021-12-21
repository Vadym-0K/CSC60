/*-----------------------------------------------------------*/
/* This function will open and read data into an array.      */
/* It will return the value of the real length of the array. */

#include "lab7.h"

void get_data (char *filename,                      /* input  */ 
	       thrower_t throw_list[NCOMPETITORS] )   /* output */
{
    int n, c;
    FILE *in_file;

    /* Open the data file and read in the array */
    in_file = fopen(filename, "r");
    if (in_file == NULL)
    {
	printf("Error on fopen of %s \n", filename);
	exit(EXIT_FAILURE);
    }
	
    /* Read the competitor's names first. */

    for (n=0; n < NCOMPETITORS; n++)	/* "n" for names of throwers */
    {
	/* "fgets" gets a string including the new line attached */
	fgets(throw_list[n].name, 19, in_file); 

    	/* strings require that the last character is NULL */
	throw_list[n].name[19] = 0;

	/* This code removes the attached new line */
	/* It will find the new line embedded in the name which it 
	   then sets to NULL.  */

	char *new_line_position = strchr(throw_list[n].name, '\n') ;
	if (new_line_position != NULL)
	    *new_line_position = 0;
    }

    /* Read the sets of tries */
    for (c=0; c < N_TRIES; c++) 
  	for(n = 0; n < NCOMPETITORS; n++)
	    fscanf(in_file, "%lf", &throw_list[n].tries[c]); 
	
    fclose(in_file);
    return;
}

/*-------------------------------------------------------------------*/
