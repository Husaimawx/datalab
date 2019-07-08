/* 
 * CS:APP Data Lab 
 * 
 * Xingzhe Zhou UID: 105158264
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /*DeMorgan's Law a&b = ~(~a | ~b)*/
int n = ~(~x | ~y); //DeMorgan's Law
return n;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /*right shift x until the byte we want is the rightmost byte, then bitwise and (&) it with all 1's on the last byte and 0's everywhere else (0xFF) so only the byte we are looking for remains*/
x = x >> (n << 3); //does shifting
x = x & 0xFF; //only byte we want remains
return x;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
 /*we will create a mask based on the value n, with the appropriate amount of  0's in front and 1's at the end
 * this has the effect of replacing the 1's that may show up at the front of an arithmetic right shift with the 0's of a logical right shift
 * then we arithmetic right shift and apply a bit wise and (&) with our mask to replace the potential 1's put at the front due to the arithmatic right shift with the correct  0's instead*/
int m = ~(((x & (1 << 31)) >> n) << 1); //mask
return (x >> n) & m; //use the mask to take off the excess 1's
   
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
/*sums the total of every 4 bits using a shifted mask then adds every other summed bit repeatedly until we are left with a single sum*/
int mask2;
int total; 
int mask = 0x11 | (0x11 << 0x8) | (0x11 << 0x10) | (0x11 << 0x18); //mask number 1
int sum = (x & mask) + ((x >> 0x1) & mask) + ((x >> 0x2) & mask) + ((x >> 0x3) & mask);//sums the total of every 4 bits
sum += (sum >> 0x10); //adds every other sum together
mask2 = 0xf | (0xf << 0x8); //mask2
sum = (sum & mask2) + ((sum >> 0x4) & mask2); //adds every other sum together
total = (sum + (sum >> 0x8)) & 0x3f; //adds the final two together to get the total sum
return total;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
/*use the fact that only 0 has a leading 0 when bit wise or (|) with its negative counterpart to determine if a number is 0*/
int counterpart = ~x + 1; //-x = ~x + 1
int isZero = ((x | counterpart) >> 31) + 1; //only zero has property that both it and its opposite have a most significant byte of 0
return isZero; 
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
/*we use a mask that is set to 111... if x is true and 000... if x is false
 * then we bit wise or with the two resulting statements so the correct one is displayed only when it is bit wise and (&) with 111...*/
int mask = (0xff + (0xff << 8) + (0xff << 16) + (0xff << 24)) + !x; //when x is true, mask becomes 111... else becomes 000...
int conditional = (mask & y) | (~mask & z); //returns the correct statement because bitwise and ensures only the correct one of the two is displayed
return conditional;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
/*test that the number is positive and that when bit wise and contains only a single 1*/
int n = (!x << 0x1f) >> 0x1f;
return (~n) & (!((~(x & (~x + 0x1)) | (0x1 << 0x1f)) & x)); //insures it is non-zero, non-negative and contains a single 1
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
/*form mask of form 101010... and then bit wise and (&) with x, then ^ (xor) with mask
 * this results in 0 if it is valid and non-zero if it is not
 * then we can ! it to get our solution*/ 
int mask = 0xAA + (0xAA << 8) + (0xAA << 16) + (0xAA << 24); //mask = 101010...
return !((x & mask) ^ mask); //bitwise and (&) mask with x, then bitwise xor (^) that with the mask then negate
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
/*shift or value x (32 - n) to the left then back to the right to replace the leading terms with 0's
 * we then compare this with the original using the bit wise xor (^) to see if anything is different
 * if something is different, it means there must be have at least a 1 in a bit that is not allowed for the size n
 * otherwise, our exclusive or will produce exactly 000... which when !, will return 1*/
int shift = 32 + (~n + 1); //defines how much we are shifting
return !(((x << shift) >> shift) ^ x); //compares our shifted left then back with the original x to see if any terms are different (means there is a 1 where it cannot be for a 2's complement of size n) 
}
/* 
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n) {
/*if x is positive, we do nothing
 * if x is negative, we need to use the complement so it rounds down properly*/
int neg = x >> 0x1f; //determines if it is negative
return ((((neg & 0x1) << n) + neg) + x) >> n; //if it is, we use complement to round
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
/* use -x = ~x + 1*/
return (~x + 1);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x) {
/*move the sign bit to the very right, make sure it is not zero by bit wise and (&) with !!x since only x = 0 has !!x = 0*/ 
int sign = x >> 0x1f; //gets sign bit
return (!sign & !!x); //makes sure its not zero as well
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
/*first determine if x and/or y are negative, then compute their difference and find the sign bit
 * afterwards, we do  each case seperately: when one is pos/neg and when both are same sign bit*/
int negative_y = (y >> 0x1f) & 0x1; //finds if y is negative
int negative_x = (x >> 0x1f) & 0x1; //finds if x is negative
int n = ((y + ~x + 1) >> 0x1f) & 0x1; //finds sign bit of y-x
return (!(negative_x ^ negative_y) & !n) | (negative_x & !negative_y); //when one is positive and one is negative, determines based off sign bit otherwise we use n to determine which is greater 
}
/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x) {
/*masks each part of the bits to determine where the leftmost 1 is using similar to binary search method to locate*/
int n = ((!!(x >> 0x10)) << 0x1f) >> 0x1f; //tells if the greatest bit is on the leftmost 16 bits
int sig = n & 0x10; 
x = x >> (n & 0x10); //shifts the values on the left
n = ((!!(x >> 0x8)) << 0x1f) >> 0x1f; //tells if the greatest bit is on the leftmost 8 bits
sig = sig + (n & 0x08); 
x = x >> (n & 0x08); //shifts the values on the left
n = ((!!(x >> 0x4)) << 0x1f) >> 0x1f; //tells if the greatest bit is on the leftmost 4 bits
sig = sig + (n & 0x4); 
x = x >> (n & 0x4); //shifts the values on the left
n = ((!!(x >> 0x2)) << 0x1f) >> 0x1f; //tells if the greatest bit is on the leftmost 2 bits
sig = sig + (n & 0x2); 
x = x >> (n & 0x2); //shifts the values on the left
n = ((!!(x >> 0x1)) << 0x1f) >> 0x1f; //tells if the greatest bit is on the leftmost 1 bit
sig = sig + (n & 0x1);
return sig;    
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
/*occurs when x & -x because all the other terms will be 0*/
return (x & (~x + 1)); //~x + 1 = -x
}
