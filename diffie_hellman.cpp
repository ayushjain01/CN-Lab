#include<bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b,
					long long int P)
{
	if (b == 1)
		return a;
	else
		return (((long long int)pow(a, b)) % P);
}

int main()
{
	long long int P, G, x, y, r1, r2, ka, kb;
	P = 23; 
	cout << "The value of P : " << P << endl;
	G = 9; 
	cout << "The value of G : " << G << endl;
    cout<<"enter private key of alice :";
    cin>>x;
    cout<<"enter private key of bob :";
    cin>>y;
	r1 = power(G, x, P); 
	r2 = power(G, y, P); 
	cout << "The public key  for Alice : " << r1 << endl;
	cout << "The public key b for Bob : " << r2 << endl;
	ka = power(r2, x, P);
	kb = power(r1, y, P);
	cout << "Secret key for the Alice is : " << ka << endl;
	cout << "Secret key for the BOB is : " << kb << endl;

	return 0;
}