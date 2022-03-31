#include<iostream>
#include<cstring>
#include"Queue.h"

using namespace std;

bool empty(Queue*Q){
	return ((Q->head==NULL)&&(Q->tail==NULL));
}

bool extract(Queue* Q,TIPO* valor){

if(empty(Q)==true)
return true;
	memcpy(valor,&(Q->head->data),sizeof(TIPO));

	Node* q=Q->head;
	Q->head=Q->head->next;
	if(Q->head==NULL)
		Q->tail=NULL;
	EliminaNode(q);
  return false;
}

bool insert( Queue * Q, TIPO valor ){
	Node* q=CrearNode();
	memcpy(&(q->data),&valor,sizeof(TIPO));
	if(empty(Q)==true){
		Q->head=q;
		Q->tail=q;
	}else{
		Q->tail->next=q;
		Q->tail=q;
	}
 
  
  return false;
}


