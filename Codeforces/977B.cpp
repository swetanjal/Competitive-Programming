#include "bits/stdc++.h"
using namespace std;
string S;
int main()
{
	char x,y;
	int MAXA = 0;
	int L;
	cin>>L;
	cin>>S;
	
	for(char i='A'; i<='Z'; i++){
		for(char j='A'; j<='Z'; j++){
			int f=0;
			for(int k=0; k<(L-1); k++){
				if(S[k] == i && S[k+1] == j)f++;
			}
			if(f>MAXA){
				MAXA = f;
				x = i;
				y = j;
			}
		}
	}
	cout<<(char)x<<(char)y<<endl;
	return 0;
}