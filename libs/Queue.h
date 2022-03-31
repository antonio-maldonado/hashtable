#ifndef _QUEUE_HPP
#define _QUEUE_HPP
#include"Node.h"
struct Queue{
	Node* head,*tail;
	Queue(){head=NULL,tail=NULL;}
};

bool empty(Queue*);
bool extract(Queue*,TIPO*);
bool insert(Queue*,TIPO);

#endif
