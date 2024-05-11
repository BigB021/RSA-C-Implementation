# RSA Encryption and Decryption Program
This is an implementation of the RSA encryption and decryption algorithm using C programming. The program is capable of generating prime numbers, computing modular inverses, and performing encryption and decryption of messages.

## Features
*Prime Number Generation:* Generate two large random prime numbers which are used as the base for RSA key generation.
*Modular Inverse Calculation:* Computes the modular inverse of a number which is crucial for deriving the private key in RSA.
*Encryption and Decryption:* Using the RSA algorithm, the program can encrypt and decrypt messages using the generated keys.
*Modular Exponentiation:* Efficiently calculates powers of numbers modulo another number, which is used during the encryption and decryption processes.
## Installation
To run this program, you need a C compiler such as GCC installed on your machine. Follow these instructions to compile and run the program:

1. Clone the Repository

 ```bash
   git clone https://your-repository-url
   cd your-repository-directory
```
2. Compile the Program

```bash
gcc rsa_encryption.c -o rsa_encryption -lm
```
The -lm flag links the math library, which is necessary for some of the mathematical functions used in the program.

3. Run the Program

```bash
./rsa_encryption
```
or for Windows os:
```bash
.\rsa_encryption.exe      
```
## Usage
Once you run the program, it automatically performs the following steps:

1. Generates two distinct prime numbers within a specified range.
2. Calculates the public and private keys based on these prime numbers.
3. Takes a hardcoded message ("Hello, RSA!"), encodes it into ASCII values, and then encrypts it.
4. Decrypts the encrypted message back to ASCII and converts it to a readable string.
5. The console will display the public and private keys, the encrypted message, and the decrypted message.

## Functions
**bool is_prime(long long int number):** Checks if the provided number is prime.
**long long int generate_prime(long long int min_value, long long int max_value):** Generates a random prime number within the specified range.
**long long int mod_inverse(long long int e, long long int phi):** Computes the modular inverse of e modulo phi.
**long long int gcd(long long int a, long long int b):** Computes the greatest common divisor of two numbers.
**long long int* encode_string(char* string):** Encodes a string to its ASCII integer values.
**char* decode_to_string(long long int* array, long long int size):** Decodes an array of ASCII values back to a string.
**long long int mod_pow(long long int base, long long int exp, long long int mod):** Performs modular exponentiation.
**long long int* encrypt(long long int* message, long long int size, long long int e, long long int n):** Encrypts a message.
**long long int* decrypt(long long int* encrypted, long long int size, long long int d, long long int n):** Decrypts a message.
## License
This project is licensed under the MIT License.

## Contributing
Contributions to Graph Algorithm Visualizer are welcome! If you have an improvement or bug fix, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or fix.
3. Commit your changes with descriptive messages.
4. Push your branch and open a pull request against the main branch. Please ensure your code adheres to the project's coding style and has been tested thoroughly.

## Acknowledgments
This project is inspired by the desire to understand the RSA algorithms in action.

Auhtor : Youssef Aitbouddroub
