//=============================================================================
// BigInteger.h
// Header file for BigInteger ADT
//
// Tristan Clark
//=============================================================================

#ifndef _BIGINTEGER_H_INCLUDE_
#define _BIGINTEGER_H_INCLUDE_

// Exported type --------------------------------------------------------------

// BigInteger reference type
typedef struct BigIntegerObj* BigInteger;

// Constructors/Destructors ---------------------------------------------------

// newBigInteger()
// Returns a reference to a new BigInteger object in the zero state.
BigInteger newBigInteger();

// freeBigInteger()
// Frees heap mememory associated with *pN, sets *pN to NULL.
// void freeBigInteger(BigInteger* pN);

// Access functions -----------------------------------------------------------

// sign()
// Returns -1 if N is negative, 1 is N is positive, and 0 is in the zero state.
int sign(BigInteger N);

// compare()
// Returns -1 if A<B, 1 is A>B, and 0 if A=B
int compare(BigInteger A, BigInteger B);

// equals()
// Return true (1) if A and B are equal, false (0) otherwise.
int equals(BigInteger A, BigInteger B);

// Manipulation procedures ----------------------------------------------------

// makeZero()
// Re-sets N to the zero state.
void makeZero(BigInteger N);

// negate()
// Reverses the sign of N: positive <--> negative. Does nothing if N is in
// the zero state.
void negate(BigInteger N);

// BigInteger Arithmetic operations -------------------------------------------

// stringToBigInteger()
// Returns a reference to a new BigInteger object representing the decimal
// integer represented in base 10 by the string s.
// Pre: s is a non-empty string containing only base ten digits 
// {0,1,2,3,4,5,6,7,8,9} and an oprional sign {+,-} prefix.
BigInteger stringToBigInteger(char* s);

// copy()
// Returns a reference to a new BigInteger object in the same state as N.
//BigInteger copy(BigInteger N);

// Other operations ------------------------------------------------------------

// printBigInteger()
// Prints a base 10 string representations of N to filestream out.
void printBigInteger(FILE* out, BigInteger N);

int myPow(int k);

long charToLong(char* s, int i, int x);

#endif
