#include "bits/stdc++.h"
using namespace std;
int A[] = {4, 8, 15, 16, 23, 42};

pair <int, int> comp(int S){
    for(int i = 0; i < 6; ++i){
        for(int j = i + 1; j < 6; ++j){
            if((A[i] * A[j]) == S)
                return {A[i], A[j]};
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "? " << "1 2" << endl;
    int prod;
    cin >> prod;
    pair < int, int > p1 = comp(prod);
    cout << "? " << "2 3" << endl;
    cin >> prod;
    pair <int, int> p2 = comp(prod);
    vector <int> res;
    if(p1.first == p2.first){
        res.push_back(p1.second);
        res.push_back(p1.first);
        res.push_back(p2.second);
    }
    else if(p1.first == p2.second){
        res.push_back(p1.second);
        res.push_back(p1.first);
        res.push_back(p2.first);
    }
    else if(p1.second == p2.first){
        res.push_back(p1.first);
        res.push_back(p1.second);
        res.push_back(p2.second);
    }
    else if(p1.second == p2.second){
        res.push_back(p1.first);
        res.push_back(p1.second);
        res.push_back(p2.first);
    }
    cout << "? " << "3 4" << endl;
    cin >> prod;
    res.push_back(prod / res[2]);
    cout << "? " << "4 5" << endl;
    cin >> prod;
    res.push_back(prod / res[3]);
    for(int i = 0; i < 6; ++i){
        int fl = 1;
        for(int j = 0; j < 5; ++j){
            if(res[j] == A[i]){
                fl = 0;
                break;
            }
        }
        if(fl)
            res.push_back(A[i]);
    }
    cout << "! ";
    for(int i = 0; i < 6; ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}