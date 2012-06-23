#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

using namespace std;

struct Nodo{
     struct Nodo *hijo_izq;
     struct Nodo *hijo_der;
     char dato;
     int altura;
};

//typedef struct Nodo NODO;
//typedef NODO *ARBOL;

typedef struct Nodo *ARBOL;

ARBOL RAIZ_ARBOL = NULL;

void inOrden(ARBOL*);
void postOrden(ARBOL*);
void preOrden(ARBOL*);
void agregarNodo(char, ARBOL*);
int calcularAltura(ARBOL*);
void balanceo(ARBOL*, ARBOL*);
void rotacionSimpleDerecha(ARBOL*, ARBOL*);
void rotacionSimpleIzquierda(ARBOL*, ARBOL*);

int main(){
     char valor;
     while(cin >> valor){
          printf("%s","entro\n");
          if(!RAIZ_ARBOL){
               RAIZ_ARBOL = (Nodo *)malloc(sizeof(Nodo));
//               RAIZ_ARBOL = (NODO *)malloc(sizeof(NODO));
               printf("%s","asignando padre\n");
               RAIZ_ARBOL->dato = valor;
               RAIZ_ARBOL->hijo_izq = NULL;
               RAIZ_ARBOL->hijo_der = NULL;
               RAIZ_ARBOL->altura = 0;
          }else{
               printf("%s","agregando nodo hijo\n");
               agregarNodo(valor, &RAIZ_ARBOL);
//               preOrden(&RAIZ_ARBOL);
               inOrden(&RAIZ_ARBOL);
//               postOrden(&RAIZ_ARBOL);
               cout << endl;
          }
     }
     return 0;
}


void agregarNodo(char valor, ARBOL *padre){
     if(!(*padre)){
          (*padre) = (Nodo *)malloc(sizeof(Nodo));
//          (*padre) = (NODO *)malloc(sizeof(NODO));
          if((*padre)){
               printf("%s","creando Nodo\n");
               (*padre)->dato = valor;
               (*padre)->hijo_izq = NULL;
               (*padre)->hijo_der = NULL;
               balanceo(&RAIZ_ARBOL, NULL);
          }
     }else if((*padre)->dato < valor){//derecha
          agregarNodo(valor, &((*padre)->hijo_der));
          printf("%s","Nodo derecho agregado\n");
     }else if((*padre)->dato > valor){//izquierda
          agregarNodo(valor, &((*padre)->hijo_izq));
          printf("%s","Nodo izquierdo agregado\n");
     }else{//ya existe el dato
          printf("%s","ya existe el valor agregado\n");
     }
}

void balanceo(ARBOL *raiz, ARBOL *padre){
     int altura = calcularAltura(&(*raiz));
     int alturaizq;
     int alturader;
     bool flag = true;
     if(altura < 2 && altura > -2){
          return;
     }
     //si el hijo izquierdo de la raiz es diferente de null calcula la altura de lo contrario retorna 0
     alturaizq = ((*raiz)->hijo_izq) ? calcularAltura(&(*raiz)->hijo_izq) : 0;
     //si el hijo derecho de la raiz es diferente de null calcula la altura de lo contrario retorna 0
     alturader = ((*raiz)->hijo_der) ? calcularAltura(&(*raiz)->hijo_der) : 0;
     
     if(alturaizq > 1 || alturaizq < -1){
          balanceo(&(*raiz)->hijo_izq, &(*raiz));
          flag = false;
     }
     
     if(alturader > 1 || alturader < -1){
          balanceo(&(*raiz)->hijo_der, &(*raiz));
          flag = false;
     }
     
     if(flag){
          if(altura < 0){
               if(alturader > 0){
                    //doble rotacion izquierda
               }else{
                    //rotacion simple izquierda
                    rotacionSimpleIzquierda(&(*raiz), &(*padre));
               }
          }else if(alturaizq < 0){
               //doble rotacion derecha
          }else{
               //rotacion simple derecha
               rotacionSimpleDerecha(&(*raiz), &(*padre));
          }
     }
}

void rotacionSimpleIzquierda(ARBOL *raiz, ARBOL *padre){
     
}

void rotacionSimpleDerecha(ARBOL *raiz, ARBOL *padre){
     if((*raiz)){
          if(!((*raiz)->hijo_izq->hijo_der)){
               
          }
     }
}

int calcularAltura(ARBOL *padre){
     ARBOL *aux = padre;
     int alturaizq = 0;
     int alturader = 0;
     if((*aux)->hijo_izq == NULL){
          alturaizq = 0;
     }else{
          alturaizq = 1 + abs(calcularAltura(&(*aux)->hijo_izq));
     }
     
     if((*aux)->hijo_der == NULL){
          alturader = 0;
     }else{
          alturader = 1 + abs(calcularAltura(&(*aux)->hijo_der));
     }
     return (alturaizq + alturader);
}

void inOrden(ARBOL *padre){
     if(*padre){
          inOrden(&(*padre)->hijo_izq);
          printf("%c",(*padre)->dato);
          inOrden(&(*padre)->hijo_der);
     }
}

void preOrden(ARBOL *padre){
     if(*padre){
          printf("%c",(*padre)->dato);
          preOrden(&(*padre)->hijo_izq);
          preOrden(&(*padre)->hijo_der);
     }
}

void postOrden(ARBOL *padre){
     if(*padre){
          preOrden(&(*padre)->hijo_izq);
          preOrden(&(*padre)->hijo_der);
          printf("%c",(*padre)->dato);
     }
}
