#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long N;
    cin >> N;   
    if(N == 1){
        cout << "1\n";
        return 0;
    }
    if(N == 2){
        cout << "1\n";
        return 0;
    }
    if(N == 3){
        cout << "0\n";
        return 0;
    }
    int res = 0;
    if((N % 2) != 0)
        res += 1;
    if((N / 2) % 2 != 0)
        res += 1;
    if(res == 2)
        res = 0;
    cout << res << endl;
    return 0;
}
