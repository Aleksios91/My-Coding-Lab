#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Function to check if a number is a palindrome
int isNumberPalindrome(int num) {
    int original = num, reversed = 0, remainder;
    while (num > 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    return original == reversed; // Returns 1 if palindrome, 0 otherwise
}

// Function to check if a string is a palindrome
int isStringPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // It's a palindrome
}

int main() {
    int choice;
    printf("Choose input type:\n");
    printf("1. Number\n");
    printf("2. String\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        if (isNumberPalindrome(num)) {
            printf("%d is a palindrome!\n", num);
        }
        else {
            printf("%d is not a palindrome.\n", num);
        }
    }
    else if (choice == 2) {
        char str[100];
        printf("Enter a string: ");
        scanf(" %s", str); // Space before %s to clear input buffer
        if (isStringPalindrome(str)) {
            printf("\"%s\" is a palindrome!\n", str);
        }
        else {
            printf("\"%s\" is not a palindrome.\n", str);
        }
    }
    else {
        printf("Invalid choice! Please choose 1 or 2.\n");
    }

    return 0;
}
