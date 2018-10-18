#include "bits/stdc++.h"
#include "string"
using namespace std;

long long freqr[100005][26];
long long freql[100005][26];

void frequency(string str, int n)
{
    for (int j=0; j<26; j++)
    {
        for (int i=(n-1); i>=0; i--)
        {
            if (i == (n-1)) freqr[i][j] = 0;
            else
            {
                if (str[i+1] == ('a'+j)) freqr[i][j] = freqr[i+1][j] + 1;
                else freqr[i][j] = freqr[i+1][j];
            }
        }
    }
    for (int j=0; j<26; j++)
    {
        for (int i=0; i<n; i++)
        {
            if (i == 0) freql[i][j] = 0;
            else
            {
                if (str[i-1] == ('a'+j)) freql[i][j] = freql[i-1][j] + 1;
                else freql[i][j] = freql[i-1][j];
            }
        }
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int n = str.size();
        frequency(str, n);
        long long in = 0;
        for (int i=0; i<n; i++)
        {
            for (int j=(str[i]-'a'+1); j<26; j++)
            in += freqr[i][j];
        }
        long long x, y;
        long long ans = in;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<26; j++)
            {
                y = in;
                long long tmp;
                if (j == (str[i]-'a')) 
                {
                    x = 0;
                }
                else if (j >= (str[i]-'a'))
                {
                    x = j - (str[i]-'a');
                    for (int k=25; k>(str[i]-'a'); k--) 
                        y -= freqr[i][k];
              
                    for (int k=0; k<(str[i]-'a'); k++)
                        y -= freql[i][k];

                    for(int k = j + 1; k < 26; k++)
                    	y += freqr[i][k];

                    for(int k = 0; k < j; k++)
                    	y += freql[i][k];
                }
                else 
                {
                    x = (str[i]-'a') - j;
                    for (int k=25; k>(str[i]-'a'); k--) 
                        y -= freqr[i][k];
              
                    for (int k=0; k<(str[i]-'a'); k++)
                        y -= freql[i][k];

                    for(int k = j + 1; k < 26; k++)
                    	y += freqr[i][k];

                    for(int k = 0; k < j; k++)
                    	y += freql[i][k];
                }
                tmp = x + y;
                ans = min(ans, tmp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}