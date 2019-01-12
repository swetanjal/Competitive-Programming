#include "bits/stdc++.h"
using namespace std;
int x, y;
int small = 0;
int big = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q;
    cin >> Q;
    while(Q--)
    {
        char ch;
        cin >> ch;
        if(ch == '+'){
            
            cin >> x >> y;
            if(x < y){
                small = max(small, x);
                big = max(big, y);
            }
            else{
                small = max(small, y);
                big = max(big, x);
            }
        }
        else{
            cin >> x >> y;
            //cout << big << " " << small << endl;
            if(x < y)
                swap(x, y);
            if(x >= big && y >= small)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}