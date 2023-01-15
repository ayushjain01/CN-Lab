#include <stdio.h>
#include <string.h>

int sDataLen, rDataLen, keyLen, flag = 0;
char sData[50], rData[50], key[50], copy[50], rem[50];


void crc()
{
    for (int i = 0; i < sDataLen; i++)
    {
        if (copy[i] == '0')
            continue;
        for (int j = 0; j < keyLen; j++)
        {
            copy[i + j] = (copy[i + j] == key[j]) ? '0' : '1';
        }
        if (i + keyLen == sDataLen)
            break;
    }
}

void main()
{
    printf("Enter Data to be sent :");
    scanf("%s", &sData);
    printf("Enter Key :");
    scanf("%s", &key);

    sDataLen = strlen(sData);
    keyLen = strlen(key);

    // Step 1 - Append k-1 0's at the end of the message, (k is keyLen)
    for (int i = sDataLen; i < sDataLen + keyLen - 1; i++)
    {
        sData[i] = '0';
    }
    sDataLen = strlen(sData);
    printf("\nModified Data : %s\n", sData);
    strcpy(copy, sData);
    // Step 2 - Perform xor division, divisor = key, dividend = sData and find remainder.
    crc();
    for (int i = 0; i < keyLen; i++)
        rem[i] = copy[sDataLen - keyLen + 1 + i]; // last k-1 digits of copy are the remainder
    printf("\nRemainder is %s\n", rem);

    // Replace last k - 1 digits of sData with remainder
    for (int i = 0; i < keyLen - 1; i++)
    {
        sData[sDataLen - keyLen + 1 + i] = rem[i];
    }
    printf("\nSent Data : %s\n", sData);
    // Step 3 - Perform xor division on received data and calculate remainder
    printf("Enter Data received :");
    scanf("%s", &rData);
    strcpy(copy, rData);
    crc();
    for (int i = 0; i < keyLen; i++)
    {
        rem[i] = copy[sDataLen - keyLen + 1 + i]; // last k-1 digits of copy are the remainder
        if (rem[i] == '1')
            flag = 1;
    }
    printf("\nRemainder is %s\n", rem);
    if (flag == 1)
        printf("\nErrors detected in data\n");
    else
        printf("\nNo errors detected.\n");
}
