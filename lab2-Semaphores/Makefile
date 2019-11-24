#AUTHOR: CHRISTIANA TEMIOLA
#STUDENT NUMBER: C00220551
#DATE: 15TH OCTOBER 2019
#TITLE: LAB 2:SEMAPHORES --> Makefile

#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.

       # CC and CFLAGS are constants defined.
CC=g++                           # CC describes the C compiler to use.
CFLAGS= -std=c++17 -pthread      # CFLAGS describes the list of flags to pass to                                   the compilation command.

#This rule says that each .o file depends on a .cpp file of the same name and to generate the .o file, 'make' needs to compile the .c file using the compiler defined in the CC macro.
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)


ALL: main.o Semaphore.o
	$(CC) -o mutex main.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL


#this is customary and just deletes all .o files
CLEAN:
	rm *.o
