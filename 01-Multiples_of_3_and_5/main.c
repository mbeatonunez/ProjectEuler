/*
 * Name:        01- Multiples of 3 and 5
 * Author:      Moises Beato Nunez
 * Date:        01 Mar 2018
 * Description: Problem 1 of the PojectEuiler series. If we list all the natural numbers below 10 that are
 *              multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of
 *              all the multiples of 3 or 5 below 1000.
 * Link:        https://projecteuler.net/problem=1
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    uint32_t limit = 1000;                  //find the multiple of 3 and 5 from 1 to this number
    uint32_t sum = 0;                       //hold the addition
    uint32_t nl = 0;                        //used to print a new line for every count of 10

    puts("Multiples: ");

    for (uint32_t i = 1; i < limit; i++){   //iterate from 1 to limit
        if(i % 3 == 0 || i % 5 == 0){       //check for multiple of 3 or 5
            if (nl % 10 == 0) printf("\n");
            sum += i;                       //add and print all multiples found
            printf("%d ",i);
            nl++;
        }
    }
    printf("\nThe sum of all multiple of 3 and 5 between 1 and %d is: %d\n", limit, sum);

    return 0;
}
