#include <bits/stdc++.h>
using namespace std;
int main()
{
	int A,B,C,D;
	cin>>A>>B>>C>>D;
	int smaller_end=min(2*C,2*D);
	int bigger_start=max(C,D);
	if(D>=A || D>=B || bigger_start>smaller_end){
		cout<<"-1\n";
	}
	else
	{
		if(bigger_start>=(2*B) || bigger_start>=(2*A))
		{
			cout<<"-1\n";
		}
		else cout<<(2*A)<<"\n"<<(2*B)<<"\n"<<bigger_start<<endl;
	}
	return 0;
}