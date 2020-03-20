#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int copy = N;
    string ans = "";
    while(copy > 0){
        if((copy % 2))
        ans = "1" + ans;
        else
        ans = "0" + ans;
        copy /= 2;
    }
    int cnt = 0;
    for(int i = 0; i < ans.size(); ++i)
    {
        if(ans[i] == '1')
            cnt++;
    }
    if(cnt > K || N < K){
        cout << "NO\n";
        return 0;
    }
    priority_queue <long long int> A;
    int req = K - cnt;
    int res = ans.size() - 1;
    long long int power[33];
    power[0] = 1;
    for(int i = 1; i <= 32; ++i)
        power[i] = power[i - 1] * 2;
    for(int i = 0; i < ans.size(); ++i){
        if(ans[i] == '1')
            A.push(power[res]);
        res--;
    }
    int ptr = A.size() - 1;
    while(req != 0){
        int last = A.top();
        A.pop();
        A.push(last / 2);
        A.push(last / 2);
        req--;
    }
    cout << "YES\n";
    while(A.empty() == false)
    {
        cout << A.top() << " ";
        A.pop();
    }
    cout << endl;
    return 0;
}