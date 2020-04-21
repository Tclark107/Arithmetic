#-----------------------------------------------------------------------------
# Makefile for CSE 101 Programming Assignment 2
#------------------------------------------------------------------------------

#Lex : Lex.o List.o
#	gcc -o Lex Lex.o List.o

#Lex.o : Lex.c List.h
#	gcc -c -std=c99 -Wall Lex.c

BigIntegerTest: BigIntegerTest.o BigInteger.o List.o 
	gcc -o BigIntegerTest BigIntegerTest.o BigInteger.o List.o

BigIntegerTest.o : BigIntegerTest.c BigInteger.h List.h
	gcc -c -std=c99 -Wall BigIntegerTest.c

BigInteger.o : BigInteger.c BigInteger.h
	gcc -c -std=c99 -Wall BigInteger.c

List.o : List.c List.h
	gcc -c -std=c99 -Wall List.c

clean :
	rm -f Lex ListClient Lex.o ListClient.o List.o

