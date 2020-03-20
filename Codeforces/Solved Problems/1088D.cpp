#include "bits/stdc++.h"
using namespace std;

int main()
{
    cout << "? 0 0" << endl;
    fflush(stdout);
    int key;
    cin >> key;
    long long int C = 0;
    long long int D = 0;
    for(int i = 29; i >= 0; i--){
        if(key == 0){
            long long tmpC = 0;
            long long tmpD = 0;
            tmpD = 1 << i;
            tmpD |= D;
            tmpC |= C;
            cout << "? " << tmpC << " " << tmpD << endl;
            fflush(stdout);
            int tmp_key;
            cin >> tmp_key;
            if(tmp_key > 0){
                tmpC = 1 << i;
                tmpD = 1 << i;
                C |= tmpC;
                D |= tmpD;
            }
            cout << "? " << C << " " << D << endl;
            fflush(stdout);
            int check = 0;
            cin >> check;
            assert(check == 0);
            continue;
        }
        long long tmpC = 0;
        tmpC = 1 << i;
        tmpC = tmpC | C;
        long long tmpD = 0;
        tmpD = 1 << i;
        tmpD = tmpD | D;
        cout << "? " << tmpC << " " << tmpD << endl;
        fflush(stdout);
        int tmp_key = 0;
        cin >> tmp_key;
        if(tmp_key != key){
            if(key > 0){
                tmpC = 1 << i;
                C = C | tmpC;
            }
            else{
                tmpD = 1 << i;
                D = D | tmpD;
            }
            cout << "? " << C << " " << D << endl;
            fflush(stdout);
            int tmp_key;
            cin >> tmp_key;
            key = tmp_key;
        }
        else{
            long long tmpC = 0;
            long long tmpD = 0;
            tmpD = 1 << i;
            tmpD |= D;
            tmpC |= C;
            cout << "? " << tmpC << " " << tmpD << endl;
            fflush(stdout);
            int tmp_key;
            cin >> tmp_key;
            if(tmp_key > 0){
                tmpC = 1 << i;
                tmpD = 1 << i;
                C |= tmpC;
                D |= tmpD;
            }
        }
    }
    cout << "! " << C << " " << D << endl;
    return 0;
}