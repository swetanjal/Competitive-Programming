#include "bits/stdc++.h"
using namespace std;
    
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long a, b;
        cin >> a >> b;
        if(a > b)
            swap(a, b);    
        for(long long int i = 0; ; ++i){
            a += i;
            if(a >= b)
            {
                long long diff = a - b;
                if((diff%2) == 0)
                    cout << i << endl;
                else if((i % 2) == 0)
                    cout << (i + 1) << endl;
                else if((i % 2) != 0)
                    cout << (i + 2) << endl;
                else
                    assert(false);
                break;
            }
        }
    }
    return 0;
}