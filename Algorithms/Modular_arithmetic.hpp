const long long MOD = 1e9 + 7;

void add(long long &a, long long b)
{
    a = (a + MOD) % MOD;
    b = (b + MOD) % MOD;

    a = (a + b) % MOD;
}

void sub(long long &a, long long b)
{
    a = (a + MOD) % MOD;
    b = (b + MOD) % MOD;

    a = (a - b) % MOD;
    a = (a + MOD) % MOD;
}

void mul(long long &a, long long b)
{
    a = (a + MOD) % MOD;
    b = (b + MOD) % MOD;

    a = (a * b) % MOD;
}
