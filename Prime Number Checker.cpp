#include <stdio.h>
#include <math.h>

int main() {
    int n, isPrime = 1; // Assume n is prime initially

    printf("Please Input a Number: ");
    scanf_s("%d", &n);

    // Handle edge cases
    if (n <= 1) {
        isPrime = 0; // Numbers less than or equal to 1 are not prime
    }
    else {
        // Check divisibility from 2 to sqrt(n)
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                isPrime = 0; // If divisible, it's not prime
                break;
            }
        }
    }

    if (isPrime) {
        printf("%d is a prime number.\n", n);
    }
    else {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}
