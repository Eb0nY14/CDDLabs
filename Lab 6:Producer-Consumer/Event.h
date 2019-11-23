/*! \AUTHOR: CHRISTIANA TEMIOLA 
    \STUDENT ID: C00220551
    \TITLE: LAB 6:PRODUCER-CONSUMER
            \Filename: Event.h
    \DATE: 21ST NOVEMBER 2019

 
 * Filename: Event.h
 * Description: This is the header file for the Event class.
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

#pragma once  /**< This line of code prevents errors by compiling only once no m                   atter how many times it is included. */

class Event{
  /*! \brief Event class
   *         The Event class has two functions, the constructor and consume
   *         The constructor produces a random letter from a-z
   *         Consume prints out the uppercase version of the produced letter to    *         demonstrate that the 'Event' is now consumed.
   *
   */
  
 private:
  char  the_char; /**< A random letter between a-z */
  
 public:
  Event();
  bool consume(); /**< prints out the uppercase version of the 'the_char' */  
};

/* Event.h ends here */
