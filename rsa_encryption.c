// Author : Youssef Aitbouddroub
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


// Function to check if a given number is prime
bool is_prime(long long int number){
    long long int divisor = 5;
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;
    while (divisor * divisor <= number){
        if (number % divisor == 0 || number % (divisor + 2) == 0) return false;
        divisor += 6;
    }
    return true;
}

// Function to generate a random prime number within a specified range.
long long int generate_prime(long long int min_value, long long int max_value){
    printf("Generating the prime number...\n");
    long long int prime = rand() % (max_value - min_value + 1) + min_value;
    while (!is_prime(prime)) {
        prime = rand() % (max_value - min_value + 1) + min_value;
    }
    return prime;
}

// Function to compute the modular inverse of 'e' modulo 'phi'
long long int mod_inverse( long long int e, long long int phi){
    for(long long int d = 2; d < phi; d++){
        if ((d * e) % phi == 1) return d;
    }
    return -1;
}

// Calculate the greatest common divisor (gcd) of two numbers.
long long int gcd(long long int a, long long int b){
    long long int remainder = 0;
    if (a == 0) return b;
    if (b == 0) return a;
    remainder = a % b;
    return gcd(b, remainder);    
}

// Function to encode a string into its ASCII integer values
long long int* encode_string(char* string){
    long long int* encoded_string = (long long int*) malloc(strlen(string) * sizeof(long long int));
    // Check if memory allocation was successful
    if (encoded_string == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Encoding message to ASCII values
    for (long long int i = 0; i < strlen(string); i++){
        encoded_string[i] = string[i];
    }
    return encoded_string;
}

// Function to decode an array of ASCII values back to a string
char* decode_to_string(long long int* array, long long int size) {
    char* decoded_string = (char*) malloc((size + 1) * sizeof(char));
    if (decoded_string == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (long long int i = 0; i < size; i++) {
        decoded_string[i] = (char) array[i];
    }
    decoded_string[size] = '\0';
    return decoded_string;
}

// Function to perform modular exponentiation
long long int mod_pow(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Function to encrypt a message using RSA algorithm
long long int* encrypt(long long int* message, long long int size, long long int e, long long int n) {
    long long int* encrypted = malloc(size * sizeof(long long int));
    if (!encrypted) {
        printf("Memory allocation failed for encrypted message.\n");
        return NULL;
    }
    for (long long int i = 0; i < size; i++) {
        encrypted[i] = mod_pow(message[i], e, n);
    }
    return encrypted;
}

// Function to decrypt a message using RSA algorithm
long long int* decrypt(long long int* encrypted, long long int size, long long int d, long long int n) {
    long long int* decrypted = malloc(size * sizeof(long long int));
    if (!decrypted) {
        printf("Memory allocation failed for decrypted message.\n");
        return NULL;
    }
    for (long long int i = 0; i < size; i++) {
        decrypted[i] = mod_pow(encrypted[i], d, n);
    }
    return decrypted;
}

// Function to print array elements
void print_array(long long int* array, long long int size) {
    for (long long int i = 0; i < size; i++) {
        printf("%lld ", array[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Generate two distinct primes
    long long int p = generate_prime(10000, 50000);
    long long int q;
    do {
        q = generate_prime(10000, 50000);
    } while (p == q);

    long long int n = p * q;
    long long int phi = (p - 1) * (q - 1);
    long long int e = 3;
    while (gcd(e, phi) != 1) {
        e += 2;
    }
    long long int d = mod_inverse(e, phi);

    printf("Public Key (e, n): (%lld, %lld)\n", e, n);
    printf("Private Key (d, n): (%lld, %lld)\n", d, n);

    // Encoding a string into ASCII values
    char* message = "Hello, RSA!";
    long long int* encoded = encode_string(message);
    long long int message_len = strlen(message);

    // Encrypting the message
    long long int* encrypted = encrypt(encoded, message_len, e, n);
    printf("Encrypted message: ");
    print_array(encrypted, message_len);

    // Decrypting the message
    long long int* decrypted = decrypt(encrypted, message_len, d, n);
    char* decrypted_message = decode_to_string(decrypted, message_len);
    printf("Decrypted message: %s\n", decrypted_message);

    // Free allocated memory
    free(encoded);
    free(encrypted);
    free(decrypted);
    free(decrypted_message);

    return 0;
}
