#include "bits/stdc++.h"
using namespace std;

struct element{
	int id; //id = 0 means dish id =1 means clan
	long long x; //Position
	long long dish_p; // People eating dish
	long long clan_q; //Number of people that needs to approach it
	long long clan_r;//Number of tribal people joining chef.
};

int T, B, C;
long long X;
vector <element> A;

bool solve(long long G)
{
	int L = A.size();
	int dead = 0;
	for(int i=0; i<L; i++){
		if(A[i].id == 0)
		{
			//Dish
			if(A[i].dish_p < G)
				G -= A[i].dish_p;
			else{
				dead = 1;
				G = 0;
				break;
			}
		}
		else
		{
			//Clan
			if(G >= A[i].clan_q)
				G += A[i].clan_r;
		}
	}
	if(dead == 1)
		return false;
	if(G > 0)
		return true;
	return false;
}

bool cmp(element a, element b)
{
	return a.x<b.x;	
}

int main()
{
	cin>>T;
	while(T--)
	{
		A.clear();
		cin>>X;
		cin>>B;
		for(int i=0; i<B; i++){
			element tmp;
			cin>>tmp.x>>tmp.dish_p;
			tmp.id = 0;
			A.push_back(tmp);
		}
		cin>>C;
		for(int i=0; i<C; i++){
			element tmp;
			tmp.id = 1;
			cin>>tmp.x>>tmp.clan_q>>tmp.clan_r;
			A.push_back(tmp);
		}
		sort(A.begin(), A.end(), cmp);
		long long low = 1; long long high = 1000000000000000001;
		long long mid; long long ans = -1;
		while(high>=low)
		{
			mid = (high + low)/2;
			if(solve(mid))
			{
				ans = mid;
				high = mid -1;
			}
			else
				low = mid + 1;
		}
		cout<< ans << endl;
	}
	return 0;
}