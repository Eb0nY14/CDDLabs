 /*! \AUTHOR: CHRISTIANA TEMIOLA 
    \STUDENT ID: C00220551
    \TITLE: LAB 5:REUSABLE BARRIER
            \Filename: Barrier.cpp
    \DATE: 21ST NOVEMBER 2019


 * Filename: Barrier.cpp
 * Description: This is the implementation file for the Barrier class.
  
 * This program is free software: you can redistribute it and/or modify
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

#include <iostream>
#include "Barrier.h"

Barrier::Barrier(int threadNum) {

    numThreads = threadNum;
}

void Barrier::wait() {

    

    mutex->Wait();

        count = count + 1;
        
        if(count == numThreads) {
            turnstile2->Wait();
            turnstile->Signal();
        }
    mutex->Signal();

    
    turnstile->Wait();
    turnstile->Signal();

    mutex->Wait();

        count = count-1;

        if(count == 0) {
            turnstile->Wait();
            turnstile2->Signal();
        }

    mutex->Signal();

    turnstile2->Wait();
    turnstile2->Signal();

}
 
// Barrier.cpp ends here





