# RSA Encryption Tool

This project implements a simple RSA encryption tool in C++ to demonstrate the basic concepts of RSA encryption and decryption using number theory.

## Overview

The RSA encryption algorithm is a public-key cryptosystem that uses two keys: a public key for encryption and a private key for decryption. The security of RSA relies on the difficulty of factoring large composite numbers.

## Features

- **Prime Number Generation**: Generate random prime numbers within a specified range.
- **Public and Private Key Generation**: Create public and private keys for encryption and decryption.
- **Message Encryption**: Encrypt a message using the public key.
- **Message Decryption**: Decrypt a message using the private key (decryption part not implemented in the code).

## Code Explanation

### Prime Number Check

```cpp
bool isPrime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
