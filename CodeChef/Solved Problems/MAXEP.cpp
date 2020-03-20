#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, C;
    cin >> N >> C;
    int st = 1;
    for(int i = 1; i <= N; i += 400){
        cout << 1 << " " << i << endl;
        int tmp;
        cin >> tmp;
        if(tmp == 1){
            cout << "2" << endl;
            break;
        }
        else
            st = i;
    }
    for(int i = st; i <= (st + 400) && i <= N; ++i)
    {
        cout << 1 << " " << i << endl;
        int tmp;
        cin >> tmp;
        if(tmp == 1){
            cout << 3 << " " << i << endl;
            break;
        }
    }
    return 0;
}