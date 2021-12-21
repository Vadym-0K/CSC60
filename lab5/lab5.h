/*---------------------------------------------------------------*/
/* Vadym Kharchenko                                              */
/* lab5.h                                                        */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



#define MAX_SIZE 40          /* max length of a grade file       */
#define DIST_SIZE 11         /* max length of distribution array */

// All the needed function prototypes

/* function to get the data  and return filesize       */
int get_data(const char *filename,  /* input, current file name */
	     int grades[]);         /* output, the filled array */

/* function to return average & distributed grade count   */
void class_stats(int grades[],	        /* input, array that holds data   */
		 int number_of_grades,  /* input, actual size of the file */
		 double *average,       /* output, average of the array   */
		 int distribution[]);   /* output, distribution count     */

void print_all(	const char *filename,  /* input, the current filename    */
		double *average,       /* input, the class average       */
		int distribution[]);   /* input, the grade distribution  */
