#include <bits/stdc++.h>
using namespace std;
struct element{
	int X;
	int Y;
	int ind;
};
int N;
element A[50005];
element B[50005];
bool compareY(element a, element b)
{
	return a.Y<b.Y;
}
bool compareX(element a, element b)
{
	return a.X<b.X;
}
int main()
{
	ifstream cin("reduce.in"); ofstream cout("reduce.out");
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>A[i].X>>A[i].Y;
		A[i].ind=i;
		B[i].X=A[i].X; B[i].Y=A[i].Y;
		B[i].ind=i;
	}
	sort(A,A+N,compareX); sort(B,B+N,compareY);
	int ret=INT_MAX;
	//Lets take leftmost X coordinate and remove it.
	if(A[0].ind==B[0].ind)ret=min(ret,(A[N-1].X-A[1].X)*(B[N-1].Y-B[1].Y));
	else if(A[0].ind==B[N-1].ind)ret=min(ret,(A[N-1].X-A[1].X)*(B[N-2].Y-B[0].Y));
	else ret=min(ret,(A[N-1].X-A[1].X)*(B[N-1].Y-B[0].Y));
	//Lets take the righmost C coordinate
	if(A[N-1].ind==B[0].ind)ret=min(ret,(A[N-2].X-A[0].X)*(B[N-1].Y-B[1].Y));
	else if(A[N-1].ind==B[N-1].ind)ret=min(ret,(A[N-2].X-A[0].X)*(B[N-2].Y-B[0].Y));
	else ret=min(ret,(A[N-2].X-A[0].X)*(B[N-1].Y-B[0].Y));
	if(B[0].ind==A[0].ind)ret=min(ret,(A[N-1].X-A[1].X)*(B[N-1].Y-B[1].Y));
	else if(B[0].ind==A[N-1].ind)ret=min(ret,(A[N-2].X-A[0].X)*(B[N-1].Y-B[1].Y));
	else ret=min(ret,(A[N-1].X-A[0].X)*(B[N-1].Y-B[0].Y));
	
	if(B[N-1].ind==A[0].ind)ret=min(ret,(A[N-1].X-A[1].X)*(B[N-2].Y-B[0].Y));
	else if(B[N-1].ind==A[N-1].ind)ret=min(ret,(A[N-2].X-A[0].X)*(B[N-2].Y-B[0].Y));
	else ret=min(ret,(A[N-1].X-A[0].X)*(B[N-2].Y-B[0].Y));
	cout<<ret<<endl;
	return 0;
}
