#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    priority_queue <int> even;
    priority_queue <int> odd;
    int A[N];
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    // Even
    for(int i = 0; i < N; ++i){
        if((A[i] % 2) == 0)
            even.push(A[i]);
        else
            odd.push(A[i]);
    }
    long long sum1 = 0;
    long long sum2 = 0;
    long long res = LONG_LONG_MAX;
    for(int i = 0; i < N; ++i){
        if(i % 2){
            // Remove even
            if(even.empty() == true){
                break;
            }
            else{
                even.pop();
            }
        }
        else{
            // Remove odd
            if(odd.empty() == true){
                break;
            }
            else{
                odd.pop();
            }
        }
    }

    while(odd.empty() == false){
        sum1 += odd.top();
        odd.pop();
    }
    while(even.empty() == false){
        sum2 += even.top();
        even.pop();
    }
    res = min(res, max(sum1, sum2));
    for(int i = 0; i < N; ++i){
        if((A[i] % 2) == 0)
            even.push(A[i]);
        else
            odd.push(A[i]);
    }
    for(int i = 0; i < N; ++i){
        if((i % 2) == 0){
            // Remove even
            if(even.empty() == true){
                break;
            }
            else{
                even.pop();
            }
        }
        else{
            // Remove odd
            if(odd.empty() == true){
                break;
            }
            else{
                odd.pop();
            }
        }
    }
    sum1 = 0; sum2 = 0;
    while(odd.empty() == false){
        sum1 += odd.top();
        odd.pop();
    }
    while(even.empty() == false){
        sum2 += even.top();
        even.pop();
    }
    res = min(res, max(sum1, sum2));
    cout << res << endl;
    return 0;
}