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
        long long Xor = 0;
        long long sum = 0;

        long long SUM = 0;
        long long XOR = 0;
        for(int i = 0; i < N; ++i){
            long long tmp;
            cin >> tmp;
            Xor = Xor ^ tmp;
            sum += tmp;
            SUM += tmp;
            XOR = XOR ^ tmp;
        }
        Xor = Xor ^ (1LL << 50);
        sum = (sum + (1LL << 50));
        
        long long diff = (2 * Xor) - sum;
        cout << 3 << endl;
        if((diff % 2) == 0){
            cout << (1LL << 50) << endl;
            SUM += (1LL << 50);
            XOR = XOR ^ (1LL << 50);
        }
        else{
            // cout << "1\n";
            Xor = Xor ^ (1LL << 50);
            Xor = Xor ^ ((1LL << 50) + 1);
            sum += 1;
            diff = (2 * Xor) - sum;
            cout << ((1LL << 50) + 1) << endl;

            SUM = SUM + (((1LL << 50) + 1));
            XOR = XOR ^ (((1LL << 50) + 1));
        }
        assert((diff % 2) == 0);
        cout << (diff / 2) << endl;
        cout << (diff / 2) << endl;

        SUM += diff;
        XOR = XOR ^ (diff / 2);
        XOR = XOR ^ (diff / 2);

        assert(SUM == (2 * XOR));
    }
    return 0;
}