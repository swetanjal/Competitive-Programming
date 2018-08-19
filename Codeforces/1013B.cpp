#include "bits/stdc++.h"
using namespace std;
const int MAXA = 100000;
int freq1[MAXA], freq2[MAXA];
int N, X;
bool chk()
{
	for(int i = 0; i < MAXA; i++)
	{
		int check = 1;
		if(i == (i & X)){
			check = 2;
		}
		if(freq1[i] >= 2 || freq2[i] >=2 || (freq1[i] >= 1 && freq2[i] >= check))
			return true;
	}
	return false;
}

int main()
{
	cin>>N>>X;
	for(int i = 0; i < N; i++)
	{
		int tmp;
		cin>>tmp;
		freq1[tmp]++;
		freq2[tmp & X]++;
	}
	//Check if answer is -1
	if(chk() == false)
		cout<<"-1\n";
	else
	{
		int flag = 0;
		for(int i = 0; i < MAXA; i++)
		{
			if(freq1[i] >= 2){
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			cout<<"0\n";
			return 0;
		}
		for(int i = 1; i < MAXA; i++)
		{
			int check = 1;
			if(i == (i & X)){
				check = 2;
			}
			if(freq1[i] >= 1 && freq2[i] >= check){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			cout<<"1\n";
			return 0;
		}
		cout<<"2\n";
	}
	return 0;
}