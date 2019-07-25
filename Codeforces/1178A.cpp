#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long s = 0;
    long long a;
    cin >> a;
    s += a;
    long long c = a;
    vector <int> v;
    v.push_back(1);
    for(int i = 2; i <= N; ++i){
        long long tmp;
        cin >> tmp;
        s += tmp;
        if((a / 2) >= tmp){
            c += tmp;
            v.push_back(i);
        }
    }
    if(((s / 2) + 1) <= c)
    {
        cout << v.size() << endl;
        for(int i = 0; i < v.size(); ++i)
            cout << v[i] << " ";
        cout << endl;
    }
    else
        cout << 0 << endl;
    return 0;
}