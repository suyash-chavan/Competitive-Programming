#define MAXN 100005
#define mod 1000000007

vector<long long> inverse_factorial(MAXN);
vector<long long> token(MAXN);
vector<long long> factorial(MAXN);

long long nPr(long long n, long long r)
{
    if (r > n)
        return 0;

    return ((inverse_factorial[n - r] * factorial[n]) % mod);
}


long long nCr(long long n, long long r)
{
    if (r > n)
        return 0;

    return (((inverse_factorial[r] * inverse_factorial[n - r]) % mod) * factorial[n]) % mod;
}


void pre()
{

    inverse_factorial[1] = 1;
    inverse_factorial[0] = 1;

    token[1] = 1;
    token[0] = 1;

    factorial[1] = 1;
    factorial[0] = 1;

    for (long long i = 2; i < MAXN; i++)
        token[i] = token[mod % i] * (mod - mod / i) % mod;

    for (long long i = 2; i < MAXN; i++)
        factorial[i] = (factorial[i - 1] * i) % mod;

    for (long long i = 2; i < MAXN; i++)
        inverse_factorial[i] = (token[i] * inverse_factorial[i - 1]) % mod;

}
