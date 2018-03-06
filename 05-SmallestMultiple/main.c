 /*
 * Name:        05- Smallest Multiple
 * Author:      Moises Beato Nunez
 * Date:        05 Mar 2018
 * Description: Problem 5 of the PojectEuler series. 2520 is the smallest number that can be 
 *              divided by each of the numbers from 1 to 10 without any remainder.
 *              What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?.
 * Link:        https://projecteuler.net/problem=5
 */
#include <stdio.h>


int isPrime(int num);
int main(int argc, char **argv)
{
	
    int n = 1, i = 2, j = 1, m = 10;

    while (i < m){
        if (isPrime(i)){
            while (j < m){
                j *= i;
            }
        }
        n *= j;
        i++;
        j=1;
    }
    
    printf("n=%d  i=%d  j=%d\n", n, i, j);
    
	return 0;
}

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