// Program 11: Write a program to implement the Diffie-Hellman Key Exchange algorithm.
// The algorithm in itself is very simple. Let’s assume that Alice wants to establish a shared secret with Bob. Here is an example of the protocol with secret values in red.
// 1. Alice and Bob agree to use a prime number p = 23 and base g = 5. (These two values are chosen in this way to ensure that the resulting shared secret can take on any value from 1 to p–1).
// 2. Alice chooses a secret integer a = 6, then sends Bob A = ga mod p (A = 56 mod 23 = 8)
// 3. Bob chooses a secret integer b = 15, then sends Alice B = gb mod p (B = 515 mod 23 = 19)
// 4. Alice computes s = Ba mod p (s = 196 mod 23 = 2)
// 5. Bob computes s = Ab mod p (s = 815 mod 23 = 2)
// 6. Alice and Bob now share a secret (the number 2).
// The number Alice get at step 4 is same as Bob got at step 5 as Bob computes
// Ab mod p = (ga mod p)b mod p = gab mod p
// Alice computes
// Ba mod p = (gb mod p)a mod p = gba mod p
#include <stdio.h>
// Function to compute a^m mod n 
int compute(int a, int m, int n)
{
int r;
int y = 1;
 while (m > 0) {
    r = m % 2;
    // fast exponention if (r == 1)
    y = (y*a) % n; 
    a = a*a % n;
    m = m / 2; 
}

return y; 
}
int diffie(int g, int a ,int p){
    int r, y = 1;
    while (a > 0)
    {
        r = a % 2;
        if (r == 1){
            y = (y * g) % p;
        }
        g = g * g % p;
        a /= 2;
    }
    return y;
}
// C program to demonstrate Diffie-Hellman algorithm
int main() {
int p = 23; int g = 5;
int a, b; int A, B;
// modulus // base
// a - Alice's Secret Key, b - Bob's Secret Key. // A - Alice's Public Key, B - Bob's Public Key
// choose secret integer for Alice's Pivate Key (only known to Alice)
 a = 6; // or use rand()
// Calculate Alice's Public Key (Alice will send A to Bob) 
A = compute(g, a, p);
// choose secret integer for Bob's Pivate Key (only known to Bob) 
b = 15; // or use rand()
// Calculate Bob's Public Key (Bob will send B to Alice) 
B = compute(g, b, p);
// Alice and Bob Exchanges their Public Key A & B with each other
printf("Alice's public Key is %d\nBob's Secret Key is %d\n", A, B);

// Find Secret key
int keyA = compute(B, a, p); int keyB = compute(A, b, p);
printf("Alice's Secret Key is %d\nBob's Secret Key is %d\n", keyA, keyB);

return 0; }
// Output:
// Alice’s Secret Key is 2 Bob’s Secret Key is 2