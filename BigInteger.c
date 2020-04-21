//=============================================================================
// BigInteger.c
// This is my BigInteger ADT.
// Tristan Clark
//=============================================================================

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "List.h"
#include "BigInteger.h"

#define POWER 4
#define BASE 100

// private ListObj type
typedef struct BigIntegerObj{
   int sign;
   List number; 
} BigIntegerObj;

// Constructors-Destructors ---------------------------------------------------

// newBigInteger()
// Returns a reference to a new BigInteger object in the zero state.
BigInteger newBigInteger() {
   BigInteger B;
   B = malloc(sizeof(BigIntegerObj));
   B->sign = 0;
   B->number = newList();
   return(B); 
}

// freeBigInteger()
// Frees heap mememory associated with *pN, sets *pN to NULL.
// void freeBigInteger(BigInteger* pN);

// Access functions -----------------------------------------------------------

// sign()
// Returns -1 if N is negative, 1 is N is positive, and 0 is in the zero state.
int sign(BigInteger N) {
   return N->sign;
}

// there seems to be an error here when both lists are empty
// write print and then test it
// compare()
// Returns -1 if A<B, 1 is A>B, and 0 if A=B
int compare(BigInteger A, BigInteger B) {
   if(A->sign == B->sign) {
      if(length(A->number) == length(B->number)) {
         moveFront(A->number);
         moveFront(B->number);
         if(A->sign == -1) {
            while( index(A->number) >= 0 ) {
               // if neg and A < B return 1;
               if(get(A->number) < get(B->number)) {return 1;}
               // else if neg and A > B return -1;
               else if(get(A->number) > get(B->number)) {return -1;}
               // otherwise continue the loop;
               else { moveNext(A->number); moveNext(B->number);}
            }
         } else { // if sign is 1, if its 0 then itll just skip the loop
            while( index(A->number) >= 0) {
               //if pos and A<B return -1
               if(get(A->number) < get(B->number)) {return -1;}
               //else pos and A>B return 1
               else if(get(A->number) > get(B->number)) {return 1;}
               //else continue
               else { moveNext(A->number); moveNext(B->number);}
            }
         }
         return 0; // if length of A > B and pos: return 1
      }else if(length(A->number) > length(B->number) && A->sign == 1) { return 1;}
      //else if length A < B && neg return 1
      else if(length(A->number) < length(B->number) && A->sign== -1) { return 1;}  
      //if length A < length B && pos return -1
      else if(length(A->number) < length(B->number) && A->sign== 1) { return -1;}
      //else if return length A > B && neg return -1
      else { return -1;}
   } else if( A->sign < B->sign) {
      return -1;
   // otherwise A sign > B sign
   } else { return 1; }
}

// equals()
// Return true (1) if A and B are equal, false (0) otherwise.
int equals(BigInteger A, BigInteger B) {
   if(A->sign == B->sign && ListEquals(A->number, B->number)) return 1;
   return 0;
}

// Manipulation procedures ----------------------------------------------------

// makeZero()
// Re-sets N to the zero state.
void makeZero(BigInteger N) {
  clear(N->number);
  N->sign = 0; 
}

// negate()
// Reverses the sign of N: positive <--> negative. Does nothing if N is in
// the zero state.
void negate(BigInteger N) {
   if(N->sign == 1) N->sign = -1;
   if(N->sign == -1) N->sign = 1;
}

// Helper functions -----------------------------------------------------------

// charToLong()
// Returns a long converted from a char charzcter array
// x is how low the iterator can go, if - or + then 0 or -1 if not.
// i is the starting point of the long
// y is the ending point, it keeps track of where the 0's start
//long charToLong(char* s, int x, int i,int y) {
long charToLong(char* s, int x, int i) {
   long part = 0;
   char digit;
   int j,idig;
   int k = 0;

   for(j = i; j > i-POWER; --j, ++k) {
      printf("i: %d\n", i);
      printf("j: %d\n", j);
      //printf("y: %d\n", y);
      printf("k: %d\n", k);

      if(j == x) break;
      digit = j[s];
      //printf("digit: %c\n", digit);
      idig = digit - '0';
      //printf("idig: %d\n", idig);
      idig = idig * myPow(k);
      part += idig;
   }
   printf("part: %ld\n", part);
   return part;
}

// myPow
// Returns 10 to the power of k.
int myPow(int k){
   int pow = 1;
   while(k > 0) {
      pow = pow * 10;
      k--;
   }
   return pow;
}

// BigInteger Arithmetic operations -------------------------------------------

// stringToBigInteger()
// Returns a reference to a new BigInteger object representing the decimal
// integer represented in base 10 by the string s.
// Pre: s is a non-empty string containing only base ten digits 
// {0,1,2,3,4,5,6,7,8,9} and an optional sign {+,-} prefix.
// x is how low the iterator can go, if - or + then 0 or -1 if not.
// z is a counter that keeps track of zeros  
// y is the ending point, it keeps track of where the 0's start 
BigInteger stringToBigInteger(char* s) {
   //implement checks
   BigInteger B = newBigInteger();
   int len = strlen(s); 
   int i,x,y,z;
   long zero = 0;
   int contLoop; //boolean

   if(s[0] == '+' || s[0] == '-') {
      x = 0;
      for( i = len-1; i >= 0; i = i - POWER) {
         z = 1;
         y = i-POWER;
         if(i-POWER+z > x) { // ensures that we wont try to access s oOBounds
            while(s[i-POWER+z] == '0'){
               if(z>POWER) {
                  prepend(B->number,zero);
                  contLoop = 1;
                  break;
               }
               y = i-POWER+z; // this line is executed POWER times
               z++;
            }
            if(contLoop) continue;
         }
         prepend(B->number,charToLong(s,x,i));
                    
      }      
   } else {
      x = -1;
      for(i = len-1; i >= 0; i = i - POWER) {
         y = i - POWER;
         prepend(B->number,charToLong(s,x,i));        
      } 
   }

   moveFront(B->number);
   if(s[0] == '-') { B->sign = -1;}
   else if(length(B->number) == 1 && get(B->number) == zero) {B->sign = 0;}
   else { B->sign = 1;}
   return B;
}

// copy()
// Returns a reference to a new BigInteger object in the same state as N.
//BigInteger copy(BigInteger N);

// Other operations ------------------------------------------------------------

// printBigInteger()
// Prints a base 10 string representations of N to filestream out.
void printBigInteger(FILE* out, BigInteger N) {
   if(N->sign == -1) fprintf(out,"%s","-"); 
   printList(out,N->number);
}


