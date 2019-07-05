// Template for Modular Inverse
/*
    Author: Swetanjal Datta(swetanjal)
    This template can be used to compute the modular inverse of a number modulo m.
    Usage:
    1. Create object of ModularInverse class as follows:
        ModularInverse obj(m);
    2. Compute modular inverse of a modulo m: obj.solve(a)
        where a is the number whose modulo inverse needs to be computed
*/
class ModularInverse{
private:
    long long MOD;
    long long x;
    long long y;
    long long extended_gcd(long long a, long long b)
    {
        if(b==0){
            x=1;
            y=0;
            return a;
        }
        long long g = extended_gcd(b, a % b);
        long long x1 = x;
        long long y1 = y;
        x = y1;
        y = x1 - ((a / b) * y1);
        return g;
    }
public:
    ModularInverse(long long m){
        MOD = m;
    }
    long long solve(long long a)
    {
        long long hcf = extended_gcd(max(a, MOD), min(a, MOD));
        if(a > MOD){
		    while(x < 0)x += MOD;
		    return x;
	    }
        else {
		    while(y < 0)y += MOD;
		    return y;
	    }
    }
};
// End of template for Modular Inverse