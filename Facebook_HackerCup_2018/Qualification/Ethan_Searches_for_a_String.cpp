#include "bits/stdc++.h"
using namespace std;

string ans;

bool checker1(string A, string B)
{
	int L = B.size();
	int l = A.size();
	for(int i = 0; i <= L - l; i++)
	{
		int flag = 1;
		for(int j = 0; j < l; j++)
			if(A[j] != B[i + j])
				flag = 0;
		if(flag)return true;
	}
	return false;
}

bool checker2(string A, string B)
{
	int L = B.size();
	int l = A.size();
	int i = 0;
	int j = 0;
	while(i < l)
	{
		if(j >= L)return false;
		if(A[i] == B[j]){
			i++;
			j++;
			continue;
		}
		if(i == 0)
		{
			j++;
			continue;
		}
		i = 0;
	}
	return true;
}


bool checker3(string A)
{
	int L = A.size();
	if(L == 1)
		return true;
	for(int i = 1; i < L; i++)
	{
		if(A[i] == A[0])return false;
	}
	return true;
}

bool checker4(string A)
{
	int L = A.size();
	for(int i = 1; i < L; i++)
	{
		if(A[i] == A[0])
		{
			//Potential Start posn.
			string end = "";
			for(int j = i; j < L; j++)
				end = end + A[j];
			string start = "";
			int lim = L - i;
			for(int j = 0; j < lim; j++)
				start = start + A[j];
			if(start == end)continue;
			ans = "";
			for(int j = 0; j < i; j++)
				ans = ans + A[j];
			ans = ans + A;
			return false;
		}
	}
	return true;
}

int main()
{
	ifstream cin("ethan_searches_for_a_string.txt");
	ofstream cout("Ethan_Searches_for_a_String.out");
	int T;
	cin>>T;
	for(int i = 1; i <= T; i++){
		string A;
		string B;
		cin>>A;
		ans = "";
		if(checker3(A))
		{
			cout<<"Case #"<<i<<": "<<"Impossible"<<endl;
			continue;
		}
		if(checker4(A))
		{
			cout<<"Case #"<<i<<": "<<"Impossible"<<endl;
			continue;	
		}
		B = ans;
		cout<<"Case #"<<i<<": "<<B<<endl;
		assert(checker1(A, B) == true && checker2(A, B) == false);
	}
	return 0;
}