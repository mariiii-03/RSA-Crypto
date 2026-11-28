#pragma once
#include <string>
#include <stdexcept>
using namespace std;

typedef unsigned long long uint64; // 64 bits: 0 to about 1.8 x 10^19


long long extended_gcd(long long a, long long b, long long &s, long long &t);           // B3
uint64 mod_inverse(uint64 a, uint64 m);                       // B4

void generate_keys(uint64 p, uint64 q, uint64 e, uint64 &n, uint64 &d);                     // B6
uint64 encrypt(uint64 M, uint64 n, uint64 e);                 // B7
uint64 decrypt(uint64 C, uint64 n, uint64 d);                 // B7

