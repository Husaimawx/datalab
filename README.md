# datalab

In this directory are 15 programming puzzles, marked by difficulty and their restrictions alongside their solutions

All code written to solve the problems have the following restrictions
  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.

  It is forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  Assume that the computer running the code:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

NOTES:
  1. Use the dlc (data lab checker) compiler to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. 
     
     
---

Enclosed are also some autograding tools in the handout directory — btest, dlc, and driver.pl — which can help check the correctness of the solutions
• btest: This program checks the functional correctness of the functions in bits.c. To build and use it, type the following two commands:
```
    unix> make
    unix> ./btest
```
Notice that btest must be rebuilt each time bits.c is modified.
You can also use the -f flag to instruct btest to test only a single function: 
```
unix> ./btest -f bitAnd
```
You can feed it specific function arguments using the option flags -1, -2, and -3: 
```unix> ./btest -f bitAnd -1 7 -2 0xf
```
Check the file README for documentation on running the btest program.

• dlc: This is a modified version of an ANSI C compiler from the MIT CILK group that you can use
to check for compliance with the coding rules for each puzzle. The typical usage is:
```
    unix> ./dlc bits.c
    ```
The program runs silently unless it detects a problem, such as an illegal operator, too many operators, or non-straightline code in the integer puzzles. Running with the -e switch:
```
unix> ./dlc -e bits.c
```
causes dlc to print counts of the number of operators used by each function. Type ./dlc -help
for a list of command line options.
• driver.pl: This is a driver program that uses btest and dlc to compute the correctness and performance points for your solution. It takes no arguments:
```
unix> ./driver.pl
```
