/*
 * Name:        03- Largest prime factor
 * Author:      Moises Beato Nunez
 * Date:        03 Mar 2018
 * Description: Problem 3 of the PojectEuler series. The prime factors of 13195 are 5, 7, 13 and 29.
 *              What is the largest prime factor of the number 600851475143 ?
 * Link:        https://projecteuler.net/problem=3
 */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#define VERSION 0.1

int isPrime(uint32_t num);

int main(int argc, char **argv)
{
    uint64_t value =  600851475143;             //scary large number
    uint32_t value2 = sqrtl(value);             //The greates prime factor of n is at most equal to the square root of n

    printf("Prime Factors of %"PRIu64": \n", value);
    for (uint32_t i = 2; i <= value2 ; i++){    //only count to the square root of n
        if ((value % i) == 0){                  //if the value of i is a factor of the scary large number
            if (isPrime(i)) {                   //check if it is prime. If so, print it.
                printf("%u ", i);
            }
        }
    } printf("\n");                             //once everything is done, print a new line.
    
	return 0;
}


/* isPrime() – checks if given number is prime
 * arguments: an unsigned integer
 * returns: 1 if prime, 0 if composite
 */
int isPrime(uint32_t num){
    int check = 0;                      //keeps track of the number of remainders
    int max_factor = num / 2;           //optimized the number of prime checks
    for (int i = 2; i <= max_factor; i++)
          if(!(num % i)) 
              check++;                  //checks if a number is divisable by any before it
    if(check == 0) 
        return 1;                       //if a number is not divisible by any number, then it is a prime
    else 
        return 0;                       //if divisable by a number greater than 1, then it is not prime.
      
}