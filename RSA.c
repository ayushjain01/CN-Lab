#include <stdio.h>
#include <math.h>

int gcd(int a, int h)
{
    while (1)
    {
        int temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

void main()
{
    int msg, p, q, phi, n, e = 2, d = e;
    printf("Enter two prime numbers\n");
    scanf("%d%d", &p, &q);

    printf("Enter the message\n");
    scanf("%d", &msg);

    // Step 1 - Calculate n = p*q
    n = p * q;
    // Step 2 - Calculate phi = (p-1) * (q-1)
    phi = (p - 1) * (q - 1);
    // Step 3 - Choose e such that, 1<e<phi and gcd(e,phi) = 1

    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    // Step 4 - Calculate d, such that (de) % phi = 1

    while (1)
    {
        if (fmod(d * e, phi) == 1)
            break;
        else
            d++;
    }

    long long encrypted = fmod(pow(msg, e), n);
    long long decrypted = fmod(pow(encrypted, d), n);

    printf("p : %d\n", q);
    printf("q : %d\n", p);
    printf("n : %d\n", n);
    printf("phi : %d\n", phi);
    printf("e : %d\n", e);
    printf("d : %d\n", d);
    printf("Cipher Text : %d\n", encrypted);
    printf("Plain Text : %d\n", decrypted);
}
