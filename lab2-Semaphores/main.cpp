/*!  \AUTHOR: CHRISTIANA TEMIOLA
     \STUDENT NUMBER: C00220551
     \DATE: 15TH OCTOBER 2019
     \TITLE: LAB 2:SEMAPHORES
     \main.cpp
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>

/*! \class Signal
    \brief Signalling with Semaphores. This file contains the main function 

  It creates at least two threads where one thread signals the other using a common Semaphore. 

*/

/*! This function named "taskOne" takes 2 arguments of types: shared pointer & an integer and   returns type void by displaying the below message first*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}

/*! This second function named "taskTwo" takes same argument types as taskOne and returns type  void by displaying the below message second*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

/*! The main function that creates the number of threads needed, in this case 2 threads and     serves as a driver test for the two functions above. It calls th    e 2 function s and displ  ays their messages to the screen.*/
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}

