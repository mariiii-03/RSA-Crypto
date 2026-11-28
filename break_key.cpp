// break_key.cpp - break the toy key by trial division.
#include "rsa.h"
#include <iostream>

int main() {
    uint64 n = 1000036000099ULL;
    uint64 e = 65537;
    std::string cipher = "0614157364221 0502078796304 0031583460315";

    uint64 p = 2;
    while (n % p != 0) p++;
    uint64 q = n / p;

    uint64 phi = (p - 1) * (q - 1);
    uint64 d = mod_inverse(e, phi);

    std::cout << "p = " << p << "\n";
    std::cout << "q = " << q << "\n";
    std::cout << "phi = " << phi << "\n";
    std::cout << "private key d = " << d << "\n";
    std::cout << "message: " << decrypt_text(cipher, n, d) << "\n";
    return 0;
}
