#include "bits/stdc++.h"
using namespace std;

int main()
{
    int X;
    cin >> X;

    for(int i = 1; i <= X; i++)
    {
        for(int j = 1; j <= X; j++){
            int A = i;
            int B = j;
         
            if(((A * B) > X) && ((A / B) < X) && (A % B) == 0)
            {
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }
    cout << "-1\n";
    return 0;
}