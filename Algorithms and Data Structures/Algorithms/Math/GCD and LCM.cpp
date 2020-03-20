#include <bits/stdc++.h>
using namespace std;
/*The Euclidean Algorithm to compute GCD of two numbers
Refer: https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm
Problem: https://www.codechef.com/problems/FLOW016*/
int T;
long long X,Y;
long long gcd(long long A, long long B){
	if(B==0)return A;
	return gcd(B,A%B);
}
int main()
{
	cin>>T;
	while(T--){
		cin>>X>>Y;
		long long hcf=gcd(max(X,Y),min(X,Y));
		long long lcm=(X*Y)/hcf;
		cout<<hcf<<" "<<lcm<<endl;
	}
	return 0;
}
