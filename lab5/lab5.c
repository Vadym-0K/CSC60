/*---------------------------------------------------------------*/
/* Vadym Kharchenko                                              */
/* LAB 5   1-dimensional arrays                                  */
/* Change the name above.                                        */
/* Change the comments on the "const" lines as per directions    */

#include "lab5.h"

// const char *FILENAME[] = 	/* array of the sample data file name */
//     {"lab5s.dat", NULL };

const char *FILENAME[] = 	/* array of the data file names */
    {"lab5a.dat", "lab5b.dat", NULL };


/*---------------------------------------------------------------*/
int main(void)
{
    int file_count = 0;           /* keeps track of which file we are on */
    int number_of_grades = 0;     /* actual size of current grade file   */
    int grades[MAX_SIZE];         /* the array                           */
    double average;  	          /* average of the array list           */
    int distribution[DIST_SIZE];  /* distribution count of the grades    */

    printf("\n\nVadym Kharchenko.  Lab 5. \n");

    /* loop through each file, reading it, and getting stats on it */

    for (file_count=0; FILENAME[file_count] != NULL; file_count++)
    {
       number_of_grades = get_data( FILENAME[file_count], grades);

       class_stats(grades, number_of_grades, &average, distribution);

       print_all(FILENAME[file_count], &average, distribution);
    }
    return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------*/
/* This function will open the input file, read the data into      */
/* array k, and return filesize.                                   */

int get_data(const char *filename,  /* input, current file name */
	     int grades[])          /* output, the filled array */
{
    FILE * input_file;
    int number_of_grades =0;

    input_file = fopen(filename, "r");
    if (input_file == NULL)
    {
	printf("Error on file-open of file %s", filename);
	exit(EXIT_FAILURE);
    }

    while ((fscanf(input_file, "%i", &grades[number_of_grades])) == 1)
	number_of_grades += 1;

    return number_of_grades;
}

/*-----------------------------------------------------------------*/
/* This function will print all but your name which is above at    */
/* line 24  */

void print_all(	const char *filename,	 /* input, the current filename   */
		double *average,         /* input, the class average      */
		int distribution[])      /* input, the grade distribution */
{
    int d;

    printf("\nStats for %s:  ", filename);
    printf("\n\n   Average grade = %f ", *average);
    printf("\n\n   Grade Distribution:  \n");
    for (d = DIST_SIZE; d >0; d--)
	printf("      Category %3i - %2i \n", (d-1)*10, distribution[d-1]);

    printf("\n");

    return;
}
/*-----------------------------------------------------------------*/
