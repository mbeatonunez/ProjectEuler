 /*
 * Name:        12- Highly divisible triangular number
 * Author:      Moises Beato Nunez
 * Date:        28 Mar 2018
 * Description: Problem 12 of the PojectEuler series. The sequence of triangle numbers is 
 *              generated by adding the natural numbers. So the 7th triangle number would 
 *              be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
 *                          1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *              Let us list the factors of the first seven triangle numbers:
 *                      1: 1
 *                      3: 1,3
 *                      6: 1,2,3,6
 *                      10: 1,2,5,10
 *                      15: 1,3,5,15
 *                      21: 1,3,7,21
 *                      28: 1,2,4,7,14,28
 *              We can see that 28 is the first triangle number to have over five divisors.
 *              What is the value of the first triangle number to have over five hundred divisors?
 * Link:        https://projecteuler.net/problem=12
 */
#include <stdio.h>

int isPrime(int num); //prime number checker

int main(int argc, char **argv)
{
	int divisor = 1;      //start at 1 to account for
    int limit = 500;
    unsigned long int n = 1000, i = 2;         //start at the 10th triangular number
    unsigned long long int triangle, temp;
    while (divisor <= limit){    
        temp = triangle = (n * (n + 1))/2;  //find the sum from 1 to n
        while (triangle < 0){
            if (0 == triangle % i){
                triangle /= i;
                divisor += 2;
                i++;
            }
        }
        if (divisor <= limit){  //if the nth triangle has less then 500 divisors, reset.
            n++;
            divisor = 1;
        } else                  //otherwise exit the loop
            break;        
    }
    
    printf("Divisor count: %d   nth triangle: %lu\n", divisor, temp);
	return 0;
}

