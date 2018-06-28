#include "bits/stdc++.h"
using namespace std;
const int MAXNM = 15;
int N,M;
pair <int , int> A[MAXNM];
pair <int , int> B[MAXNM];
int COMMON[10];
int main()
{
	cin>>N>>M;
	for(int i=0; i<N; i++)
	{
		cin>>A[i].first>>A[i].second;
		if(A[i].first>A[i].second)
			swap(A[i].first, A[i].second);
	}
	for(int i=0; i<M; i++)
	{
		cin>>B[i].first>>B[i].second;
		if(B[i].first > B[i].second)
			swap(B[i].first, B[i].second);
	}	
	int flag = 0; int common = -1; int valid = -1; int invalid = -1;
	for(int i=0; i<N; i++)
	{
		int first = 0; int second = 0;
		for(int j=0; j<M; j++)
		{
			if(((A[i].first == B[j].first) && (A[i].second != B[j].second)) || 
				((A[i].first == B[j].second) && (A[i].second != B[j].first)) || 
				((A[i].second == B[j].first) && (A[i].first != B[j].second)) ||
				((A[i].second == B[j].second) && (A[i].first != B[j].first)))
			{
				flag++;
				if(A[i].first == B[j].first){
					common = A[i].first;
					first = 1;
				}
				else if(A[i].first == B[j].second){
					first = 1;
					common = A[i].first;
				}
				else if((A[i].second == B[j].first)){
					second = 1;
					common = A[i].second;
				}
				else{
					second = 1;
					common = A[i].second;
				}
			}
		}
		COMMON[common] = 1;
		if((first && second))
			invalid  = 1;
		else if((first == 1 && second == 0) || (first == 0 && second == 1))
			valid = 1;
	}
	swap(A, B);
	for(int i=0; i<M; i++)
	{
		int first = 0; int second = 0;
		for(int j=0; j<N; j++)
		{
			if(((A[i].first == B[j].first) && (A[i].second != B[j].second)) || 
				((A[i].first == B[j].second) && (A[i].second != B[j].first)) || 
				((A[i].second == B[j].first) && (A[i].first != B[j].second)) ||
				((A[i].second == B[j].second) && (A[i].first != B[j].first)))
			{
				flag++;
				if(A[i].first == B[j].first){
					common = A[i].first;
					first = 1;
				}
				else if(A[i].first == B[j].second){
					first = 1;
					common = A[i].first;
				}
				else if((A[i].second == B[j].first)){
					second = 1;
					common = A[i].second;
				}
				else{
					second = 1;
					common = A[i].second;
				}
			}
		}
		COMMON[common] = 1;
		if((first && second))
			invalid  = 1;
		else if((first == 1 && second == 0) || (first == 0 && second == 1))
			valid = 1;
	}
	int cnt = 0;
	for(int i=0; i<10; i++)
		cnt += COMMON[i];
	
	if(invalid == 1 && valid == -1)
		cout<<"-1\n";
	else if(invalid == 1 && valid == 1)
		cout<<"-1\n";
	else if(cnt == 1)
		cout<<common<<endl;
	else if(invalid == -1 && valid == 1 && flag == 1)
		cout<<common<<endl;
	else
		cout<<"0\n";
	return 0;
}