// Start of template for Euler Totient Function
long long phi(long long S){
    long long result = S;
    for(long long i = 2; (i * i) <= S; ++i){
        if((S % i) == 0){
            while((S % i) == 0)
                S /= i;
            result = result - (result / i);
        }
    }
    if(S >= 2){
        result = result - (result/ S);
    }
    return result;
}
// End of template for Euler Totient Function