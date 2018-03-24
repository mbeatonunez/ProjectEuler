 /*
 * Name:        09- Special Pythagorean triplet
 * Author:      Moises Beato Nunez
 * Date:        11 Mar 2018
 * Description: Problem 9 of the PojectEuler series. A Pythagorean triplet is a set of three 
 *              natural numbers, a < b < c, for which,
 *                          a2 + b2 = c2
 *              For example, 32 + 42 = 9 + 16 = 25 = 52.
 *              There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *              Find the product abc.
 * Link:        https://projecteuler.net/problem=9
 */
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	int n = 1000;       //the sum we are looking for
    int sum = 0;        //the result of a + b + c
    int max = 500;      //since 1000/3 = 333.33, then a, b and c have to be 3 digit numbers, 
    int min = 100;      //We can reason that a,b, and c, have to be between 100 and 500 since any number combination
                        //greater than 500 would give us a number greater than n/
    int product;
    int a,b,c;
    
    for ( a = min; a < max; a+=5){          //since 1000 is divisible by 5, we are only interested in multiples of 5.
        for ( b = min; b < max; b+=5){
            for ( c = min; c < max; c+=5){
                if (a < b && b < c){        //only check if a < b < c
                    if ( pow(c,2) == (pow(a,2) + pow(b,2))){ //is c^2 = a^2 + b^2 
                        sum = a + b + c;
                        if (n == sum){
                            product = a * b * c;
                            printf("a: %d\nb: %d\nc: %d\nSum: %d\nProduct: %d\n", a, b, c, sum, product);
                            break;                            
                        }
                    }
                }
            }
        }
        
    }
   
	return 0;
}
