#include "bits/stdc++.h"
using namespace std;
const int MAXN = 55;
char A[MAXN];
char B[MAXN];
int N;
int main()
{
	cin>>N;
	for(int i = 0; i < N; i++)
		cin>>A[i];
	for(int i = 0; i < N; i++)
		cin>>B[i];
	int freq1[26];
	int freq2[26];
	for(int i = 0; i < 26; i++){
		freq1[i] = 0;
		freq2[i] = 0;
	}
	for(int i = 0; i< N; i++){
		freq1[A[i] - 'a']++;
		freq2[B[i] - 'a']++;
	}
	int flag = 1;
	for(int i = 0; i <26; i++)
	{
		if(freq1[i] != freq2[i]){
			flag = 0;
			break;
		}
	}
	if(flag == 0){
		cout<<"-1\n";
		return 0;
	}
	int ans = 0;
	vector <int> res;
	for(int i = 0; i < N; i++){
		if(A[i] == B[i])continue;
		int cnt = 0;
		for(int j = i + 1; j < N; j++){
			if(A[j] == B[i]){
				//Keep swapping this
				for(int k = j; k > i; k--){
					res.push_back(k);
					swap(A[k], A[k - 1]);
					ans++;
				}
				break;
			}
		}
	}
	cout<<ans<<endl;
	for(int i = 0; i < ans; i++)
		cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}