#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_HISTORY 10


typedef struct {
    char type[10];  
    int amount;
    int balance;
} Transaction;


Transaction history[MAX_HISTORY];
int historyCount = 0;


int isValidCardNumber(char* cardNumber) {
    int i = 0;
    //Checks for the content of a number to determine its validity
    while (cardNumber[i] != '\0') {

        if (!(isdigit(cardNumber[i]) || cardNumber[i] == '-')) {
            return 0;
        }
        i++;
    }

    if (i != 19) {  //If number doesn't contain 19 characters (16 numbers + 3 dashes= Like on a real credit card)
        return 0;
    }

    for (int j = 4; j < 19; j += 5) {   //Is invalid if it lacks dashes
        if (cardNumber[j] != '-') {
            return 0;
        }
    }

    return 1;
}


void Withdraw(int* MoneyBalance) {
    int amount;
    printf("Please declare the amount you want to withdraw: ");
    scanf("%d", &amount);

    if (*MoneyBalance == 0) {
        printf("Cannot withdraw. You got no money on your account.\n");
    }
    else if (*MoneyBalance < amount) {
        printf("Insufficient funds! You only have %d on your account.\n", *MoneyBalance);
    }
    else {
        *MoneyBalance -= amount;
        printf("Withdrawal successful! New balance: %d\n", *MoneyBalance);


        if (historyCount < MAX_HISTORY) {   //Transaction recorder
            strcpy(history[historyCount].type, "Withdraw");
            history[historyCount].amount = amount;
            history[historyCount].balance = *MoneyBalance;
            historyCount++;
        }
    }
}


void Deposit(int* MoneyBalance) {
    int amount;
    printf("Please input the amount you want to add: ");
    scanf("%d", &amount);

    *MoneyBalance += amount;
    printf("Deposit successful! New balance: %d\n", *MoneyBalance);


    if (historyCount < MAX_HISTORY) { //Transaction recorder
        strcpy(history[historyCount].type, "Deposit");
        history[historyCount].amount = amount;
        history[historyCount].balance = *MoneyBalance;
        historyCount++;
    }
}


void CheckHistory() {
    if (historyCount == 0) {
        printf("No transactions made yet.\n");
    }
    else {
        printf("\n--- Transaction History ---\n");
        for (int i = 0; i < historyCount; i++) {
            printf("%s: $%d, Balance: $%d\n", history[i].type, history[i].amount, history[i].balance);
        }
    }
}

int main() {
    int MoneyBalance = 0;
    char choice;
    char CCI[20];


    printf("Please input your credit card number: ");
    scanf("%18s", CCI);
    while (1) {
        printf("Please enter your credit card number (format: 1234-5678-9012-3456): ");
        scanf("%19s", CCI);

        if (isValidCardNumber(CCI)) {
            printf("Card number %s is valid.\n", CCI);
            break;
        }
        else {
            printf("Invalid input. Please follow the format 1234-5678-9012-3456.\n");
        }
    }


    while (1) {
        printf("\nAlright, what do you want to do?\n");
        printf("A. Withdraw\nB. Deposit\nC. Check account history\nD. Exit\n");
        printf("Enter your choice (A/B/C/D): ");


        while (getchar() != '\n');
        scanf ("%c", &choice);

        switch (choice) {
        case 'A':
        case 'a':
            Withdraw(&MoneyBalance);
            break;
        case 'B':
        case 'b':
            Deposit(&MoneyBalance);
            break;
        case 'C':
        case 'c':
            CheckHistory();
            break;
        case 'D':
        case 'd':
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please select A, B, C, or D.\n");
            break;
        }
    }

    return 0;
}
