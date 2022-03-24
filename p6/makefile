t1: t1.o t1_func.o
	gcc t1.o t1_func.o -o t1
t1.o: t1.c t1_func.h
	gcc -c t1.c
t1_func.o: t1_func.c t1_func.h
	gcc -c t1_func.c