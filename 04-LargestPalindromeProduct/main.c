/*
 * Name:        04- Largest Palindrome Products
 * Author:      Moises Beato Nunez
 * Date:        04 Mar 2018
 * Description: Problem 4 of the PojectEuler series. A palindromic number reads the same both ways.
 *              The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *              Find the largest palindrome made from the product of two 3-digit numbers.
 * Link:        https://projecteuler.net/problem=4
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t isPal(uint32_t num);   //checks to see if a number is a palindrome

int main(int argc, char **argv)
{
	uint32_t max_count = 1000;  //a 3-digit number lives between 100 and 999
    uint32_t min_count = 100;
    uint32_t max_pal = 0;

    for (uint32_t i = min_count; i < max_count; i++){
        for (uint32_t j = i; j < max_count; j++){   // set j to i to avoid checking the same number twice
           if (isPal(i*j) ){
               if (i*j > max_pal)                   //check for the largest value.
                    max_pal = i*j; 
           }
               
        }
    }
    printf("Largest Palindrome Products of two 3-digit numbers: %d\n", max_pal);
    
    return 0;
}
/* isPal()   checks to see if a number is a palindrome
 * argument: a unsigned int to be checked
 * returns:  1 if palindrom, 0 otherwise
 */ 
uint32_t isPal(uint32_t num){
    uint32_t orig = num;       
    uint32_t revs = 0;
    while( num!=0 )             //loop reverses the number by adding the remainders 
    {                           // and multiplying them by 10 at each pas
        revs = revs*10 + (num%10);
        num /= 10;              //decrement the number by one order of magnitude
    }
    
    if (orig == revs ) return 1; 
    else return 0;
}