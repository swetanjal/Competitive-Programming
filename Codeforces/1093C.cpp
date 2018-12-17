#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long int A[N];
    int cnt = N - 1;
    long long int tmp;
    cin >> tmp;
    A[cnt] = tmp;
    A[0] = 0;
    cnt--;
    for(int i = 1; i < (N / 2); ++i)
    {
        cin >> tmp;
        A[cnt] = min(tmp, A[cnt + 1]);
        A[i] = tmp - A[cnt];
        if(A[i] < A[i - 1])
        {
            A[i] = A[i - 1];
            A[cnt] = tmp - A[i];
        }
        cnt--;
    }
    for(int i = 0; i < N; ++i)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}