// Start of template for mod exponentiation
long long modExp(long long a, long long b, long long p)
{
	if(b==0){
		return 1;
	}
	if(b==1)return a;
	long long ttt=modExp(a,b/2,p);
	ttt=(ttt*ttt)%p;
	if((b%2)==0)return ttt;
	return (ttt*a)%p;
}
// End of template for mod exponentiation