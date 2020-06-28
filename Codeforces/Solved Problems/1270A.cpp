#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, A, B;
        cin >> N >> A >> B;
        int flag = 0;
        for(int i = 1; i <= A; ++i){
            int tmp;
            cin >> tmp;
            if(tmp == N)
                flag = 1;
        }
        for(int i = 1; i <= B; ++i){
            int tmp;
            cin >> tmp;
            if(tmp == N)
                flag = 0;
        }
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}