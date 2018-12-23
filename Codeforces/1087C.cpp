#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1e3 + 5;
int A[MAXN][MAXN];
int xA, xB, xC, yA, yB, yC;

void init()
{
    for(int i = 0; i < MAXN; ++i)
        for(int j = 0; j < MAXN; ++j)
            A[i][j] = 0;
}

bool connect(int X1, int Y1, int X2, int Y2)
{
    if(X1 <= X2)
    {
        for(int i = X1; i <= X2; ++i)
            A[Y1][i] = 1;
    }
    else{
        for(int i = X2; i <= X1; ++i)
            A[Y1][i] = 1;
    }

    if(Y1 <= Y2){
        for(int i = Y1; i <= Y2; ++i)
            A[i][X2] = 1;
    }
    else{
        for(int i = Y2; i <= Y1; ++i)
            A[i][X2] = 1;
    }
}

int count()
{
    int c = 0;
    for(int i = 0; i < MAXN; ++i)
        for(int j = 0; j < MAXN; ++j)
            c += A[i][j];
    return c;
}
vector <int> ansX;
vector <int> ansY;

void push()
{
    for(int i = 0; i < MAXN; ++i)
    {
        for(int j = 0; j < MAXN; ++j){
            if(A[i][j])
            {
                ansX.push_back(j);
                ansY.push_back(i);
            }
        }
    }
}


int main()
{
    cin >> xA >> yA;
    cin >> xB >> yB;
    cin >> xC >> yC;
    init();    
    connect(xA, yA, xB, yB);
    connect(xB, yB, xC, yC);
    long long int res = count();
    push();

    init();
    connect(xA, yA, xB, yB);
    connect(xC, yC, xB, yB);
    int tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }

    init();
    connect(xB, yB, xA, yA);
    connect(xC, yC, xB, yB);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }

    init();
    connect(xB, yB, xA, yA);
    connect(xB, yB, xC, yC);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }

    ////////////////////////
    init();
    connect(xC, yC, xA, yA);
    connect(xA, yA, xB, yB);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }

    init();
    connect(xC, yC, xA, yA);
    connect(xB, yB, xA, yA);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    init();
    connect(xA, yA, xC, yC);
    connect(xA, yA, xB, yB);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    init();
    connect(xA, yA, xC, yC);
    connect(xB, yB, xA, yA);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    ////////////////////////////////////
    init();
    connect(xA, yA, xC, yC);
    connect(xC, yC, xB, yB);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    init();
    connect(xA, yA, xC, yC);
    connect(xB, yB, xC, yC);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    init();
    connect(xC, yC, xA, yA);
    connect(xC, yC, xB, yB);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    init();
    connect(xC, yC, xA, yA);
    connect(xB, yB, xC, yC);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    /////////////////////////////////////////////
    init();
    connect(xB, yB, xA, yA);
    connect(xA, yA, xC, yC);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    init();
    connect(xB, yB, xA, yA);
    connect(xC, yC, xA, yA);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    init();
    connect(xA, yA, xB, yB);
    connect(xA, yA, xC, yC);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    init();
    connect(xA, yA, xB, yB);
    connect(xC, yC, xA, yA);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    ///////////////////////////

    init();
    connect(xB, yB, xC, yC);
    connect(xC, yC, xA, yA);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }

    init();
    connect(xB, yB, xC, yC);
    connect(xA, yA, xC, yC);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }

    init();
    connect(xC, yC, xB, yB);
    connect(xB, yB, xA, yA);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    init();
    connect(xC, yC, xB, yB);
    connect(xA, yA, xB, yB);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }

    //////////////////
    init();
    connect(xC, yC, xB, yB);
    connect(xB, yB, xA, yA);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }

    init();
    connect(xB, yB, xC, yC);
    connect(xB, yB, xA, yA);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }

    init();
    connect(xC, yC, xB, yB);
    connect(xA, yA, xB, yB);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    init();
    connect(xB, yB, xC, yC);
    connect(xA, yA, xB, yB);
    tmp = count();
    if(tmp < res){
        ansX.clear();
        ansY.clear();
        push();
        res = tmp;
    }
    
    cout << res << endl;
    
    for(int i = 0; i < res; ++i)
        cout << ansX[i] << " " << ansY[i] << endl;
    return 0;
}