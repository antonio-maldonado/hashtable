//******************************************************************************
/**
  Node.cpp
  Funciones del Node

  \author Ricardo Legarda Sáenz.
  \date 2015-09-06 22:25:58  
*/
//******************************************************************************

// directivas del preprocesador
#include "Node.h"
using namespace std;


// *************************************************************
//    Funciones nodos
// *************************************************************
Node* CrearNode( void )
{
  Node* ptr = new Node;
  return ptr;
}
void EliminaNode( Node* ptr )
{    
  delete ptr;
}

