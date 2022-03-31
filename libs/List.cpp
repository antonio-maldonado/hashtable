#include<iostream>
#include<cstring>
#include"List.h"
using namespace std;


bool insertNodoLista(Node* p,TIPO valor){
if(p==NULL)
{
cout<<"error en inserNodoLista..."<<endl;
return true;
}
Node* q=CrearNode();
memcpy(&(q->data),&valor,sizeof(TIPO));
q->prev=p;
q->next=p->next;
if(p->next!=NULL)
	p->next->prev=q;
p->next=q;
return false;
}


bool eliminaNodoLista(Node* p,TIPO* valor)
{
if(p==NULL)
{
cout<<"error en eliminaNodoLista..."<<endl;
return true;
}

memcpy(valor,&(p->next->data),sizeof(TIPO));
Node* q=p->next;
p->next=q->next;
if(q->next!=NULL)
	q->next->prev=p;
EliminaNode(q);
return false;
}

