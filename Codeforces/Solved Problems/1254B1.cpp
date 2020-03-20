#include "bits/stdc++.h"
using namespace std;
//#define INT_MAX 1000000000
long long int compute(vector <long long int> S)
{
    long long int res = 100000000000000000;
    int l = S.size();


    long long int cum[l];
    cum[l - 1] = S[l - 1];
    for(int i = l - 2; i >= 0; --i)
        cum[i] = S[i] + cum[i + 1];
    long long int sum = 0;
    for(int i = 0; i < l; ++i){
        sum += S[i];

        long long int tmp = ((S[i] * 1LL * (i + 1)) - sum) + ((cum[i] - S[i]) - ((l - i - 1) * 1LL * S[i]));
        res = min(res, tmp);
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector <long long int> A;
    long long int count = 0;
    for(int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;
        if(tmp){
            A.push_back(i);
            count += 1;
        }
    }
    long long int rest = 1000000000000000000;
    for(long long int i = 1; (i * i) <= count; ++i){
        if((count % i) == 0){
            int p1 = i;
            int l = A.size();
            long long int ans = 0;
            for(int i = p1 - 1; i < l; i += p1)
            {
                vector <long long int> v;
                for(int j = i; j >= i - p1 + 1; --j)
                    v.push_back(A[j]);
                reverse(v.begin(), v.end());
                long long int res = compute(v);
                ans = ans + res;
            }
            if(p1 != 1)
                rest = min(rest, ans);
            p1 = count / i;
            ans = 0;
            for(int i = p1 - 1; i < l; i += p1)
            {
                vector <long long int> v;
                for(int j = i; j >= i - p1 + 1; --j)
                    v.push_back(A[j]);
                reverse(v.begin(), v.end());
                long long int res = compute(v);
                ans = ans + res;
            }
            if(p1 != 1)
                rest = min(rest, ans);
        }
    }
    if(rest == 1000000000000000000)
        cout << "-1\n";
    else
        cout << rest << endl;
    return 0;
}