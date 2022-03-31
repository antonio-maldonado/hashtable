#ifndef _STACK_HPP
#define _STACK_HPP
//typedef int TIPO;
// define elementos del stack
#include"Node.h"

struct Stack
{
  Node* top;
  Stack(){top=NULL;}
};
bool empty (Stack* );         // true si esta vacio
bool pop (Stack*, TIPO* );    // true si hay problemas 
bool push (Stack*, TIPO );     // true si hay problemas 

#endif 

