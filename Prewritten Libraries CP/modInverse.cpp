/*ax+by=gcd(a,b)
Extended Euclidean Algorithm finds x and y for us. 
This in turn helps us to find the modular inverse as follows.
Suppose we want to find modular inverse of a (mod m).
We make b=m
ax+my=gcd(a,m)
ax+my=1
ax=1-my
ax congruence 1 (mod m)
x is the modular inverse
Refer: http://www-math.ucdenver.edu/~wcherowi/courses/m5410/exeucalg.html to get an idea how it works
How we get the recurrence?
***In our functions we assume a>b
We always send extended_gcd(b,a%b) as a%b will always be <= b. This is trivial.
When b==0 gcd=a and the above equation ax+by=gcd(a,b) can be rewritten as
ax=a => x=1 and y=0 This is our base case.
Moving onto our recursive case.
ax+by=g.................(1)
b*x1+(a%b)*y1=g [We proved this in Euclidean algorithm]
a%b = a - [a/b]*b
Substituting this: 
b*x1+{a - [a/b]*b}*y1=g
b*x1+a*y1-[a/b]*b*y1=g
a*y1 + b*(x1-[a/b]*y1)=g........(2)
Comparing the coefficients of a and b we get:
x=y1
y=x1-[a/b]*y1
*/
#include <bits/stdc++.h>
using namespace std;
long long A,B;
long long x,y;
long long extended_gcd(long long a, long long b)
{
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	long long g=extended_gcd(b,a%b);
	long long x1=x;
	long long y1=y;
	x=y1;
	y=x1-((a/b)*y1);
	return g;
}
int main()
{
	cin>>A>>B;
	long long hcf=extended_gcd(max(A,B), min(A,B));
	if(A>B){
		while(x<0)x+=B;
		cout<<x<<endl;
	}
	else {
		while(y<0)y+=B;
		cout<<y<<endl;
	}
	cout<<"GCD: "<<hcf<<endl;
	return 0;
}
