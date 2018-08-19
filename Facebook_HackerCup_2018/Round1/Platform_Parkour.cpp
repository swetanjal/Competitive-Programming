#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;
const int MAXN = 200000;
const int MAXM = 20;
long double H[MAXN];
long double UP[MAXN];
long double DOWN[MAXN];
int N, M;

bool check_intersect(long double l1, long double r1, long double l2, long double r2)
{
	if(l1 <= l2 && r2 <= r1)
		return true;
	if(l2 > r1 || r2 < l1)
	return false;
	return true;
}

bool check(long double X)
{
	long double L = H[0] - X;
	long double R = H[0] + X;
	for(int i = 0; i < (N - 1); i++){
		L -= DOWN[i];
		R += UP[i];
		if(!check_intersect(L, R, H[i + 1] - X, H[i + 1] + X))
			return false;
		L = max(L, H[i + 1] - X);
		R = min(R, H[i + 1] + X);
	}
	return true;
}

int main()
{
	ifstream cin("platform_parkour.txt");
	ofstream cout("platform_parkour_sample_input.out");
	int t;
	cin>>t;
	for(int T = 1; T <= t; T++){
		cin>>N>>M;
		long long W, X, Y, Z;
		cin>>H[0]>>H[1]>>W>>X>>Y>>Z;
		for(int i = 2; i < N; i++)
			H[i] = ((long long)(W * H[i-2]) % Z + (long long)(X * H[i-1]) % Z + Y) % Z;
		int A, B;
		long double U, D;
		for(int i = 0; i < N; i++)
			UP[i] = INF, DOWN[i] = INF;
		for(int i = 1; i <= M; i++){
			cin>>A>>B>>U>>D;
			A--;
			B--;
			if(B < A)
				swap(A, B), swap(U, D);
			for(int j = A; j < B; j++)
				UP[j] = min(UP[j], U), DOWN[j] = min(DOWN[j], D);
		} 
		//cout<<check(483009.500000)<<endl;	
		//cout<<UP[0]<<" "<<DOWN[0]<<endl;
		long double low = 0.0; long double high = 1e9; long double mid;
		long double ans = -1;
		for(int i = 1; i <= 100; i++)
        {
            mid = (high + low)/2;
            if(check(mid)){
            	ans = mid;
                high = mid;
            }
            else
                low = mid;
        }
        cout<<"Case #"<<T<<": "<<fixed<<setprecision(8)<<ans<<endl;
        //printf("Case #%d: %.8Lf\n", T, ans);
		//cout<<low<<endl;
	}
	return 0;
}