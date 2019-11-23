#AUTHOR: Christiana Temiola
#STUDENT NUMBER: C00220551
#DATE: 21ST NOVEMBER 2019

#TITLE: LAB 6:PRODUCER-CONSUMER
	  #Filename: Makefile

#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread

CFILES= SafeBuffer.cpp Semaphore.cpp Event.cpp main.cpp
OBJFILES= SafeBuffer.o Semaphore.o Event.o main.o



#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL: $(OBJFILES)
	$(CC) -o lab6 $(OBJFILES) $(CFLAGS)


#this is customary and just deletes all .o files
CLEAN:
	rm *.o
