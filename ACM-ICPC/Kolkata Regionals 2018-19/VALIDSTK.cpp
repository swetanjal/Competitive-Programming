#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        int fl = 0;
        int valid = 1;
        for(int i = 0; i < N; ++i){
            int tmp;
            cin >> tmp;
            if(tmp)
                fl++;
            
            else
                fl--;
            if(fl < 0)
            {
                valid = 0;
            }
        }
        if(valid)
            cout << "Valid\n";
        else
            cout << "Invalid\n";
    }
    return 0;
}