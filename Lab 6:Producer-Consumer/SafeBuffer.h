/*! \AUTHOR: CHRISTIANA TEMIOLA 
    \STUDENT ID: C00220551
    \TITLE: LAB 6:PRODUCER-CONSUMER
            \Filename: SafeBuffer.h
    \DATE: 21ST NOVEMBER 2019

 
 * Filename:  SafeBuffer.h
 * Description: This is the header file for the SafeBuffer class.
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */

#pragma once    /* This line of code prevents errors by compiling only once no m                   atter how many times it is included.*/
#include "Event.h"
#include <vector>
#include "Semaphore.h"

class SafeBuffer {

private:
  std::vector<Event> theData; /**< An array of event objects */
  std::shared_ptr<Semaphore> theMutex; /**< A shared mutex lock object */
  // std::shared_ptr<Semaphore> theSemaphore;

public:
  SafeBuffer();
  int push(Event); /**< Push takes an Event object and attempts to push it to the buffer */
  Event pop();  /**< Removes the oldest object from the buffer */
  
};
/* SafeBuffer.h ends here */
