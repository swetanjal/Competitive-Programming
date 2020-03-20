/*
ID: swetanj2
LANG: C++
TASK: ttwo
*/
#include <bits/stdc++.h>
using namespace std;
char G[10][10];
struct move{
	int h;
	int v;
};
struct pos{
	int x;
	int y;
};
pos farmer;
pos cow;
pos f;
pos c;
bool equals(pos A, pos B)
{
	if(A.x==B.x && A.y==B.y)return true;
	return false;
}
bool valid(pos S, pos N)
{
	S.x+=N.x;
	S.y+=N.y;
	if(S.x<0 || S.x>9 || S.y<0 || S.y>9)return false;
	if(G[S.x][S.y]=='*')return false;
	return true;
}
pos rotate(pos lol)
{
	pos ret;
	if(lol.x==-1){
		ret.x=0;
		ret.y=1;
	}
	if(lol.x==1)
	{
		ret.x=0;
		ret.y=-1;
	}
	if(lol.y==-1){
		ret.x=-1;
		ret.y=0;
	}
	if(lol.y==1)
	{
		ret.x=1;
		ret.y=0;
	}
	return ret;
}
int main()
{
	ifstream cin("ttwo.in");
	ofstream cout("ttwo.out");
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			cin>>G[i][j];
			if(G[i][j]=='F'){
				farmer.x=i;
				farmer.y=j;		
			}
			else if(G[i][j]=='C'){
				cow.x=i;
				cow.y=j;
			}
		}
	}
	f.x=-1; f.y=0; c.x=-1; c.y=0;
	for(int i=1; i<=10000; i++)
	{
		if(equals(farmer,cow)){
			cout<<(i-1)<<endl;
			return 0;
		}
		//try moving the farmer
		if(valid(farmer,f))
		{
			farmer.x=farmer.x+f.x;
			farmer.y=farmer.y+f.y;
		}
		else
		{
			f=rotate(f);
		}
		//try moving the cows
		if(valid(cow,c))
		{
			cow.x=cow.x+c.x;
			cow.y=cow.y+c.y;
		}
		else
		{
			c=rotate(c);
		}
	}
	cout<<"0"<<endl;
	return 0;
}
