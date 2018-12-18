#include "bits/stdc++.h"
using namespace std;
int T;
long double A, B, X, Y;
struct point{
    long double x;
    long double y;
};
point P1, P2, P3, P4, Q1, Q2, Q3, Q4;

bool Q2Q3()
{
    point T3;
    T3.x = Q2.x;
    T3.y = A;
    point T2;
    T2.x = Q2.x;
    T2.y = 0;
    point T1;
    T1.x = 0; T1.y = max((long double)0, T3.y - (T3.x * (Q4.y - T3.y) / (Q4.x - T3.x)));
    long double tmp = T2.x + (T1.x - T2.x) * (Q1.y - T2.y) / (T1.y - T2.y);
    if(Q1.x >= tmp)
        return true;
    return false;
}

bool Q1Q4()
{
    point T3, T2;
    T3.x = Q4.x;
    T3.y = A;
    T2.y = 0;
    T2.x = Q4.x;
    point T1;
    T1.x = A; T1.y = max((long double)0, T3.y + ((T3.y - Q3.y) * (T1.x - T3.x)/ (T3.x - Q3.x)));
    long double tmp = T1.x + (T1.x - T2.x) * (Q2.y - T1.y) / (T1.y - T2.y);
    if(tmp >= Q2.x)
        return true;
    return false;
}

bool Q1Q2()
{
    point T1, T2, T3;
    T3.x = 0; T2.x = A;
    T3.y = Q1.y; T2.y = Q1.y;
    T1.y = A;
    T1.x = min((long double)A, T3.x + (T3.x - Q4.x) * (T1.y - T3.y) / (T3.y - Q4.y));
    long double tmp = (Q3.y - T2.y) * (T2.x - T1.x) / (T2.y - T1.y) + T2.x;
    if(tmp >= Q3.x)
        return true;
    return false;
}

bool Q4Q3()
{
    point T1, T2, T3;
    T1.y = 0;
    T3.x = 0; T3.y = Q4.y;
    T2.x = A; T2.y = Q4.y;
    T1.y = 0;
    T1.x = min((long double)A, T3.x + (T1.y - T3.y) * (T3.x - Q1.x) / (T3.y - Q1.y));
    long double tmp = (Q2.y - T2.y) * (T2.x - T1.x) / (T2.y - T1.y) + T2.x;
    if(tmp >= Q2.x)
        return true;
    return false;
}

bool solve()
{
    cin >> A >> B >> X >> Y;
    
    P1.x = 0; P1.y = 0;
    P2.x = A; P2.y = 0;
    P3.x = A; P3.y = A;
    P4.x = 0; P4.y = A;

    Q1.x = X; Q1.y = Y;
    Q2.x = X + B; Q2.y = Y;
    Q3.x = X + B; Q3.y = Y + B;
    Q4.x = X; Q4.y = Y + B;
    return (Q2Q3() | Q1Q4() | Q1Q2() | Q4Q3());
}

int main()
{
    cin >> T;
    while(T--){
        
        if(solve())
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}