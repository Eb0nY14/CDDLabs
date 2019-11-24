/*! \AUTHOR: CHRISTIANA TEMIOLA
    \STUDENT NUMBER: C00220551
    \DATE: 15TH OCTOBER 2019
    \TITLE: LAB 2:SEMAPHORES
    \Semaphore.cpp
*/


#include "Semaphore.h"

/*! \class Semaphore
    \brief A Semaphore Implementation

This is the implementation file for the Semaphore class.
*/

/*! A Semaphore Wait() function that takes no argument and returns void value */
 
void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}

template< typename R,typename P >

/*! Another Semaphore Wait function that takes 2 arguments and returns a boolean value */
bool Semaphore::Wait(const std::chrono::duration<R,P>& crRelTime)
{
      std::unique_lock< std::mutex > lock(m_mutex);
      if (!m_condition.wait_for(lock,crRelTime,[&]()->bool{ return m_uiCount>0; })){
	  return false;
      }
      --m_uiCount;
      return true;
}

/*! A Semaphore Signal function that takes no argument, performs the Signal(), increments(i.e updates)  the shared variable m_uiCount and returns void value */
void Semaphore::Signal()
{
  std::unique_lock< std::mutex > lock(m_mutex); /*!< the shared variable m_uiCount is locked by mutex                                                       to prevent concurrent access while updating it.                                                     */
      ++m_uiCount;
      m_condition.notify_one();
}
