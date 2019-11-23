#AUTHOR: Christiana Temiola
#STUDENT NUMBER: C00220551
#DATE: 11TH NOVEMBER 2019
#TITLE: LAB 5:Reusable Barrier Class
	  #Filename: Makefile

#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread -Wall -g -O0


#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) 

ALL: 
	$(CC) -o reusableBarrier main.cpp Semaphore.cpp Barrier.cpp $(CFLAGS)


#this is customary and just deletes all .o files
CLEAN:
	rm *.o
