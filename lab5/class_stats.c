/*-------------------------------------------------------------------------*/
// Vadym Kharchenko
// Lab 5, class_stats function
/*-------------------------------------------------------------------------*/

#include "lab5.h"
void class_stats( int grades[], int number_of_grades, double *average, int distribution[])
{
     *average = 0;
     int i, n;
     for (i = 0 ; i < DIST_SIZE; i++)
     {
          distribution[i] = 0;
     }
     for (n = 0 ; n < number_of_grades; n++)
     {
          *average += grades[n];
          distribution[grades[n]/10]++;
     }

     *average /= number_of_grades;
}

/*-------------------------------------------------------------------------*/
