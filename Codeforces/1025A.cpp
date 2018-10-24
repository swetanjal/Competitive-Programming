#include "bits/stdc++.h"
using namespace std;
int A[26];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int L;
	cin >> L;
	for(int i = 0; i < L; i++){
		char x;
		cin >> x;
		A[x - 'a']++;
	}
	int flag = 0;
	if(L == 1){
		cout << "Yes\n";
		return 0;
	}
	for(int i = 0; i < 26; i++){
		if(A[i] > 1)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}