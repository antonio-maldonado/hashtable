// define encabezados de funciones a utilizar
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include "libs/Node.h"
using namespace std;

      static const unsigned char Rand8[256] = {
      // 0-255 shuffled in any (random) order suffices
       98,  6, 85,150, 36, 23,112,164,135,207,169,  5, 26, 64,165,219, //  1
       61, 20, 68, 89,130, 63, 52,102, 24,229,132,245, 80,216,195,115, //  2
       90,168,156,203,177,120,  2,190,188,  7,100,185,174,243,162, 10, //  3
      237, 18,253,225,  8,208,172,244,255,126,101, 79,145,235,228,121, //  4
      123,251, 67,250,161,  0,107, 97,241,111,181, 82,249, 33, 69, 55, //  5
       59,153, 29,  9,213,167, 84, 93, 30, 46, 94, 75,151,114, 73,222, //  6
      197, 96,210, 45, 16,227,248,202, 51,152,252,125, 81,206,215,186, //  7
       39,158,178,187,131,136,  1, 49, 50, 17,141, 91, 47,129, 60, 99, //  8
      154, 35, 86,171,105, 34, 38,200,147, 58, 77,118,173,246, 76,254, //  9
      133,232,196,144,198,124, 53,  4,108, 74,223,234,134,230,157,139, // 10
      189,205,199,128,176, 19,211,236,127,192,231, 70,233, 88,146, 44, // 11
      183,201, 22, 83, 13,214,116,109,159, 32, 95,226,140,220, 57, 12, // 12
      221, 31,209,182,143, 92,149,184,148, 62,113, 65, 37, 27,106,166, // 13
        3, 14,204, 72, 21, 41, 56, 66, 28,193, 40,217, 25, 54,179,117, // 14
      238, 87,240,155,180,170,242,212,191,163, 78,218,137,194,175,110, // 15
       43,119,224, 71,122,142, 42,160,104, 48,247,103, 15, 11,138,239  // 16
      };


// *************************************************************
//
//    Funcion principal
//
// *************************************************************
#define DIVISION
#if defined STRING_EXCLUSIVEOR
char key[100];
const int HashTableSize =256;
typedef unsigned char HashIndexType;
	HashIndexType Hash(char *str){
	HashIndexType h=0;
	while(*str)
		h=Rand8[h^*str++];
	return h;
}
#elif defined STRING_EXCLUSIVEOR_EXTENDED
char key[100];
const int HashTableSize =400;
typedef unsigned short int HashIndexType;


