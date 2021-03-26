/*

   _____                       _        _____ _                            
  / ____|                     | |      / ____| |                           
 | (___  _   _ _   _  __ _ ___| |__   | |    | |__   __ ___   ____ _ _ __  
  \___ \| | | | | | |/ _` / __| '_ \  | |    | '_ \ / _` \ \ / / _` | '_ \ 
  ____) | |_| | |_| | (_| \__ \ | | | | |____| | | | (_| |\ V / (_| | | | |
 |_____/ \__,_|\__, |\__,_|___/_| |_|  \_____|_| |_|\__,_| \_/ \__,_|_| |_|
                __/ |                                                      
               |___/                                                       


*/

// More Time and Less Memory - Using Time Complexity O(NloglogN) - Know Whether Number is Prime

const long long n=100000;

vector<bool> is_prime(n+1, true);

void prime_sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

// Less Time and More Memory - Using Time Complexity O(N) - Know Primes in Range 0 to N

const long long N = 10000000;
long long lp[N+1];
vector<long long> primes;

void prime_sieve()
{
    for (long long i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (long long j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    } 
}


// Segmented Sieve

vector<bool> segmentedSieveNoPreGen(long long L, long long R) {
    vector<bool> isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
