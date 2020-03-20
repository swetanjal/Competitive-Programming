#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    char str[100005];
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int l = str.size();
        int gcount = 0, bcount = 0;
        vector <int> req;
        int j=0;
        for (int i=0; i<l; i++)
        {
            if (str[i] == 'f' || str[i] == 'r' || str[i] == 'i' || str[i] == 'e' || str[i] == 'z' || str[i] == 'a')
            {
                gcount++;
                if (bcount != 0)
                {
                    req.push_back(bcount);
                    bcount = 0;                    
                }
            }
            else 
            {
                bcount++;
                if (gcount != 0)
                {
                    req.push_back(gcount);                    
                    gcount = 0;
                }
            }
        }
        if (gcount != 0)
        {
            req.push_back(gcount);
        }
        else if (bcount != 0)
        {
            req.push_back(bcount);
        }
        l = req.size();
        for (int i=0; i<l; i++)
        {
            cout << req[i];
        }
        cout << "\n";
    }
    return 0;
}