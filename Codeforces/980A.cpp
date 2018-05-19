#include "bits/stdc++.h"
using namespace std;
string S;
int main()
{
	cin>>S;
	int L=S.size();

	int dash = 0;
	for(int i=0; i<L; i++){
		if(S[i] == '-')
			dash++;
	}
	int dot = L-dash;
	if(dash==0 || dot == 0){
		cout<<"YES\n";
	}
	else if((dash%dot)==0){
		cout<<"YES\n";
	}
	else
		cout<<"NO\n";
	return 0;
}