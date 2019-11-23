/*! \AUTHOR: CHRISTIANA TEMIOLA
    \STUDENT ID: C00220551
    \TITLE: LAB 5:REUSABLE BARRIER
    \DATE: 21ST NOVEMBER 2019
*/

#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>

/*! \ LAB 5:Reusable Barrier Class 
 * Filename: main.cpp

 * Description: This is the file that contains main function. It creates at least two threads that demonstrates a reusable barrier in action.
*/

static const int num_threads = 100;
int sharedVariable=0;

/*! \fn barrierTask
    \brief An example of using a reusable barrier
*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Do first bit of task
    std::cout << "A"<< i;
    //Barrier
    theBarrier->wait();
    //Do second half of task
    std::cout<< "B" << i;

  }
  
}

int main(void){
  std::cout << "Starting Main Thread..." << std::endl;
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Barrier> aBarrier( new Barrier(num_threads));
  std::cout << "Barrier & Threads created..." << std::endl;
  /**< Launch the threads  */

  for(std::thread& t: vt){
    t=std::thread(barrierTask,aBarrier,10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}

