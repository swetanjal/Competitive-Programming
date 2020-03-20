#include "bits/stdc++.h"
using namespace std;

int main()
{
	int K;
	cin>>K;
	if((K/2)<18){

		while((K/2)>0){
			cout<<"8";
			K-=2;
		}
		if((K%2)==1)cout<<"4";
		cout<<endl;
	}
	else if((K/2)==18 && (K%2)==0){
		while((K/2)>0){
			cout<<"8";
			K-=2;
		}
		cout<<endl;
	}
	else
		cout<<"-1\n";
	return 0;
}