/*! \AUTHOR: CHRISTIANA TEMIOLA 
    \STUDENT ID: C00220551
    \TITLE: LAB 5:REUSABLE BARRIER
            \Filename: Barrier.h
    \DATE: 21ST NOVEMBER 2019

 
 * Filename: Barrier.h
 * Description: This is the header file for the Barrier class.
 

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

#pragma once  /* This line of code prevents errors by compiling only once no mat                 ter how many times it is included.*/
#include "Semaphore.h"

class Barrier{
  int numThreads;
  int count = 0;

  Semaphore *turnstile = new Semaphore(0);
  Semaphore *turnstile2 = new Semaphore(1);
  Semaphore *mutex = new Semaphore(1);

 public:
  Barrier(int threadNum);
  //virtual ~Barrier();
  void wait();  
};


/* Barrier.h ends here */
