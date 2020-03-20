#include <bits/stdc++.h>
using namespace std;
    
vector <long long int> a;
    
long long int max_med(long long int n, long long int k)
{
    long long int mid, m = n/2, low = a[m], high = a[m] + k;
    long long int ans = -1;
    while(high >= low)
    {
        mid = (high + low) / 2;
        long long int tot = 0;
        for(long long int i = m; i < n; i++){
            if((mid - a[i]) < 0)
                break;
            tot += (mid - a[i]);
        }
    
        if(tot <= k)
        {
            ans = mid;
            low = mid + 1;
        }
    
        else
            high = mid - 1;
    }
    return ans;
}
    
int main()
{
    long long int n, k, temp, res;
    cin >> n >> k;
    
    for(long long int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    
    sort(a.begin(), a.end());
    res = max_med(n, k);
    cout << res << endl;
    return 0;
}