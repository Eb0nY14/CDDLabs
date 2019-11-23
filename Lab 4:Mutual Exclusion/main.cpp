/*! \AUTHOR: CHRISTIANA TEMIOLA
    \STUDENT NUMBER: C00220551
    \DATE: 11TH NOVEMBER 2019
    \TITLE: LAB 4:MUTUAL EXCLUSION
    \main.cpp
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 100;
int sharedVariable=0;

/*! \fn updateTask
    \brief An Implementation of Mutual Exclusion using Semaphores

 * Uses Semaphores to create a program that implements mutual exclusion on a sha  * red variable in order to prevent concurrent access.
 *
 * @return updates the shared variable's value
 * @param firstSem Semaphore object
 * @param numUpdates the number of times the sharedVariable is to the updated.
*/

/*! \main.cpp Lab 4 
 *
 * \section Mutual Exclusion
 *
 * This lab demonstrates mutual exclusion by implementing it on a shared variable * such that concurrent access is not permitted.
  */


void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates){
  if(sharedVariable != 0)
    firstSem->Wait(); 
  for(int i=0; i < numUpdates; i++){
    //UPDATE SHARED VARIABLE HERE!
    sharedVariable++;
    std::cout << "the thread id is: " << std::this_thread::get_id() << "the variable is: " << sharedVariable << std::endl;
  }
    firstSem->Signal();

}//end of updateTask function


int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore( new Semaphore);
 
  /**< Launch the threads  */
    int i=0;
    for(std::thread& t: vt){
      t=std::thread(updateTask, aSemaphore, 1000);
    }
    std::cout << "Launched from the main\n";
      
  /**< Join the threads with the main thread */
    for (auto& v :vt){
       v.join();
    }
    
    std::cout << sharedVariable << std::endl;
    return 0;
}//end of main function
