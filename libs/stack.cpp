#include<iostream>
#include"stack.h"
#include<cstring>
bool empty(Stack *S )
{return (S->top == NULL);}

bool pop( Stack *S, TIPO* valor )
{
  if(empty(S) == true)
    return true;
  memcpy(valor,&(S->top->data),sizeof(TIPO));
	Node* q=S->top;
	S->top=S->top->next;
	EliminaNode(q);
	return false;
}

bool push( Stack *S, TIPO valor )
{
	Node* q=CrearNode();
	memcpy(&(q->data),&valor,sizeof(TIPO));
 	q->next=S->top;
	S->top=q;
  return false;
}


