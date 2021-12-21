/* ----------------------------------------------------------------- */
/*                  Redirection                                      */
/*                  Lab 10                                           */
/*                  Vadym Kharchenko                                 */
/* ----------------------------------------------------------------- */
#include "lab9_10.h"

void Redirection(int argc, char **argv)
{
     int OutLoc = 0;
     int InLoc = 0;

     int i = 0;
     for(i = 0; i < argc; i++)
     {
          if(strcmp(argv[i],">") == 0)
          {
               if(OutLoc != 0)
               {
                    fprintf(stderr,"Error, cannot output to more than one file\n");
                    _exit(EXIT_FAILURE);
               }
               else if(i == 0)
               {
                    fprintf(stderr,"No command entered\n");
                    _exit(EXIT_FAILURE);
               }
               OutLoc = i;
          }
          else if(strcmp(argv[i],"<") == 0)
          {
               if (InLoc != 0)
               {
                    fprintf(stderr,"ERROR, Cannot input from more than one file\n");
                    _exit(EXIT_FAILURE);
               }
               else if(i == 0)
               {
                    fprintf(stderr,"ERROR, No command entered\n");
                    _exit(EXIT_FAILURE);
               }
               InLoc = i;
          }
     }

     if(OutLoc != 0)
     {
          if (argv[OutLoc + 1] == NULL)
          {
               fprintf(stderr,"ERROR, There is no file for OutLoc\n");
               _exit(EXIT_FAILURE);
          }

          int fd = open(argv[OutLoc + 1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); //int fd = open(argv[OutLoc + 1], O_RDWR );
          if(fd < 0) {
			perror ("Error, file to read/write is not opened\n");
			_exit(EXIT_FAILURE);
		}
          dup2(fd, 1);
          close(fd);
          // Set things up for the future exec call by setting argv[OutLoc] to NULL
          argv[OutLoc] = NULL;
     }

     if(InLoc != 0)
     {
          if (argv[InLoc + 1] ==  NULL)
          {
               fprintf(stderr,"ERROR. There's no file to read\n");
			_exit(EXIT_FAILURE);
          }
          int fd = open( argv[InLoc + 1] , O_RDWR); //int fd = open( argv[InLoc + 1] , O_RDONLY);
          if (fd < 0) {
			perror("Error, file to read is not opened\n");
			_exit(EXIT_FAILURE);
		}
          dup2(fd, 0);
          argv[InLoc] = NULL;
     }
}
