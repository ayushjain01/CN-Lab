#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long compute(int g, int a, int p)
{
    long long r = fmod(pow(g, a), p);
    return r;
}

void main()
{
    int p, g, x, y, aliceKey, bobKey;
    long long R1, R2, key;
    printf("\nEnter the values of p and g : ");
    scanf("%d %d", &p, &g);
    x = rand()%10;
    printf("\nAlice's Private Key x : %d", x);
    R1 = compute(g, x, p);
    printf("\nAlice send R1 : %d to Bob", R1);
    y = rand()%10;
    printf("\nBob's Private Key y : %d", y);
    R2 = compute(g, y, p);
    printf("\nBob send R2 : %d to Alice", R2);
    aliceKey = compute(R2, x, p);
    bobKey = compute(R1, y, p);
    key = compute(g, (x * y), p);
    printf("\nAlice's Private Key : %d", aliceKey);
    printf("\nBob's Private Key : %d", bobKey);
    printf("\nShared Key : %d", key);
}

// 23 9
