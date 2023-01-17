//Refer https://github.com/ayushjain01/CN-Lab/blob/main/RSA.c first for understanding how RSA works

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int checkPrime(int n)
{
    int i;
    int m = n / 2;

    for (i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            return 0; // Not Prime
        }
    }

    return 1; // Prime
}

int findGCD(int n1, int n2)
{
    int i, gcd;

    for (i = 1; i <= n1 && i <= n2; ++i)
    {
        if (n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }

    return gcd;
}

int powMod(int a, int b, int n)
{
    long long x = 1, y = a;

    while (b > 0)
    {
        if (b % 2 == 1)
            x = (x * y) % n;
        y = (y * y) % n; // Squaring the base
        b /= 2;
    }

    return x % n;
}

int main(int argc, char *argv[])
{
    int p, q; //Note p and q Must be large prime numbers.
    int n, phi;

    char data[50], cipherText[50], plainText[50];
    int cipher[50], decrypt[50];

    while (1)
    {
        printf("Enter any two prime numbers: ");    //Code works best with p = 13 and q = 17, breaks for other numbers. Got a fix? Please issue a Pull Request.
        scanf("%d %d", &p, &q);

        if (!(checkPrime(p) && checkPrime(q)))
            printf("Both numbers are not prime. Please enter prime numbers only...\n");
        else if (!checkPrime(p))
            printf("The first prime number you entered is not prime, please try again...\n");
        else if (!checkPrime(q))
            printf("The second prime number you entered is not prime, please try again...\n");
        else
            break;
    }

    n = p * q;

    phi = (p - 1) * (q - 1);

    int e = 0;
    for (e = 5; e <= 100; e++)
    {
        if (findGCD(phi, e) == 1)
            break;
    }

    int d = 0;
    for (d = e + 1; d <= 100; d++)
    {
        if (((d * e) % phi) == 1)
            break;
    }

    printf("Value of e: %d\nValue of d: %d\n", e, d);

    printf("Enter a string: ");
    scanf("%s", &data);
    int array[50];
    for (int i = 0; i < strlen(data); i++)
    {
        array[i] = (int)((char)data[i]);
    }

    for (int i = 0; i < strlen(data); i++)
    {
        cipher[i] = powMod(array[i], e, n);
    }
    printf("\nCipher Text : ");
    for (int i = 0; i < strlen(data); i++)
    {
        cipherText[i] = (char)cipher[i];
        printf("%c", cipherText[i]);
    }
    printf("\n");

    for (int i = 0; i < strlen(data); i++)
    {
        decrypt[i] = powMod(cipher[i], d, n);
    }
    printf("\nPlain Text : ");

    for (int i = 0; i < strlen(data); i++)
    {
        plainText[i] = (char)decrypt[i];
        printf("%c", plainText[i]);
    }
    printf("\n");
    return 0;
}
