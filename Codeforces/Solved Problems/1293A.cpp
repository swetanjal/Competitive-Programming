    #include "bits/stdc++.h"
    using namespace std;
     
    int main()
    {
        int T;
        cin >> T;
        while(T--)
        {
            int N, K, S;
            cin >> N >> S >> K;
            map < int, int> H;
            for(int i = 1; i <= K; ++i){
                int tmp;
                cin >> tmp;
                H[tmp] = 0;
            }
            int res = 10000000;
            for(int i = S; i <= N; ++i){
                if(H.find(i) != H.end()){
                    continue;
                }
                else{
                    res = min(res, abs(S - i));
                    break;
                }
            }
            for(int i = S; i >= 1; --i){
                if(H.find(i) != H.end()){
                    continue;
                }
                else{
                    res = min(res, abs(S - i));
                    break;
                }
            }
            cout << res << endl;
        }
        return 0;
    }