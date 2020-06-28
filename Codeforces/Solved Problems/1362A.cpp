#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long int A, B;
        cin >> A >> B;

        if((A % B) == 0){
            long long int tmp = A / B;
            long long int res = 0;
            while((tmp % 8) == 0){
                tmp /= 8;
                res++;
            }
            while((tmp % 4) == 0){
                tmp /= 4;
                res++;
            }
            while((tmp % 2) == 0){
                tmp /= 2;
                res++;
            }
            if(tmp == 1)
            cout << res << endl;
            else
            cout << "-1\n";
        }

        else if((B % A) == 0){
            long long int tmp = B / A;
            long long int res = 0;
            while((tmp % 8) == 0){
                tmp /= 8;
                res++;
            }
            while((tmp % 4) == 0){
                tmp /= 4;
                res++;
            }
            while((tmp % 2) == 0){
                tmp /= 2;
                res++;
            }
            if(tmp == 1)
            cout << res << endl;
            else
            cout << "-1\n";
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}