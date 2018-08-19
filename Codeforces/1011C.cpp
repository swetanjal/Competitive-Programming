#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1005;

int N;
long double M;
long double A[MAXN];
long double B[MAXN];

bool chk(long double fuel)
{

	for(int i = 0; i < N; i++){
		if(i == (N - 1)){
			long double wt = fuel + M;
			long double burn_takeoff = wt / A[i];
			fuel = fuel - burn_takeoff;
			if(fuel <= 0)break;
			wt = fuel + M;
			long double burn_land = wt / B[0];
			fuel = fuel - burn_land;
			if(fuel < 0)
				break;
			break;
		}
		long double wt = fuel + M;
		long double burn_takeoff = wt / A[i];
		fuel = fuel - burn_takeoff;
		if(fuel <= 0)break;
		wt = fuel + M;
		long double burn_land = wt / B[i + 1];
		fuel = fuel - burn_land;
		if(fuel <= 0)
			break;
	}
	if(fuel >= 0)
		return true;
	return false;
}

int main()
{
	cin>>N;
	cin>>M;
	for(int i = 0; i < N; i++)
		cin>>A[i];
	for(int i = 0; i < N; i++)
		cin>>B[i];
	long double low = 0.0; long double high = 1e18; long double mid;
	long double ans = -1;
	for(int i = 1; i <= 100; i++)
	{
		mid = (high + low)/2.0;
		if(chk(mid))
		{
			high = mid;
			ans = mid;
		}
		else
			low = mid;
	}
	if(ans == -1)
		cout<<"-1\n";
	else
		cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}