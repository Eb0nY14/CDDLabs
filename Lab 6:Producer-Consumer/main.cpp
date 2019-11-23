/*! \AUTHOR: CHRISTIANA TEMIOLA
    \STUDENT NUMBER: C00220551
    \DATE: 21ST NOVEMBER 2019

    \TITLE: LAB 6:PRODUCER-CONSUMER
            main.cpp
*/


#include "Event.h"
#include "SafeBuffer.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 5; //use small value for num_threads for testing                                     purposes                  // 100;
const int size = 5;                   // 20;

/*! @brief Example of the producer-consumer pattern.
 *
 */

/*! \main.cpp Lab 6
 *
 * \section Producer-Consumer Pattern
 *
 * This lab demonstrates the producer-consumer pattern.
 * The first function called producer creates events and adds them to the buffer.
 * The second function called consumer consumes the events created by the producer. *
 */ 


/*! \fn producer
    \brief Creates events and adds them to buffer
*/

void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Produce(create) the event;
    Event e;
    // Add the event created to buffer;
    theBuffer->push(e);
  }
}//producer

/*! \fn consumer
    \brief Takes events from buffer and consumes them
*/

void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Consume event and deduct from buffer
    Event e= theBuffer->pop();
    e.consume();
  }
}//consumer

int main(void){

  /*! \brief  Main function which demonstrates a thread safe buffer implementation
    * 
    * */

  std::vector<std::thread> producers(num_threads);
  std::vector<std::thread> consumers(num_threads);
  
  std::shared_ptr<SafeBuffer> aBuffer( new SafeBuffer());
  
  /**< Launch the Producer threads  */
  for(std::thread& p: producers){
    p=std::thread(producer,aBuffer,5);
  }

  for(std::thread& c: consumers){
    c=std::thread(consumer,aBuffer,5);
  }

  /**< Join the threads with the main thread */
  for (auto& p :producers){
      p.join();
  }
  
  for (auto& c :consumers){
      c.join();
  }
  
  std::cout <<  std::endl;
  return 0;
}
