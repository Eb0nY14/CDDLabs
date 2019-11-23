/*! \AUTHOR: CHRISTIANA TEMIOLA
    \STUDENT NUMBER: C00220551
    \DATE: 11TH NOVEMBER 2019

    \TITLE: LAB 6:PRODUCER-CONSUMER
            Event.cpp
*/

#include "Event.h"
#include <iostream>
#include <stdlib.h>

//iostream doesnt need .h because it is a cpp library
//event and stdlib does because they are c libs

//producing..
Event::Event(){

    the_char = 'a'+rand()%26;
    std::cout << the_char;
}
  

bool Event::consume(){
  char betterTheChar = the_char -32;
  std::cout<<betterTheChar;
}

