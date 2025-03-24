#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   if (L == NULL) return NULL;
   for(int i = 1; i <= 10; i++){
      int* elemento = (int*)malloc(sizeof(int));
      *elemento = i;
      pushBack(L, elemento);
      printf("%d\n", *elemento);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int cont = 0;
   int *posicion = (int*)first(L);
   while(posicion != NULL){
      cont +=  *posicion;
      posicion = (int*)next(L);
   }
   return cont;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int *posicion = (int*)first(L);
   while(posicion != NULL){
      if(*(int*)posicion == elem){
         popCurrent(L);
      }
      posicion = (int*)next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* pilaAux = create_stack();
   void* dato;
   while((dato = top(P1)) != NULL){
      push(pilaAux, dato);
      pop(P1);
   }
   while((dato = top(pilaAux)) != NULL){
      push(P1, dato);
      push(P2, dato);
      pop(pilaAux);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack* PilaVuelta = create_stack();
   Stack* PilaAux = create_stack();
   int largo = strlen(cadena);
   if(largo % 2 != 0){
      return 0;
   }
   for(int i = 0; i < largo; i++){
      char *elemento = (char*)malloc(sizeof(char));
      *elemento = cadena[i];
      push(PilaVuelta, elemento);
      push(PilaAux, elemento);
      }
   
   Stack* PilaOG = create_stack();
   while(top(PilaAux) != NULL){
      push(PilaOG, top(PilaAux));
      pop(PilaAux);
   }
   while(top(PilaOG) != NULL){
      if(*(char*)top(PilaOG) == '(' ){
         if((*(char*)top(PilaVuelta)) != '}' && (*(char*)top(PilaVuelta)) != ']'){
            pop(PilaOG);
            pop(PilaVuelta);
         }
         else{
            return 0;
         }
      }
      else if(*(char*)top(PilaOG) == '['){
         if((*(char*)top(PilaVuelta)) != '}' && (*(char*)top(PilaVuelta)) != ')'){
            pop(PilaOG);
            pop(PilaVuelta);
         }
         else{
            return 0;
         }
      }
      else if(*(char*)top(PilaOG) == '{'){
         if((*(char*)top(PilaVuelta)) != ']' && (*(char*)top(PilaVuelta)) != ')'){
            pop(PilaOG);
            pop(PilaVuelta);
         }
         else{
            return 0;
         }
      }   
      else{
         pop(PilaOG);
         pop(PilaVuelta);
      }
   }

   return 1;
}

