#####################
#Vadym Kharchenko
#Lab 5
#####################
lab5: lab5.o class_stats.o lab5.h
		gcc lab5.o class_stats.o lab5.h -o lab5
lab5.o: lab5.c lab5.h
		gcc -c lab5.c -lm
class_stats.o: class_stats.c lab5.h
		gcc -c class_stats.c -lm
