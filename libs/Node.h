//******************************************************************************
/*
  Node.h
  Encabezados del Node

  \author Ricardo Legarda Sáenz.
  \date 2015-09-06 22:25:34 
*/
//******************************************************************************
#ifndef _NODE_HPP
#define _NODE_HPP     // include just once

// incluye los encabezados de la funciones a utilizar
#include <cstdlib>    // NULL

// definicion de estructuras de datos
//typedef int TIPO;
typedef struct 
{
int hashkey;
char nombre[100];
char matricula[100];
}TIPO;

// define estructura de nodos y funciones de creacion/eliminacion
struct Node 
{
  TIPO data;
  Node *next, *prev;
  Node ()  {  next = NULL;    prev = NULL;  } 
};
Node* CrearNode(void);
void EliminaNode(Node*);

#endif




