#include "bits/stdc++.h"
#define PI 3.14159265
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double n, r;
    cin >> n >> r;
    long double angle1 = 360 * 1.0 / n;
    long double angle2 = (180 - angle1) * 1.0 / 2;
    long double R= r * sin(angle1 * PI / 180) / (2 * sin(angle2 * PI / 180) - sin(angle1 * PI / 180));
    cout << fixed << setprecision(9) << R << endl;
    return 0;
}