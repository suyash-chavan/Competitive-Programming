// Using Euclidean Algorithm ->


long long gcd (long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// BINARY GCD(If using C++17 include numric header) ->

long long gcd(long long a, long long b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

// LCM using GCD ->

long long lcm (long long a, long long b) {
    return a / gcd(a, b) * b;
}
