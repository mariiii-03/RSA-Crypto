// rsa.cpp - RSA from scratch. Only +, -, *, / and % are used on integers.
#include "rsa.h"
//#include <cctype>
#include <vector>
//#include <string>
using namespace std;

// OWNER: Zainab (Z2)
// B3: divide forward (save quotients), substitute backward.
long long extended_gcd(long long a, long long b, long long &s, long long &t) {
    std::vector<long long> quotients;
    long long r0 = a, r1 = b;
    while (r1 != 0) {
        quotients.push_back(r0 / r1);
        long long r2 = r0 % r1;
        r0 = r1;
        r1 = r2;
    }
    long long g = r0;
    long long x = 1, y = 0;
    for (int i = (int)quotients.size() - 1; i >= 0; i--) {
        long long q = quotients[i];
        long long newy = x - q * y;
        x = y;
        y = newy;
    }
    s = x;
    t = y;
    return g;
}

// OWNER: Zainab (Z2)
// B4: inverse of a mod m in 0..m-1.
uint64 mod_inverse(uint64 a, uint64 m) {
    long long s, t;
    long long g = extended_gcd((long long)a, (long long)m, s, t);
    if (g != 1) throw std::invalid_argument("no inverse");
    long long r = s % (long long)m;
    if (r < 0) r += (long long)m;
    return (uint64)r;
}

// OWNER: Zainab (Z2)
// B6
void generate_keys(uint64 p, uint64 q, uint64 e, uint64 &n, uint64 &d) {
    if (!is_prime(p) || !is_prime(q))
        throw std::invalid_argument("p and q must both be prime");
    if (p == q) throw std::invalid_argument("p and q must be different");
    uint64 phi = (p - 1) * (q - 1);
    if (e <= 1 || e >= phi || gcd(e, phi) != 1)
        throw std::invalid_argument("e must satisfy 1 < e < phi and gcd(e, phi) = 1");
    n = p * q;
    d = mod_inverse(e, phi);
}

// OWNER: Zainab (Z2)
// B7
uint64 encrypt(uint64 M, uint64 n, uint64 e) {
    if (M >= n) throw std::invalid_argument("message block must be less than n");
    return mod_exp(M, e, n);
}
uint64 decrypt(uint64 C, uint64 n, uint64 d) {
    if (C >= n) throw std::invalid_argument("ciphertext block must be less than n");
    return mod_exp(C, d, n);
}
