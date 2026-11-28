# RSA Project — Discrete Structures, Fall 2026

Files: `rsa.h`, `rsa.cpp` (B0–B8), `test_rsa.cpp` (B9), `demo.cpp` (B9), `break_key.cpp` (B10),
`computations.pdf` (Part A, handwritten scan).

Only `+ - * / %` are used on integers; no `__int128`, `pow`, or big-number/crypto libraries.

## Build and run

    g++ -std=c++17 -O2 rsa.cpp test_rsa.cpp -o test_rsa
    ./test_rsa          # prints: All tests passed

    g++ -std=c++17 -O2 rsa.cpp demo.cpp -o demo
    ./demo              # interactive: enter p q e, then a message

    g++ -std=c++17 -O2 rsa.cpp break_key.cpp -o break_key
    ./break_key

## Demo run

    Enter p q e: 43 59 13
    Public key: n = 2537, e = 13
    Private key: d = 937
    Block size: 2 letters
    Message: Stop!
    Cleaned: STOP
    Plaintext blocks: 1819 1415
    Ciphertext: 2081 2182
    Decrypted: STOP

## Output of break_key (B10)

    p = 1000003
    q = 1000033
    phi = 1000034000064
    private key d = 983264276609
    message: NUMBERTHEORYISFUNX

The message is "NUMBER THEORY IS FUN" plus one padding `X` (block size k = 6, so
17 letters are padded to 18).
Trial division needed about 10^6 steps because n = 1000003 · 1000033 is small; for a 2048-bit key it would need about 10^308.

## Sources
Rosen, Discrete Mathematics and Its Applications, §4.1–4.4, §4.6, and the lecture slides.
