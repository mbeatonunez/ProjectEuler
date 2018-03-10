 /*
 * Name:        06- Sum square difference
 * Author:      Moises Beato Nunez
 * Date:        10 Mar 2018
 * Description: Problem 6 of the PojectEuler series. The sum of the squares of the first ten natural numbers is,
 *                                      12 + 22 + ... + 102 = 385
 *              The square of the sum of the first ten natural numbers is,
 *                                      (1 + 2 + ... + 10)2 = 552 = 3025
 *              Hence the difference between the sum of the squares of the first ten natural numbers and the 
 *              square of the sum is 3025 − 385 = 2640. Find the difference between the sum of the squares of 
 *              the first one hundred natural numbers and the square of the sum.
 * Link:        https://projecteuler.net/problem=6
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXVALUE 100

int main(int argc, char **argv)
{
	int n = MAXVALUE, m = MAXVALUE;
    /* calculate the square of the sum */
    m = (m * (m + 1)) / 2;      // get the sum of 1 to m
    m = m * m;                  // get the square of m
    /* calculate the sum of the squares */
    n =  (((2 * n) + 1) * (n + 1) * n) / 6;
    
    printf("%d - %d = %d\n",m, n, (m-n));
	return 0;
}
