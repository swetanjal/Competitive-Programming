/*
ID: swetanj2
LANG: C++
TASK: castle
*/
#include <bits/stdc++.h>
using namespace std;
int N,M,tmp;
int size=0;
int max_size=0;
int cnt=0;
int component[55][55];
int sizes[2500];
struct element{
    int x;
    int y;
};
vector <element> edges[55][55];
element k;
void dfs(int i1, int j1)
{
    cnt++;
    component[i1][j1]=size;
    int l=edges[i1][j1].size();
    for(int i=0; i<l; i++)
    {
        if(component[edges[i1][j1][i].x][edges[i1][j1][i].y]==-1)dfs(edges[i1][j1][i].x,edges[i1][j1][i].y);
    }
}
int main() {
	ifstream cin("castle.in");
	ofstream cout("castle.out");
	cin>>M>>N;
	for(int i=0; i<N; i++)
	{
	    for(int j=0; j<M; j++)
	    {
	        cin>>tmp;
	        if(tmp==0)
	        {
	            k.x=i-1; k.y=j; edges[i][j].push_back(k);
	            k.x=i+1; k.y=j; edges[i][j].push_back(k);
	            k.x=i; k.y=j-1; edges[i][j].push_back(k);
	            k.x=i; k.y=j+1; edges[i][j].push_back(k);
	        }
	        if(tmp==1)
	        {
	            k.x=i-1; k.y=j; edges[i][j].push_back(k);
	            k.x=i; k.y=j+1; edges[i][j].push_back(k);
	            k.x=i+1; k.y=j; edges[i][j].push_back(k);
	        }
	        else if(tmp==2)
	        {
	            k.x=i; k.y=j-1; edges[i][j].push_back(k);
	            k.x=i; k.y=j+1; edges[i][j].push_back(k);
	            k.x=i+1; k.y=j; edges[i][j].push_back(k);
	        }
	        else if(tmp==4)
	        {
	            k.x=i; k.y=j-1; edges[i][j].push_back(k);
	            k.x=i-1; k.y=j; edges[i][j].push_back(k);
	            k.x=i+1; k.y=j; edges[i][j].push_back(k);
	        }
	        else
	        if(tmp==8)
	        {
	            k.x=i; k.y=j-1; edges[i][j].push_back(k);
	            k.x=i-1; k.y=j; edges[i][j].push_back(k);
	            k.x=i; k.y=j+1; edges[i][j].push_back(k);
	        }
	        else if(tmp==3)
	        {
	            k.x=i; k.y=j+1; edges[i][j].push_back(k);
	            k.x=i+1; k.y=j; edges[i][j].push_back(k);
	        }
	        else if(tmp==5)
	        {
	            k.x=i-1; k.y=j; edges[i][j].push_back(k);
	            k.x=i+1; k.y=j; edges[i][j].push_back(k);
	        }
	        else if(tmp==9)
	        {
	            k.x=i-1; k.y=j; edges[i][j].push_back(k);
	            k.x=i; k.y=j+1; edges[i][j].push_back(k);
	        }
	        else if(tmp==6)
	        {
	            k.x=i; k.y=j-1; edges[i][j].push_back(k);
	            k.x=i+1; k.y=j; edges[i][j].push_back(k);
	        }
	        else if(tmp==10)
	        {
	            k.x=i; k.y=j+1; edges[i][j].push_back(k);
	            k.x=i; k.y=j-1; edges[i][j].push_back(k);
	        }
	        else if(tmp==12)
	        {
	            k.x=i; k.y=j-1; edges[i][j].push_back(k);
	            k.x=i-1; k.y=j; edges[i][j].push_back(k);
	        }
	        else if(tmp==7)
	        {
	            k.x=i+1; k.y=j; edges[i][j].push_back(k);
	        }
	        else if(tmp==11)
	        {
	            k.x=i; k.y=j+1; edges[i][j].push_back(k);
	        }
	        else if(tmp==13){k.x=i-1; k.y=j; edges[i][j].push_back(k);}
	        else {k.x=i; k.y=j-1; edges[i][j].push_back(k);}
	    }
	}
	for(int i=0; i<N; i++)
	for(int j=0; j<M; j++)component[i][j]=-1;
	for(int i=0; i<N; i++)
	{
	    for(int j=0; j<M; j++)
	    {
	        if(component[i][j]==-1)
	        {
	            cnt=0;
	            dfs(i,j);
	            sizes[size++]=cnt;
	            //size++;
	            if(cnt>max_size)max_size=cnt;
	            //cout<<cnt<<endl;
	        }
	    }
	}
	cout<<size<<endl<<max_size<<endl;
	max_size=0; char dir='I';
	int pos_x=-1; int pos_y=-1;
	for(int i=N-1; i>=0; i--)
	{
	    for(int j=0; j<M; j++)
	    {
	        //north
	        if(i>0){
	            if(component[i][j]!=component[i-1][j])
	            {
	                int tmp_size=sizes[component[i][j]]+sizes[component[i-1][j]];
	                if(tmp_size>max_size)
	                {
	                    max_size=tmp_size;
	                    pos_x=i; pos_y=j; dir='N';
	                }
	                if(tmp_size==max_size)
	                {
	                    if(j<pos_y)
	                    {
	                        max_size=tmp_size;
	                        pos_x=i; pos_y=j; dir='N';
	                    }
	                    else if((j==pos_y)&&(dir!='N'))
	                    {
	                        max_size=tmp_size;
	                        pos_x=i; pos_y=j; dir='N';
	                    }
	                }
	            }
	        }
	        //east
	        if(j<M-1){
	            if(component[i][j]!=component[i][j+1])
	            {
	                int tmp_size=sizes[component[i][j]]+sizes[component[i][j+1]];
	                if(tmp_size>max_size)
	                {
	                    max_size=tmp_size;
	                    pos_x=i; pos_y=j; dir='E';
	                }
	                if(tmp_size==max_size)
	                {
	                    if(j<pos_y)
	                    {
	                        max_size=tmp_size;
	                        pos_x=i; pos_y=j; dir='E';
	                    }
	                }
	            }
	        }
	    }
	}
	cout<<max_size<<endl<<(pos_x+1)<<" "<<(pos_y+1)<<" "<<dir<<endl;
	return 0;
}