HashIndexType Hash(char *str) {
    HashIndexType h;
    unsigned char h1, h2;

    if (*str == 0) return 0;
    h1 = *str; h2 = *str + 1;
    str++;
    while (*str) {
        h1 = Rand8[h1 ^ *str];
        h2 = Rand8[h2 ^ *str];
        str++;
    }
  
    /* h is in range 0..65535 */
    h = ((HashIndexType)h1 << 8)|(HashIndexType)h2;
    /* use division method to scale */
    return h % HashTableSize;
}
#elif defined DIVISION
int key;
const int HashTableSize=41;
typedef int HashIndexType;
HashIndexType Hash(int key){
return key%HashTableSize;}
#elif defined MULTIPLICATION
int key,n=6;
const int HashTableSize=(2<<(n-1));
typedef unsigned char HashIndexType;//8 bits
//typedef unsigned short int HashIndexType;//16-bits
//typedef unsigned long int HashIndexType;//32 bits
HashIndexType Hash(int key){
	static const HashIndexType k=40503;
	static const int S=16-n;
	return (HashIndexType)(k*key)>>S;
}
#elif defined STRING_ADDITION
char key[100];
const int HashTableSize=256;
typedef unsigned char HashIndexType;
HashIndexType Hash(char *str){
	HashIndexType h=0;
	while(*str)
		h+=*str++;
	return h;
}
#endif
int main ( int argc, char **argv ) 
{
  // define variables de trabajo
  char buffer[100];
	Node* Diccionario[HashTableSize];
  for(int k=0;k<HashTableSize;k++){
		Diccionario[k]=NULL;
		}

  // obtiene nombre del archivo a leer
  if ( argc > 1 )    // valores de la terminal ?
    {
      // si, lee nombre de archivo
      buffer[0] = '\0';    
      strcat( buffer, argv[1] );
    }
  else  
    {
      // no, indica al usuario como usarse
      cout << "Escriba nombre del archivo a leer : " << endl;
      cin >> buffer;
    }

  // abre archivo
  ifstream fileCode( buffer );
  if ( !fileCode.is_open() )
    {
      cout << "No se pudo abrir el archivo..." << endl;
      exit( EXIT_FAILURE );
    }

  // lee datos de archivo
  cout << endl << "ciclo de lectura...";
 
	
	int count=0;
  while ( fileCode.getline(buffer,100) && (strlen(buffer)>0) && (count< HashTableSize) )
    {
      // lee datos del archivo y obtiene hashkey
		TIPO tmp;
		  sscanf( buffer, "%s", tmp.matricula);
      char *ptr;    
    	strtod(buffer,&ptr);
    
      while ( *ptr == ' ' )
        ptr++;
      strcpy( tmp.nombre, ptr );
		#if defined DIVISION
			key=atoi(tmp.matricula);
		#elif defined MULTIPLICATION
			key=atoi(tmp.matricula);
		#elif defined STRING_ADDITION
			strcpy(key,tmp.matricula);
		#elif defined STRING_EXCLUSIVEOR
			strcpy(key,tmp.matricula);
		#elif defined STRING_EXCLUSIVEOR_EXTENDED
			strcpy(key,tmp.matricula);
		#endif
		HashIndexType hashkey=Hash(key);
//		cout<<HashTableSize<<"   "<<hashkey<<endl;
		tmp.hashkey=hashkey;
		if(Diccionario[hashkey]==NULL){
			Diccionario[hashkey]=CrearNode();
			memcpy(&(Diccionario[hashkey]->data),&tmp,sizeof(TIPO));
		}else{
			Node *q=Diccionario[hashkey];
			while(q->next!=NULL)
				q=q->next;
			q->next=CrearNode();
			memcpy(&(q->next->data),&tmp,sizeof(TIPO));
		}

		count++;
    }
  cout << "listo !!!  " << endl;

	cout<<"Matriculas que estan en el diccionario: "<<endl;
	for(int k=0;k<HashTableSize;k++)
		if(Diccionario[k]!=NULL){
			Node* q=Diccionario[k];
			while(q!=NULL){
				cout<<q->data.hashkey<<" "<<q->data.matricula<<" "<<q->data.nombre<<endl;
				q=q->next;
			}
		}
					
	
	cout<<endl<<"Cual matricula buscas: ";
	//cin.getline(key,100);	
	cin>>key;
	HashIndexType hashkey=Hash(key);
	if(Diccionario[hashkey]!=NULL){
		int matricula=key;//atoi(key);
		Node* q=Diccionario[hashkey];
		while(q!=NULL){
		int valor=atoi(q->data.matricula);
		if(matricula==valor){
			cout<<endl<<"Matricula encontrada: "<<endl<<q->data.matricula<<" "<<q->data.nombre<<endl<<endl;		
		break;
		}else
			q=q->next;
		
		}
	if(q==NULL)
			cout<<endl<<"No existe la matricula..."<<endl;
	}else 
		cout<<endl<<"No existe la matricula"<<endl;
	for(int k=0;k<HashTableSize;k++)
		if(Diccionario[k]!=NULL){
			while(Diccionario[k]!=NULL){
				Node* q=Diccionario[k];
				Diccionario[k]=Diccionario[k]->next;
				EliminaNode(q);
			}
		}
	for(int k=0;k<HashTableSize;k++)
		if(Diccionario[k]!=NULL)
			cout<<endl<<"error "<<k;
	return EXIT_SUCCESS;
}  // end main

