#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        long long int tmp;
        int res = 0;
        for(int i = 1; i <= 10; ++i)
        {
            for(int j = 1; j <= 10; ++j)
            {
                cin >> tmp;
                if(tmp <= 30)
                    res++;
            }
        }
        if(res >= 60)
            cout << "yes\n";
        else
            cout << "no\n";
    }    
    return 0;
}