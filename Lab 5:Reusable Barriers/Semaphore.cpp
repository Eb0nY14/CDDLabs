/*! AUTHOR: CHRISTIANA TEMIOLA
    STUDENT ID: C00220551
    TITLE: LAB 5:REUSABLE BARRIER
    DATE: 21ST NOVEMBER 2019
*/

#include "Semaphore.h"
#include <iostream>

/*! \class Semaphore
    \brief A Semaphore Implementation

    \LAB 5:Reusable Barrier Class
       \Filename: Semaphore.cpp

   Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}

template< typename R,typename P >
bool Semaphore::Wait(const std::chrono::duration<R,P>& crRelTime)
{
      std::unique_lock< std::mutex > lock(m_mutex);
      if (!m_condition.wait_for(lock,crRelTime,[&]()->bool{ return m_uiCount>0; })){
	  return false;
      }
      --m_uiCount;
      return true;
}

void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}
