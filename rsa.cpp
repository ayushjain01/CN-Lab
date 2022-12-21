#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(b==0)return a;
	else return gcd(b,a%b);
}
int main()
{
	double p=29,q=19;
	double n=p*q;
	double phi=(p-1)*(q-1);
	double e=2;
	while(e<phi)
	{
		if(gcd(e,phi)==1)break;
		else e++;
	}
	//public j=key=fn(n,e)
	 //d=private key
	 double d1=1/e;
	 double d=fmod(d1,phi);
	double msg;
	cout<<"enter message :";
	cin>>msg;
	double c=pow(msg,e); 
	double m=pow(c,d); 
	c=fmod(c,n);
	m=fmod(m,n);
	cout<<"encrypted message :"<<c<<endl;
	cout<<"decrypted message :"<<m<<endl;
}