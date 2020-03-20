#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long N;
	cin >> N;
	if((N - 2) %3 != 0){
		cout << "1 1 "<<(N - 2)<<endl;
	}
	else{
		cout << "1 2 "<<(N - 3)<<endl;
	}
	return 0;
}