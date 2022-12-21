#include <stdio.h>
#define BSIZE 12

void main()
{
    int g, inPack = 0, outPack = 0, buffer = 0, constRate = 0;
    printf("\nEnter number of group packets : ");
    scanf("%d", &g);
    int incoming[10] = {0}, inRate[10] = {0}, outRate[10] = {0}, inBucket[10] = {0}, dropped[10] = {0};
    printf("\nEnter number of packets in each group : ");
    for (int i = 0; i < g; i++)
    {
        scanf("%d", &incoming[i]);
        inRate[i] = incoming[i];
        outRate[i] = 0;
        inBucket[i] = 0;
        dropped[i] = 0;
        inPack = inPack + incoming[i];
    }
    printf("\nEnter constant out rate : ");
    scanf("%d", &constRate);
    int count = 0;
    while (!(inPack == outPack))
    {
        buffer = buffer + inRate[count];
        if (buffer <= BSIZE)
        {
            if (buffer <= constRate)
            {
                outRate[count] = buffer;
                buffer = 0;
                inBucket[count] = 0;
                dropped[count] = 0;
            }
            else
            {
                outRate[count] = constRate;
                buffer = buffer - outRate[count];
                inBucket[count] = buffer;
                dropped[count] = 0;
            }
        }
        else 
        {
            outRate[count] = constRate;
            buffer = buffer - outRate[count];

            if (buffer > BSIZE)
            {
                dropped[count] = buffer - BSIZE;
                buffer = BSIZE;
                inBucket[count] = buffer;
            }
            else
            {
                inBucket[count] = buffer;
                dropped[count] = 0;
            }
        }
        outPack += outRate[count] + dropped[count];
        count++;
    }
    printf("\n| Clock | InRate | OutRate| InBucket | Dropped |");
    printf("\n------------------------------------------------");
    for (int i = 0; i < count ; i++)
        printf("\n|\t%d|\t%d|\t%d|\t%d|\t%d|", i+1, inRate[i], outRate[i], inBucket[i], dropped[i]);
}
// 13 6 5 20 40