/****************************************************************************************
*  ListTest.c
*  My test for List ADT
*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"List.h"

int main(int argc, char* argv[]){

   // init a List
   List A = newList();
   //List B = newList();

   // prepend to the list
   prepend(A, 3);
   //printList(stdout,A);
   prepend(A,7);
   //printList(stdout,A);
   prepend(A,321);
   prepend(A,2);
   prepend(A,9);
   printList(stdout,A);
   printf("\n");

   moveFront(A);
   set(A,25);
   printf("%d\n",index(A));
   printList(stdout,A);
   printf("\n");

   moveNext(A);
   moveNext(A);
   set(A,322);
   printf("%d\n",index(A));
   printList(stdout,A);
   printf("\n");

   moveBack(A);
   set(A,3777);
   printf("%d\n",index(A));
   printList(stdout,A);
   printf("\n");

   freeList(&A);
}
