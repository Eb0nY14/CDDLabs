#AUTHOR: CHRISTIANA TEMIOLA
#STUDENT NUMBER: C00220551
#DATE: 17TH OCTOBER 2019
#TITLE: LAB 3:RENDEZVOUS --> Makefile

#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL: main.o Semaphore.o
	$(CC) -o rendezvous main.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)


#this is customary and just deletes all .o files
CLEAN:
	rm *.o
