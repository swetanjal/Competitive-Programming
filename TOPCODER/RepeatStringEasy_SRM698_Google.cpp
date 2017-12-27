#include <bits/stdc++.h>
using namespace std;
int N;
string S;
int rec(int i, int j)
{
	if(i>j)return 0;
	if(S[i]==S[j]){
		return rec(i+1,j-1);
	}
	return 1+rec(i+1,j);
}
class ThePalindrome{
public:
int find(string lol)
{
	S=lol;
	N=S.size();
	return (N+rec(0,N-1));
}
};
