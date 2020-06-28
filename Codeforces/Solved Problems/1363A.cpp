#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, X;
        cin >> N >> X;
        int even = 0;
        int odd = 0;
        for(int i = 1; i <= N; ++i){
            int tmp;
            cin >> tmp;
            if((tmp % 2) == 0)
                even++;
            else
                odd++;
        }
        if(odd == 0){
            cout << "No\n";
            continue;
        }
        int e = 0;
        while(X >= 2 && even > 0){
            X--;
            e = 1;
            even--;
        }
        while(X >= 3 && odd >= 2){
            X -= 2;
            odd -= 2;
        }
        if((X == 1 && odd > 0) || (X == 2 && e == 1 && odd > 2))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}