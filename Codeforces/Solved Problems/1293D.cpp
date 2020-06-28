    #include "bits/stdc++.h"
    using namespace std;
     
    int main()
    {
        long long int x0, y0, ax, ay, bx, by, xs, ys, t;
        cin >> x0 >> y0 >> ax >> ay >> bx >> by;
        cin >> xs >> ys >> t;
        vector <long long> X;
        vector <long long> Y;
        X.push_back(x0);
        Y.push_back(y0);
        while(X[X.size() - 1] < 10000000000000000 && Y[Y.size() - 1] < 10000000000000000)
        {
            X.push_back(ax * X[X.size() - 1] + bx);
            Y.push_back(ay * Y[Y.size() - 1] + by);
        }
        int ANS = 0;
        int l = X.size();
        for(int idx = 0; idx < l; ++idx){
            long long total_time = 0;
            long long prevx = xs; long long prevy = ys;
            int res = 0;
            for(int i = idx; i >= 0; --i){
                if(abs(prevx - X[i]) + abs(prevy - Y[i]) + total_time <= t){
                    total_time = abs(prevx - X[i]) + abs(prevy - Y[i]) + total_time;
                    res++;
                    prevx = X[i]; prevy = Y[i];
                }
                else{
                    break;
                }
            }
            for(int i = idx + 1; i < l; ++i){
                if(abs(prevx - X[i]) + abs(prevy - Y[i]) + total_time <= t){
                    total_time = abs(prevx - X[i]) + abs(prevy - Y[i]) + total_time;
                    res++;
                    prevx = X[i]; prevy = Y[i];
                }
                else{
                    break;
                }
            }
            ANS = max(ANS, res);
        }
        cout << ANS << endl;
        return 0;
    }