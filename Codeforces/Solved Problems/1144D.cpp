#include "bits/stdc++.h"
using namespace std;
const int MAXN = 2e5 + 5;
int N;
int freq[MAXN];
int A[MAXN];
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        freq[A[i]]++;
    }
    int maxi = 0;
    int idx = -1;
    for(int i = 0; i < MAXN; ++i){
        if(freq[i] > maxi){
            maxi = freq[i];
            idx = i;
        }
    }
    int root = -1;
    for(int i = 0; i < N; ++i){
        if(idx == A[i]){
            root = i;
            break;
        }
    }
    vector <int> a;
    vector <int> b;
    vector <int> c;
    for(int i = root - 1; i >= 0; i--){
        if(A[i] < idx){
            a.push_back(1);
            b.push_back(i + 1);
            c.push_back(i + 1 + 1);
            //cout << i << " " << (i + 1) << endl;
        }
        else if(A[i] > idx){
            a.push_back(2);
            b.push_back(i + 1);
            c.push_back(i + 1 + 1);
        }
    }

    for(int i = root + 1; i < N; i++){
        if(idx < A[i]){
            a.push_back(2);
            b.push_back(i + 1);
            c.push_back(i - 1 + 1);
            //cout << i << " " << (i + 1) << endl;
        }
        else if(idx > A[i]){
            a.push_back(1);
            b.push_back(i + 1);
            c.push_back(i - 1 + 1);
        }
    }
    cout << a.size() << endl;
    for(int i = 0; i < a.size(); ++i)
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
    return 0;
}