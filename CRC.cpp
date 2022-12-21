#include<bits/stdc++.h>
using namespace std;

string find_xor(string a,string b)
{
    int n=b.length();
    string res="";
    for(int i=1;i<n;i++)
    {
        if(a[i]==b[i])res+='0';
        else res+='1';
    }
    return res;    
}

string mod_2_operation(string divident,string divisor)
{
    int n=divident.length();
    int curr_pos=divisor.length();
    string curr=divident.substr(0,curr_pos);
    while(curr_pos<n)
    {
        if(curr[0]=='1')
        {
            curr=find_xor(divisor,curr)+divident[curr_pos];
        }
        else
        {
            string temp(curr.length(),'0');
            curr=find_xor(temp,curr)+divident[curr_pos];
        }
        curr_pos++;
    }
    
    if(curr[0]=='1')curr=find_xor(divisor,curr);
    else
    {
        string temp(curr.length(),'0');
        curr=find_xor(temp,curr);
    }
    return curr;

}

void encode(string data,string divisor)
{
    int n=data.length();
    int m=divisor.length();
    string appended_data=data+string(m-1,'0');
    string remainder=mod_2_operation(appended_data,divisor);
    string codeword_data=data+remainder;
    cout<<"given_word is : "<<data<<endl;
    cout<<"appended_data is : "<<appended_data<<endl;
    cout<<"remainder is : "<<remainder<<endl;
    cout<<"codeword is : "<<codeword_data<<endl;

}

int main()
{
    string send_msg,rec_msg,divisor;
    cout<<"enter data to send & key to use as divisor :"<<endl;
    cin>>send_msg>>divisor;
    encode(send_msg,divisor);
    cout<<"enter received message :"<<endl;
    cin>>rec_msg;
    string temp=mod_2_operation(rec_msg,divisor);
    if(temp.find('1')!=string::npos)cout<<"there is error in transmission"<<endl;
    else cout<<"safe transmission"<<endl;
}
//////////////////////////////////////////////////////// perfect////////////////////////////////////////////////