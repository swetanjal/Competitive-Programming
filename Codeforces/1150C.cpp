#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    int one = 0;;
    int two = 0;
    for(int i = 1; i <= N; ++i)
    {
        int a;
        cin >> a;
        if(a == 1)
            one++;
        else
            two++;
    }
    if(one == 0){
        for(int i = 1; i <= two; ++i)
            cout << "2 ";
        cout << endl;
        return 0;
    }
    if(two == 0){
        for(int i = 1; i <= one; ++i)
            cout << "1 ";
        cout << endl;
        return 0;
    }
    cout << "2 1 ";
    for(int i = 1; i < two; ++i)
        cout << "2 ";
    for(int i = 1; i < one; ++i)
        cout << "1 ";
    cout << endl;
    return 0;
}