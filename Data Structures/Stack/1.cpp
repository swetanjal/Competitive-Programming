/*
Concept involved:
Next Greater and Next Lesser in O(N)
Previous Lesser and Previous Greater of each element in O(N).
Refer: http://www.geeksforgeeks.org/next-greater-element/
to get an idea of next greater. The concept can be extended to solve the others.
Problem: http://codeforces.com/problemset/problem/817/D
*/ 
#include <bits/stdc++.h>
using namespace std;
int N;
long long A[1000005];
int  next_greater[1000005],prev_greater[1000005];
int next_lesser[1000005], prev_lesser[1000005];
int main()
{
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>A[i];
	}
	/*************************************************************/
	for(int i=0; i<N; i++)next_greater[i]=N-1;
	for(int i=0; i<N; i++)prev_greater[i]=0;
	stack <int> S;
	S.push(0);
	for(int i=1; i<N; i++)
	{
		int next = A[i];
		while(S.empty()==false && A[S.top()]<next){
			next_greater[S.top()] = i-1;
			S.pop();
		}
		S.push(i);
	}
	stack <int> P;
	P.push(N-1);
	for(int i=(N-2); i>=0; i--){
		int prev = A[i];
		while(P.empty()==false && A[P.top()]<=prev){
			prev_greater[P.top()] = i+1;
			P.pop();
		}
		P.push(i);
	}
	long long maximum_sum = 0;
	for(int i=0; i<N; i++){
		maximum_sum+=((next_greater[i]-i+1)*1LL*(i-prev_greater[i]+1)*A[i]);
	}
	/******************************************************************/
	for(int i=0; i<N; i++)next_lesser[i]=N-1;
	for(int i=0; i<N; i++)prev_lesser[i]=0;
	stack <int> X;
	X.push(0);
	for(int i=1; i<N; i++)
	{
		int next = A[i];
		while(X.empty()==false && A[X.top()]>next){
			next_lesser[X.top()] = i-1;
			X.pop();
		}
		X.push(i);
	}
	stack <int> Y;
	Y.push(N-1);
	for(int i=(N-2); i>=0; i--){
		int prev = A[i];
		while(Y.empty()==false && A[Y.top()]>=prev){
			prev_lesser[Y.top()] = i+1;
			Y.pop();
		}
		Y.push(i);
	}
	long long minimum_sum = 0;
	for(int i=0; i<N; i++){
		minimum_sum+=((next_lesser[i]-i+1)*1LL*(i-prev_lesser[i]+1)*A[i]);
	}
	cout<<(maximum_sum-minimum_sum)<<endl;
	return 0;
}
