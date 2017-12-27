/*
ID: swetanj2
LANG: C++
TASK: preface
*/
#include <bits/stdc++.h>
using namespace std;
struct element{
	int I;
	int V;
	int X;
	int L;
	int C;
	int D;
	int M;
};
element thousands[4];
element hundreds[10];
element tens[10];
element units[10];
int main()
{
	ifstream cin("preface.in");
	ofstream cout("preface.out");
	for(int i=0; i<4; i++){
		thousands[i].I=0;
		thousands[i].V=0;
		thousands[i].X=0;
		thousands[i].L=0;
		thousands[i].C=0;
		thousands[i].D=0;
		thousands[i].M=0;
	}
	thousands[1].M=1;
	thousands[2].M=2;
	thousands[3].M=3;
	for(int i=0; i<10; i++){
		hundreds[i].I=0;
		hundreds[i].V=0;
		hundreds[i].X=0;
		hundreds[i].L=0;
		hundreds[i].C=0;
		hundreds[i].D=0;
		hundreds[i].M=0;
	}
	hundreds[1].C=1;
	hundreds[2].C=2;
	hundreds[3].C=3;
	hundreds[4].D=1; hundreds[4].C=1;
	hundreds[5].D=1;
	hundreds[6].D=1; hundreds[6].C=1;
	hundreds[7].D=1; hundreds[7].C=2;
	hundreds[8].D=1; hundreds[8].C=3;
	hundreds[9].M=1; hundreds[9].C=1;
	for(int i=0; i<10; i++){
		tens[i].I=0;
		tens[i].V=0;
		tens[i].X=0;
		tens[i].L=0;
		tens[i].C=0;
		tens[i].D=0;
		tens[i].M=0;
	}
	tens[1].X=1;
	tens[2].X=2;
	tens[3].X=3;
	tens[4].L=1; tens[4].X=1;
	tens[5].L=1;
	tens[6].L=1; tens[6].X=1;
	tens[7].L=1; tens[7].X=2;
	tens[8].L=1; tens[8].X=3;
	tens[9].C=1; tens[9].X=1;
	for(int i=0; i<10; i++){
		units[i].I=0;
		units[i].V=0;
		units[i].X=0;
		units[i].L=0;
		units[i].C=0;
		units[i].D=0;
		units[i].M=0;
	}
	units[1].I=1;
	units[2].I=2;
	units[3].I=3;
	units[4].V=1; units[4].I=1;
	units[5].V=1;
	units[6].V=1; units[6].I=1;
	units[7].V=1; units[7].I=2;
	units[8].V=1; units[8].I=3;
	units[9].X=1; units[9].I=1;
	int N;
	cin>>N;
	element ans;
	ans.I=0;
	ans.V=0;
	ans.X=0;
	ans.L=0;
	ans.C=0;
	ans.D=0;
	ans.M=0;
	for(int i=1; i<=N; i++)
	{
		ans.I=ans.I+thousands[i/1000].I+hundreds[(i%1000)/100].I+tens[(i%1000)%100/10].I+units[i%10].I;
		ans.V=ans.V+thousands[i/1000].V+hundreds[(i%1000)/100].V+tens[(i%1000)%100/10].V+units[i%10].V;
		ans.X=ans.X+thousands[i/1000].X+hundreds[(i%1000)/100].X+tens[(i%1000)%100/10].X+units[i%10].X;
		ans.L=ans.L+thousands[i/1000].L+hundreds[(i%1000)/100].L+tens[(i%1000)%100/10].L+units[i%10].L;
		ans.C=ans.C+thousands[i/1000].C+hundreds[(i%1000)/100].C+tens[(i%1000)%100/10].C+units[i%10].C;
		ans.D=ans.D+thousands[i/1000].D+hundreds[(i%1000)/100].D+tens[(i%1000)%100/10].D+units[i%10].D;
		ans.M=ans.M+thousands[i/1000].M+hundreds[(i%1000)/100].M+tens[(i%1000)%100/10].M+units[i%10].M;
	}
	if(ans.I!=0)
	cout<<"I "<<ans.I<<endl;
	if(ans.V!=0)
	cout<<"V "<<ans.V<<endl;
	if(ans.X!=0)
	cout<<"X "<<ans.X<<endl;
	if(ans.L!=0)
	cout<<"L "<<ans.L<<endl;
	if(ans.C!=0)
	cout<<"C "<<ans.C<<endl;
	if(ans.D!=0)
	cout<<"D "<<ans.D<<endl;
	if(ans.M!=0)
	cout<<"M "<<ans.M<<endl;
	return 0;
}
