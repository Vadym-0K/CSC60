#####################
#Vadym Kharchenko
#Lab 10
#####################
lab10: lab10.o RunExtCmd.o ParseCmd.o ProcessCmd.o Redirection.o lab9_10.h
		gcc lab10.o RunExtCmd.o ParseCmd.o ProcessCmd.o Redirection.o -o lab10 -Wall
lab10.o: lab10.c lab9_10.h
		gcc -c lab10.c -Wall
RunExtCmd.o: RunExtCmd.c ProcessCmd.c lab9_10.h
		gcc -c RunExtCmd.c ProcessCmd.c -Wall
ProcessCmd.o: ProcessCmd.c Redirection.c lab9_10.h
		gcc -c ProcessCmd.c Redirection.c -Wall
Redirection.o: Redirection.c lab9_10.h
		gcc -c Redirection.c -Wall
