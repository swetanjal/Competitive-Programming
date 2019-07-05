// Template for Matrix Exponentiation
/*
    Author: Swetanjal Dutta(swetanjal)
    This template can be used to solve Linear Recurrences.
    Usage:
    1. Create object of MatrixExpo class as follows: MatrixExpo <int> obj(m, b, mod); 
    where m is the matrix whose exponent is required and b is the base vector. Answer is computed modulo mod.
    2. Raise m to the power N and multiply with b: vector < int > P = obj.solve(N);
*/
template <typename T>
class MatrixExpo{
private:
    vector < vector <T> > M;
    vector < T > B;
    vector < vector <T> > identity;
    long long int MOD;
    int dim;
    vector < vector <T> > matrixExpo(long long int N)
    {
        if(N == 0)
            return identity;
        if(N == 1)
            return M;
        vector < vector < T > > res = matrixExpo(N / 2);
        vector < vector < T > > ans;
        vector < vector < T > > ret;
        vector < T > tmp;
        for(int i = 0; i < dim; ++i)
            tmp.push_back(0);
        for(int i = 0; i < dim; ++i)
            ans.push_back(tmp), ret.push_back(tmp); 
        for(int i = 0; i < dim; ++i){
            for(int j = 0; j < dim; ++j){
                for(int k = 0; k < dim; ++k)
                    ans[i][j] = (ans[i][j] + ((res[i][k] * res[k][j]) % MOD)) % MOD;
            }
        }
        if((N % 2) != 0)
        {
            for(int i = 0; i < dim; ++i){
                for(int j = 0; j < dim; ++j){
                    for(int k = 0; k < dim; ++k)
                        ret[i][j] = (ret[i][j] + ((ans[i][k] * M[k][j]) % MOD)) % MOD;
                }
            }   
        }
        else
            ret = ans;
        return ret;
    }
public:
    MatrixExpo(vector < vector < T > > m, vector < T > b, long long int mod)
    {
        MOD = mod;
        M = m;
        B = b;
        dim = b.size();
        vector <T> tmp;
        for(int i = 0; i < dim; ++i)
            tmp.push_back(0);
        for(int i = 0; i < dim; ++i)
        {
            tmp[i] = 1;
            identity.push_back(tmp);
            tmp[i] = 0;
        }
    }
    vector < T > solve(long long int N)
    {
        vector < vector < T > > X = matrixExpo(N);
        vector <T> ret;
        for(int i = 0; i < dim; ++i){
            ret.push_back(0);
            for(int j = 0; j < dim; ++j){
                ret[i] = (ret[i] + (X[i][j] * B[j]) % MOD) % MOD;
            }
        }
        return ret;
    }
};
// End of template for Matrix Exponentiation