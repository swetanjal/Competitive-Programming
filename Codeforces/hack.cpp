#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main()
{
	ofstream cout("x.out");
    int last = 1;
    int cur = 2;
    int cnt = 0;
    cout << "3498 4660 3497\n";
    while(cur + 3 < 3500){
        cout << cur << " " << last << "\n";
        cout << cur + 1<< " " << last << "\n";
        cout << cur + 2 << " " << cur<<"\n";
        cout << cur + 2 << " " << cur + 1 << "\n";
        last = cur + 2;
        cnt += 4;
        cur += 3;
    }
	return 0;
}
