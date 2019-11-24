#ifndef SEMAPHORE_H
#define SEMAPHORE_H 
#include <mutex>
#include <condition_variable>
#include <chrono>



/*! \AUTHOR: CHRISTIANA TEMIOLA
    \STUDENT NUMBER: C00220551
    \DATE: 15TH OCTOBER 2019
    \TITLE: LAB 2:SEMAPHORES
    \Semaphore.h
*/



/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore.
   This file defines the Semaphore class i.e defines all the variables and classes used by other files such as cpp files etc.

*/

/*! A Semaphore class */
class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    Semaphore(unsigned int uiCount=0)
          : m_uiCount(uiCount) { };
    void Wait();
    template< typename R,typename P >
    bool Wait(const std::chrono::duration<R,P>& crRelTime); /*!< uses chrono library to improve time over precision since time varies across systems */
    void Signal();

};

#endif
