#include <stdio.h>

void checksum(int messages[], int n)
{   
    int sum = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + messages[i]; //calculate sum
    }
    sum = ~sum; //complement sum to get checksum
    messages[i] = sum;
}
void printMessages(int messages[], int n)
{
    for (int i = 0; i <= n; i++) printf("\t%d", messages[i]); //i<=n because the arrays now have one extra element (checksum), i.e n messages + 1 checksum
}
void main()
{
    int n, flag =0;
    printf("\nEnter number of messages to send :");
    scanf("%d",&n);
    int sender[n], receiver[n];
    printf("\nEnter Messages :"); //Step 1 - Get message input
    for (int i = 0; i < n; i++) {
        scanf("%d",&sender[i]);
        receiver[i] = sender[i];
    }//Step 2 - Calculate checksum
    checksum(sender,n);
    receiver[n] = sender[n];
    printf("\nEnter 1 if you want to induce an error at receiver side :");
    scanf("%d",&flag);
    if (flag == 1){
        receiver[0] += 1; //inducing error in the first message
    }
    checksum(receiver,n+1); //receiver side = n messages + 1 checksum
    printf("\n***************************Sender Side***************************\n");
    printMessages(sender,n);
    printf("\n**************************Receiver Side**************************\n");
    printMessages(receiver,n+1);
    if (receiver[n+1] == -1) printf("\nError Detected!");
    else printf("\nNo Errors detected!");
}