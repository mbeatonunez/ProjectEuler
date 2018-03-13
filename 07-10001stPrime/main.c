 /*
 * Name:        07- 10001st prime
 * Author:      Moises Beato Nunez
 * Date:        11 Mar 2018
 * Description: Problem 7 of the PojectEuler series. By listing the first six prime numbers: 
 *                          2, 3, 5, 7, 11, and 13, 
 *              we can see that the 6th prime is 13. What is the 10,001st prime number?
 * Link:        https://projecteuler.net/problem=7
 */
#include <stdio.h>
#include <math.h>

int isPrime(int num){
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

int main(int argc, char **argv)
{
	int nth_prime = 10001;
    int n = 1, i = 1;  
    //brute force approach (most inefficient)
    while (n < nth_prime){
        i +=2;                 //only check odd number
        if (isPrime(i)) n++;
    }
    printf("The %d'th Prime number is %d\n", nth_prime, i);
	return 0;
}
