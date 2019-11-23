 /*! \AUTHOR: CHRISTIANA TEMIOLA 
    \STUDENT ID: C00220551
    \TITLE: LAB 6:PRODUCER-CONSUMER
            \Filename: SafeBuffer.cpp
    \DATE: 21ST NOVEMBER 2019


 * Filename: SafeBuffer.cpp
 * Description: This is the implementation file for the SafeBuffer class.
 */

/*! \brief  A thread safe buffer
*           Utilises semaphores to create a thread safe buffer where
*           multiple threads can put and take from the buffer
* 
*/

#include "SafeBuffer.h"

/*don't need to include vector etc again because it is already included in safebuffer.h */

SafeBuffer::SafeBuffer(){
  theMutex = std::make_shared<Semaphore>(1);
  //theSemaphore=std::make_shared<Semaphore>(0);
}

int SafeBuffer::push(Event e) {
  theMutex->Wait();
  theData.push_back(e);
  int size = theData.size();
  //theSemaphore->Signal();
  theMutex->Signal();
  return size;
}

Event SafeBuffer::pop() {
  //theSemaphore->Wait();
  theMutex->Wait();
  Event e = theData.back();
  theData.pop_back();
  theMutex->Signal();
  return e;
}
