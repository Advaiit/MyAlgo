//Sieve of Eratosthenes
//Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number. 

#include <iostream>
#include <stdio.h>
using namespace std;

void printPrimes(int n)
{
    bool table[n] = {true};

    for(int j = 0;j < n; j++) table[j] = true;

    int p = 2;

    int temp = p;
    int i = 1;

    //Create prime table here
    while(p <= n)
    {
        i = 1;
        while(temp <= n)
        {
            temp = p * ++i;
            table[temp] = false;
        }

        while(!table[++p]);
        temp = p;
    }

    for(int j = 2;j < n; j++) if(table[j]) printf(" %d",j);
    printf("\n");
}

int main()
{
    printPrimes(50);
    return 0;
}