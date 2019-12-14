#include "bits/stdc++.h"
using namespace std;

bool chk(int fl, int g, int s, int b)
{
    if(fl == 0)
        return true;
    if(fl == 1)
    {
        if(g < s)
            return true;
        return false;
    }
    if(s < b)
        return true;
    return false;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        long long A[N];
        for(int i = 0; i < N; ++i)
            cin >> A[i];
        int gold = 1;
        int silver = 0;
        int bronze = 0;
        int flag = 0;
        int idx = -1;
        for(int i = (N / 2) - 1; i >= 0; --i){
            if(A[i] != A[i + 1]){
                idx = i;
                break;
            }
        }
        for(int i = 1; i <= idx; ++i)
        {
            if(A[i] < A[i - 1] && chk(flag, gold, silver, bronze))
            {
                flag++;
            }
            if(flag == 0)
                gold++;
            else if(flag == 1)
                silver++;
            else
                bronze++;
        }
        //cout << gold << " " << silver << " " << bronze << endl;
        if(gold!=0 && silver!=0 && bronze!=0 && bronze > gold)
            cout << gold << " " << silver << " " << bronze << endl;
        else
            cout << "0 0 0" << endl;
    }
    return 0;
}