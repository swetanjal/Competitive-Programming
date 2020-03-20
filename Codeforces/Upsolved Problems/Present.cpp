// Codeforces Round #626 (Div. 1, based on Moscow Open Olympiad in Informatics)
// 1322 B
/*
Some pointers to the solution. Tags I feel are relevant: Sorting, binary-search, bitmasks
-> Construct the solution bit by bit
-> Suppose we are interested in finding out whether $k^{th}$ bit is set or not in the solution.
-> We need to consider all pairs of numbers, but we are only interested from $0^{th}$ to $k^{th}$ bit in these numbers
-> Therefore, consider numbers modulo $2^{k+1}$. $k + 1$ because we want information of the $k^{th}$ bit inclusive
-> This gets our numbers in range from $0$ to $2^{k+1} - 1$ and the sums cannot exceed $2^{k+2} - 2$
-> Which of the pairs' sum contribute to the $k^{th}$ bit being set. [Intuition: Set the $k^{th}$ bit and think about all the different ranges]
-> Of course the sum needs to be greater than $2^k$ and must be less than $2^{k+1}$. 
-> This is without considering the sum having $(k+1)^{th}$ bit being set.
-> Considering when $(k+1)^{th}$ bit is set in the sum of the pair, this corresponds to range between $2^{k+1} + 2^{k}$ and $2^{k+2} - 2$.
*/

#include "bits/stdc++.h"
using namespace std;
const int BITS = 26;
const int MAXN = 4e5 + 5;
int N;
long long int A[MAXN];
long long int B[MAXN];
int solve[BITS];
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> B[i];
    for(int i = 0; i < BITS - 1; ++i){
        for(int j = 0; j < N; ++j) A[j] = B[j] % (1LL << (i + 1));
        sort(A, A + N);
        long long int pairs = 0;
        for(int j = 0; j < N; ++j){
            // Find upper bound k such that A[j] + A[k] < (1 << (i + 1))
            int low = j + 1; int high = N - 1;
            int mid; int k = -1;
            while(low <= high){
                mid = (high + low) / 2;
                if(A[j] + A[mid] < (1LL << (i + 1))){
                    k = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            // Find lower bound k such that A[j] + A[k_prime] >= (1 << i)
            low = j + 1; high = N - 1;
            int k_prime = -1;
            while(low <= high){
                mid = (high + low) / 2;
                if(A[j] + A[mid] >= (1LL << i)){
                    k_prime = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            // Number of pairs is k - k_prime + 1
            int pairs_1 = 0;
            if(k_prime != -1 && k != -1){
                pairs_1 = k - k_prime + 1;
            }

            /************************************************************/

            // Find upper bound k such that A[j] + A[k] <= ((1 << (i + 2)) - 2)
            low = j + 1; high = N - 1;
            long long bound = ((1LL << (i + 2)) - 2);
            k = -1;
            while(low <= high){
                mid = (high + low) / 2;
                if(A[j] + A[mid] <= bound){
                    k = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            // Find lower bound k such that A[j] + A[k_prime] >= (1 << (i + 1)) + (1 << i)
            low = j + 1; high = N - 1;
            bound = (1LL << (i + 1)) + (1LL << i);
            k_prime = -1;
            while(low <= high){
                mid = (high + low) / 2;
                if(A[j] + A[mid] >= bound){
                    k_prime = mid;
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            // Number of pairs is k - k_prime + 1
            int pairs_2 = 0;
            if(k_prime != -1 && k != -1){
                pairs_2 = k - k_prime + 1;
            }
            pairs += ((pairs_1 + pairs_2) % 2);
        }
        solve[i] = pairs % 2;
    }
    long long res = 0;
    for(int i = 0; i < BITS; ++i)
        res = res + solve[i] * (1LL << i);
    cout << res << endl;
    return 0;
}