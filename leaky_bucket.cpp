#include<bits/stdc++.h>
using namespace std;

void licky_bucket()
{
    int n_packets,bucket_cap,outgoing_rate,received=0,sent=0,contain=0,dropped=0,have;
    cout<<"enter n_packets && bucket_capacity && outgoing_rate :"<<endl;
    cin>>n_packets>>bucket_cap>>outgoing_rate;
    vector<int>packet_size(n_packets*2,0);
    for(int i=0;i<n_packets;i++)
    {
        packet_size[i]=rand()%10;
    }
    cout<<"Iteration Received Sent Contain Dropped "<<endl;
    for(int i=0;i<n_packets||contain>0;i++)
    {
        received=packet_size[i];
        have=received+contain;
        if(have<=outgoing_rate)
        {
            sent=have;
            contain=0;
            dropped=0;
        }
        else
        {
            sent=outgoing_rate;
            contain=min(bucket_cap,have-sent);
            dropped=have-sent-contain;
        }
        cout<<"   "<<i<<"       "<<received<<"       "<<sent<<"     "<<contain<<"     "<<dropped<<endl;

    }
}
int main()
{
    licky_bucket();
    return 0;
}