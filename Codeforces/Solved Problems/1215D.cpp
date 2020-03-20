#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt1 = 0;
    int cnt2 = 0;
    int sum1 = 0;
    int sum2 = 0;
    char c;
    for(int i = 0; i < N; ++i){
        cin >> c;
        if(c == '?' && i < (N / 2))
            cnt1 += 1;
        if(c == '?' && i >= (N / 2))
            cnt2 += 1;
        if(c != '?' && i < (N / 2))
            sum1 += (c - '0');
        if(c != '?' && i >= (N / 2))
            sum2 += (c - '0');
    }
    int chance = 0;
    while(cnt1 > 0 && cnt2 > 0){
        //cout << sum1 << " " << sum2 << endl;
        if((chance % 2) == 0){
            // Unequal's chance
            if(sum1 > sum2)
                sum1 += 9, cnt1 -= 1;
            else
                sum2 += 9, cnt2 -= 1; 
        }
        else{
            // Equal's chance
            if(sum1 > sum2)
                sum2 = sum2 + min(9, sum1 - sum2), cnt2 -= 1;
            else
                sum1 = sum1 + min(9, sum2 - sum1), cnt1 -= 1;
        }
        chance++;
    }
    while(cnt1 > 0){
        //cout << "cnt1\n";
        //cout << sum1 << " " << sum2 << endl;
        if((chance % 2) == 0){
            // Unequal
            if(sum1 > sum2)
                break;
            else{
                if((sum1 + (chance / 2) * 9 + (chance / 2) * 0) > sum2){
                    sum1 += 9;
                    cnt1 -= 1;
                }
                else
                {
                    sum1 += 0;
                    cnt1 -= 1;
                }
            }
        }
        else{
            if(sum1 > sum2)
                break;
            else
                sum1 = sum1 + min(9, sum2 - sum1), cnt1 -= 1;
        }
        chance++;
    }
    while(cnt2 > 0){
        //cout << "cnt2\n";
        //cout << sum1 << " " << sum2 << endl;
        if((chance % 2) == 0){
            // Unequal
            if(sum2 > sum1)
                break;
            else{
                if((sum2 + (chance / 2) * 9 + (chance / 2) * 0) > sum1){
                    sum2 += 9;
                    cnt2 -= 1;
                }
                else
                {
                    sum2 += 0;
                    cnt2 -= 1;
                }
            }
        }
        else{
            if(sum2 > sum1)
                break;
            else
                sum2 = sum2 + min(9, sum1 - sum2), cnt2 -= 1;
        }
        chance++;
    }
    if(sum1 == sum2)
        cout << "Bicarp\n";
    else
        cout << "Monocarp\n";
    return 0;
}