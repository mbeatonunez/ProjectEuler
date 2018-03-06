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
#include <math.h>


int isPrime(int num);
int main(int argc, char **argv)
{
    /* To calculate the smallest multiple from 1 to m, it is not necessary to use every number on that range.
     * Notice that 2520 = 5*7*8*9; If 10 is a factor of N, then so is 5. Likewise, if N mod 8 = 0, so does 2 and 4.
     * This is also the case for 9 and 3. Additionally, if N mod 2 = N mod 3 = 0, then N mod 6 must equal zero.
     * Therefore, 5,7,8 and 9 account for all numbers from 1 to 10.
     * Now, if we convert them to prime factor we get:
     *                   2520 = 5*7*(2*2*2*2)*(3*3).
     * Notice that no single prime-exponent pair (p^x) is greater than m
     *                   (2^4) < 10, (3^2) < 10...
     * Therefore, we can calculate the smallest multiple, n, by multiplying every instance from p to m where p^x < m.
     *                   (2^4)*(3^2)*(5^1)*(7^1) = 2520
     */
    long unsigned int n = 1; //smallest multiple
    int p;                   //prime number
    int x;                   //exponent
    int m = 20;              //upper limit of range (1 to m)
    float power;             //Greatest power of p^x

    for (p = 2;p <= m; p++){                                 //check every prime number less than or equal to m
        if (isPrime(p)){
            for (x = 1; pow(p,x) < m; x++) power = pow(p,x); //find the greatest power of a prime equal less then m (p^x < m)
            n *= power;

        }
    }
    printf("The smallest multiple of range 1 to %d is %d \n", m, n);


	return 0;
}

int isPrime(int num){
    int check = 0;                      //keeps track of the number of remainders
    int max_factor = num / 2;           //optimized the number of prime checks
    for (int i = 2; i <= max_factor; i++)
          if(!(num % i))
              check++;                  //checks if a number is divisible by any before it
    if(check == 0)
        return 1;                       //if a number is not divisible by any number, then it is a prime
    else
        return 0;                       //if divisible by a number greater than 1, then it is not prime.

}
