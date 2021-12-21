/* ----------------------------------------------------------------- */
/*                  ParseCmd                                         */
/* ----------------------------------------------------------------- */
/* Parse the input line into argc/argv format */

#include "lab9_10.h"

int ParseCmd (char *cmdline, char **argv)
{
    int argc = 0;
    char *separator = " \n\t";  /* Includes space, Enter, Tab */

    /* strtok searches for the characters listed in separator */
    argv[argc] = strtok(cmdline, separator);
 
    while ((argv[argc] != NULL) && (argc+1 < MAXARGS))
    { 
	argv[++argc] = strtok((char *) 0, separator);
    }
    return argc;
}
/* end of function ParseCmd
/* ----------------------------------------------------------------- */
