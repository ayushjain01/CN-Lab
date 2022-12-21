#include<bits/stdc++.h>
using namespace std;

string find_1s_complement(string str)
{
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        if(str[i]=='0')str[i]='1';
        else str[i]='0';
    }
    return str;
}

string calculate_checksum(string data,int block_size)
{
    int n=data.size();
    if(n%block_size!=0)
    {
        int more=block_size-n%block_size;
        data=string(more,'0')+data;        
    }
    string res=data.substr(0,block_size);
    for(int i=block_size;i<n;i+=block_size)
    {
        string next_block=data.substr(i,block_size);
        string temp_sum="";
        int sum=0,carry=0;
        for(int j=block_size-1;j>=0;j--)
        {
            sum+=res[j]-'0'+next_block[j]-'0';
            carry=sum/2;
            if(sum==0)temp_sum='0'+temp_sum;
            else if(sum==1)temp_sum='1'+temp_sum;
            else if(sum==2)temp_sum='0'+temp_sum;
            else temp_sum='1'+temp_sum;
            sum=carry;
        }
        if(carry==1)
        {
            int i=block_size;
            do
            {
                if(temp_sum[i]=='0')temp_sum[i]='1';
                else temp_sum[i]='0';
            }while(i>=0&&temp_sum[i--]!='0');
        }
        res=temp_sum;
    }
    return find_1s_complement(res);
}

bool checker(string send_msg,string rec_msg,int block_size)
{
    string sender_cheksum=calculate_checksum(send_msg,block_size);
    string temp=rec_msg+sender_cheksum;
    string rec_checksum=calculate_checksum(temp,block_size);
    if(count(rec_checksum.begin(),rec_checksum.end(),'0')==block_size)return true;
    return false;

}
int main()
{
    string send_msg,rec_msg;
    int block_size;
    cout<<"enter send message && received message && block size "<<endl;
    cin>>send_msg>>rec_msg>>block_size;
    if(checker(send_msg,rec_msg,block_size))cout<<"No error"<<endl;
    else cout<<"error"<<endl;
}