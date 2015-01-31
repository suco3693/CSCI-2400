/* 
 * CS:APP Data Lab 
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

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team = 
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
    "suco3693 + dabr9981", 
   /* Student name 1: Replace with the full name of first team member */
   " Sutton Cowperthwaite",
   /* Login ID 1: Replace with the login ID of first team member */
   "Suco3693",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "Danny Brill",
   /* Login ID 2: Login ID of the second team member */
   "Dabr9981"
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
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
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1; //shifts 1 over X number of times and adds 1
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x); // shifts 1 over X number of times
     result += 4; // adds 4 to the result
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
//
// 15 problems, 40 points
// 2 - rating 1
// 5 - rating 2
// 4 - rating 3
// 4 - rating 4


/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1<<31); //shift one bit to the highest spot 
                 // i.e. -(2^31);
}



/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  return ~(0); // -1 in binary is all 1's. so take the opposite of all zeros
}


/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int evenBits(void) {
	//5 is 0101. use hex to make 8 bits of even numbered bits as 1's
   // then shift the bits over to the end of the 8byte word
  return (0x55<<24)+(0x55<<16)+(0x55<<8)+(0x55); 
}




/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	//get the most significant bit of x
	int r = (x >> 31); // -1 if it's negative or 0  
	//q is (2^n)-1
	int q = ((1<<n)+ (~(0))); // all 1's in front of 2^n
	//if r is negative add one to x. 
	r = r & q; // checks if x is 0 
	x = x + r; // add values so as not to lose magnitude when shifting in line below
			   // this also accounts for the remainder and ensures a nice result
	x = (x >> n);  //shift to the right n times to do the proper division
  return x; 

}



/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  return !(x ^ y); //if they are equal ^ makes the value 0. then ! returns 1
				  // if they aren't equal ^ makes the value non zero. then ! returns 0
}





/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	//flip all bits and add one
  return ~(x)+1;
}





/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	int q =(n<<3); // if it's the 0th byte we don't have to shift it
				   // if it's the 3rd byte we have to shift 24 bit
				   // we multiply the byte number, n, by 8
	int r = (x>>q);// then shift the byte over that, q, number of spaces
  return r & 0xFF; //  mask the desired bit with the & of all 1's to get only the desired bit
}




/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	//!x checks if it is 0;
	int y = (1<<31); //shift a bit into the sign position
	
	
  return (!((x & y) | !x)); // if there is a bit in the sign spot return 0
							// if x is 0 return 0
}





/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {

	int negX = !(x >> 31); // if x is neg returns 0
	int negY = !(y >> 31); // if y is neg returns 0
	int sum = !((x + y)>>31); // if x + y is negative returns 0 otherwise 1
	int same = !(negX ^ negY); // if they are the same returns 1
	int dif = (sum ^ negY); // if they are different returns a 1	
  return !(same & dif); //if x and y have the same sign but the sum sign is different
						// then the addition isn't ok return a 0. otherwise return 1

}






/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int d = (x + (~y + 1)) >> 31; // checks if x - y is greater than 0 
		int a;
		int isZero = !(x + (~y + 1)); // returns 1 if x and y are equal
		x = x >> 31;  // retreive most significant bit
		y = y >> 31;  //
		// if x and y are different it returns 1 otherwise 0
		a = (x^y); // a = 1 if the signs are different 
		//
		a = (a & x) | (~a & d) | isZero;	//if different signs and x is negative -- 1
							    // or if signs are same and x is greater than -y -- 1
							    // or if x - y = 0  -- 1
  return (a & 1); 
  
  
  
}






/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	x = (x >> n); // shift x down n spaces
	int mask = 1 << 31;
	mask = mask >> (n + ~(0));
	mask = ~mask;
  return x & mask;
}





/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int leastBitPos(int x) {
	int negative = ~x + 1; // flips bits
	int result = x & negative; // highlights only the least significant bit 
  return result;
}




/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
	//an odd number of 0's implies an odd number of 1's
	//so if we compare bits 2 at a time and end up with an 
	//odd number of differences we know that we have an odd number of 0's
	//so fold the number in half and compare the bits
	//fold that number in half and compare the bits
	//by the final comparison every pair was compared once and a 1 means
	//there are an odd number of differences and 0 implies an even number
	int y = x >> 16; 
	x = y ^ x;
	y = x >> 8;
	x = y ^ x;
	y = x >> 4;
	x = y ^ x;
	y = x >> 2;
	x = y ^ x;
	y = x >> 1;
	x = y ^ x;
  return (x & 1);
}





/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 60
 *   Rating: 4
 */
int isPower2(int x) {
	int comp=~(x)+1; //two's complement, complement of x
	int neg= (x >> 31) & 1;// equals 1 if x is negative, 0 otherwise
	int z= ~(comp | ~(x));// if x is not a power of 2 return 0
  return (!!(x)) & (!(neg)&!(z)); //if x is 0 return 0 (first)
		//if x is negative return 0 (second)
		//if x is odd return 0  (second)
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	int y = x << 1; // if there is a 1 this pattern guarantees a 1 in the most significant spot
	int result = x | y; //shift the bits over and "or" them with the original bits
	y = result << 2;
	result = y | result;
	y = result << 4;
	result = y | result;
	y = result << 8;
	result = y | result;
	y = result << 16;
	result = y | result;
	result = result >> 31; //therefore the most significant bit is copied to all bits
	result = result + 1;//add one to overflow all 1's to a zero or to make a zero a 1;
  return result;
}
