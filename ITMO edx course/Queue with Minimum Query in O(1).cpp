#include <bits/stdc++.h>
using namespace std;
int T;
char key;
long long N;
int main()
{
	ifstream cin("queuemin.in");
	ofstream cout("queuemin.out");
	cin>>T;
	stack <long long> inbox;
	stack <long long> outbox;
	stack <long long> outbox_min;
	stack <long long> inbox_min;
	inbox_min.push(100000000000000);
	outbox_min.push(100000000000000);
	for(int i=0; i<T; i++)
	{
		cin>>key;
		if(key=='+'){
			cin>>N;
			inbox.push(N);
			inbox_min.push(min(inbox.top(),inbox_min.top()));
		}
		else
		if(key=='?'){
			/*if(outbox.empty())
			{
				while(inbox.empty()==false)
				{
					outbox_min.push(min(outbox_min.top(),inbox.top()));
					outbox.push(inbox.top()); 
					inbox.pop();
				}
			}*/
			cout<<min(inbox_min.top(),outbox_min.top())<<"\n";
			//outbox_min.pop();
			//outbox.pop();
		}
		else
		{
			if(outbox.empty())
			{
				while(inbox.empty()==false)
				{
					outbox_min.push(min(outbox_min.top(),inbox.top()));
					outbox.push(inbox.top()); 
					inbox.pop();
					inbox_min.pop();
				}
			}
			outbox.pop(); outbox_min.pop();
		}
	}
	return 0;
}
