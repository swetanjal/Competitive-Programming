// binary search, greedy, two pointers 965D
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int l, w; // l < w range 10^5
int a[100001]; // size w-1
int sum[100001]; // size w-l

// e.g: if l=1, then then max no of frogs that reach = min a[i]
// logic: find th smallest sum segment of size l


int main()
{
    cin >> w >> l;
    for(int i = 1; i <= w-1; i++)
        cin >> a[i];

    sum[1] = 0;

    for(int i=1; i <= l; i++)
        sum[1] += a[i];

    for(int i=2; i <= w-l; i++)
    {
        // filling in the sum segments in sum array
        sum[i] = sum[i-1] + a[l+i-1] - a[i-1];
        // is this correct ?
    }
int min = sum[1];
for(int i=2; i <= w-l; i++)
{
    if(sum[i] < min)
        min = sum[i];
}
// find the min of sum array
cout << min << endl;
    return 0;
}
