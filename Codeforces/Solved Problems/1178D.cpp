#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e6 + 5;
int N;

int isPrime[MAXN];
vector <int> u;
vector <int> v;
int main()
{
    for(int i = 0; i < MAXN; ++i)
        isPrime[i] = 1;
    for(int i = 2; i < MAXN; ++i){
        if(isPrime[i] == 1){
            for(int j = i + i; j < MAXN; j += i)
                isPrime[j] = 0;
        }
    }
    cin >> N;
    for(int i = 1; i <= N; ++i)
    {
        if(i == N)
            u.push_back(i), v.push_back(1);
        else
            u.push_back(i), v.push_back(i + 1);
    }
    int edges = N;
    int lst = 1;
    while(isPrime[edges] == 0){
        edges++;
        u.push_back(lst), v.push_back(lst + (N / 2));
        lst++;
    }
    cout << u.size() << endl;
    for(int i = 0; i < u.size(); ++i)
        cout << u[i] << " " << v[i] << endl;
    return 0;
}