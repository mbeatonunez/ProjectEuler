 /*
 * Name:        10- Summation of primes
 * Author:      Moises Beato Nunez
 * Date:        26 Mar 2018
 * Description: Problem 10 of the PojectEuler series. The sum of the primes below 10 is
 *                       2 + 3 + 5 + 7 = 17.
 *              Find the sum of all the primes below two million.
 * Link:        https://projecteuler.net/problem=10
 */
#include <stdio.h>
#include <math.h>

int isPrime(int num){
    int prime;
    if (num == 1) prime = 0;
    else if (num < 4) prime = 1;
    else if ( 0 == (num % 2) ) prime = 0;
    else if (num < 9) prime = 1;
    else if ( 0 == (num % 3) ) prime = 0;
    else {
        prime = 1;
        int round = floor(sqrt(num));
        int factor = 5;
        while (factor <= round){
            if (0 == (num % factor) || 0 == (num % (factor + 2))){
                prime = 0;
                break;
            }
            factor += 6;
        }
    }
    return prime;
}

int main(int argc, char **argv)
{
	unsigned long long int i, sum = 2;
    int limit = 2000000;
    int count = 0;
    for (i = 3; i < limit; i += 2){
        if (isPrime(i)){
            sum += i;
            count++;
        }
    }
    printf("The sum of the primes below %d is %llu\n", limit, sum);
	return 0;
}
