//===============================================================================
// BigIntegerTest.c
// Test file for BigInteger
// Tristan Clark
//===============================================================================

#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#include"BigInteger.h"

int main(int argc, char* argv[]){
   
   // initialize a BigInteger
   BigInteger A = newBigInteger();
   BigInteger B = newBigInteger();
   //printf("%d\n",sign(A));
   //printf("%d\n",sign(B)); 
   //printf("%d\n",compare(A,B));
   
   //long something = charToLong("572634",-1,5);
   //printf("%ld\n",something); 
   //prepend( A->number , something);
   //long whatnow = charToLong("572634",-1,1);
   //printf("%ld\n",whatnow);
   //prepend(A->number ,whatnow);
   //printList(stdout, A->number);
   
   A = stringToBigInteger("7402779357");
   printBigInteger(stdout,A);
   printf("\n");
   //printf("%d\n",sign(A));
   //B = copy(A);
   //printBigInteger(stdout,B);
   //printf("\n");
   //printf("%d\n",sign(B));
   B = stringToBigInteger("41085449");
   printBigInteger(stdout,B);
   printf("\n");

   BigInteger C = newBigInteger();
   add(C,A,B);
   printf("hello\n");
   printBigInteger(stdout,C);
   printf("\n");
   printf("but here\n");



}
