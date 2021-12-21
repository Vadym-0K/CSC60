//  function RunExtCmd

#include "lab9_10.h"
void RunExtCmd(int argc, char **argv)
{
     int status;
     pid_t pid;
     pid = fork();
     switch(pid)
     {
          case -1:
               perror("Fork error");
               exit(EXIT_FAILURE);
          case 0:
               // I am the child process. I will execute the call to execvp
               ProcessCmd(argc, argv);
               break;
          default:
               // I am the parent process.
               if(wait(&status) == -1)
                    perror ("Error on the parent wait");
               else
                    printf("Child returned status: %d\n", status);
               break;
     }              /* end of the switch */
     return;
}       	   /* end of RunExternalCommand */
