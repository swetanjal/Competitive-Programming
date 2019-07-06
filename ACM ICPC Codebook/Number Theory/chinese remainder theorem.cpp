// Template for CRT
/*
    Author: Swetanjal Dutta(swetanjal)
    This template can be used to compute the smallest number X satisfying N equations of the form X % ni = ri
    Usage:
    1. This template makes use of the Modular Inverse Template.
    2. Create an object of CRT class:
    CRT obj(n, r)
    where n is a vector of ni s and r is a vector of ri s where ni and ri have the meaning implied by the equation above
    3. Solve for X:
    obj.solve() 
*/
class CRT{
private:
    vector <long long> N;
    vector <long long> R;
    long long prodN;
public:
    CRT(vector <long long> n, vector < long long > r)
    {
        N = n;
        R = r;
        prodN = 1;
    }
    long long solve()
    {
        int L = N.size();
        for(int i = 0; i < L; ++i)
            prodN = prodN * N[i];
        long long ans = 0;
        for(int i = 0; i < L; ++i){
            long long y = prodN / N[i];
            ModularInverse obj(N[i]);
            long long z = obj.solve(y);
            ans = ans + (z * y * R[i]);
        }
        return (ans % prodN);
    }
};
// End of template for CRT