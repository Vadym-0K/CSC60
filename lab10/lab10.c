/* Author(s): Ruthann Biel & Vadym Kharchenko
 * This is csc60mshell.c
 * This is lab10.c the csc60mshell
 * This program serves as the base for doing labs 9 and 10.
 * Student is required to use this program to build a mini shell
 * using the specification as documented in the directions.
 * Date: Fall 2021
 */

#include "lab9_10.h"


/* ----------------------------------------------------------------- */
/*                  The main program starts here                     */
/* ----------------------------------------------------------------- */
int main(void) //int main (int argc, char * argv[])
{
    char CmdLine[MAXLINE];
    char *argv[MAXARGS];
    int argc;

    // Loop forever to wait and process commands
    while (TRUE)
    {
        printf("\ncsc60shell> ");

        /* read the command the user types in */
        fgets(CmdLine, MAXLINE, stdin);

        /* Call ParseLine to build argc/argv; their limits declared above */
        // You write this call
        argc = ParseCmd(CmdLine, argv);

        // REQUIRED: Just-to-make-sure printfs
        printf("Argc = %i \n",  argc);
        int i;
        for(i = 0; i < argc; i++)
        {
            printf ("Argv %i = %s \n", i, argv[i]);
        }

        // If user hits enter key without a command, continue to loop again at the beginning
        // You write this line.  Hint: if argc is zero, no command declared */
        if (argc == 0)
        {
             printf("A command was not entered.");
             continue;
        }


        // Handle build-in command: exit, pwd, or cd
        // See the directions for the algorithms to do these 3 commands.

        if(strcmp(argv[0], "exit") == 0)       // Sample of complete line.
        {
             exit(EXIT_SUCCESS);
        }

        else if(strcmp(argv[0], "pwd") == 0)
        {
            char PathBuf[MAX_PATH_LENGTH];
            //"(May skip error checking here)"
            getcwd(PathBuf, sizeof(PathBuf));
            printf("%s\n", PathBuf);

        }

        else if(strcmp(argv[0], "cd") == 0)
        {
             char *dir;
             if(argc == 1)
                    dir = getenv("HOME");
             else
                    dir = argv[1];
             if(chdir(dir) < 0)
                    perror("error changing directory");
        }


        /* Else, fork off a process */
        else
        {
            RunExtCmd(argc, argv);

        }      /* end of the if-else-if */

    }	   /* end of the while loop */
}   	   /* end of main */
