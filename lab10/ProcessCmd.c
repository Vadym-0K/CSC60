/* ----------------------------------------------------------------- */
/*                  ProcessCmd                                       */
/* ----------------------------------------------------------------- */
#include "lab9_10.h"
void ProcessCmd(int argc, char **argv) {

    /* Step 1: Call Redirection to deal with operators:            */
    Redirection(argc, argv);
    /* < , or  >, or both                                           */


    /* Step 2: perform system call execvp to execute command        */
    /* Hint: Please be sure to review execvp.c sample program       */
    /* or the Lab10slides                                           */
    int ret = execvp(argv[0], argv);

    if (ret  == -1)
    {
         fprintf(stderr, "Error on the exec call\n");
         exit(EXIT_FAILURE);
    }

 }
/* ----------------------------------------------------------------- */
