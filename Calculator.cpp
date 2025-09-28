#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void Add(float a, float b) {
    float c = a + b;
    
    if (a == (int)a && b == (int)b) {
        printf("Result: %.0f\n", c);  
    }
    else {
        printf("Result: %f\n", c);  
    }
}

void Subtract(float a, float b) {
    float c = a - b;
    
    if (a == (int)a && b == (int)b) {
        printf("Result: %.0f\n", c);  
    }
    else {
        printf("Result: %f\n", c);  
    }
}

void Multiply(float a, float b) {
    float c = a * b;
   
    if (a == (int)a && b == (int)b) {
        printf("Result: %.0f\n", c);  
    }
    else {
        printf("Result: %f\n", c);  
    }
}

void Divide(float a, float b) {
    if (b == 0) {
        printf("Forbidden division by 0, idiot! Try again.\n");
        return;
    }
    float c = a / b;
    
    if (a == (int)a && b == (int)b) {
        
        if ((int)c == c) {
            printf("Result: %.0f\n", c);  
        }
        else {
            printf("Result: %f\n", c);  
        }
    }
    else {
        printf("Result: %f\n", c);  
    }
}

int main() {
    float a, b;
    char choice;

    
    printf("Input 2 numbers: ");
    scanf_s("%f%f", &a, &b);

   
    printf("What do you want to do?\n");
    printf("A. Add, B. Subtract, C. Multiply, D. Divide: ");
    scanf_s(" %c", &choice);  

    
    switch (choice) {
    case 'A':
    case 'a':
        Add(a, b);
        break;
    case 'B':
    case 'b':
        Subtract(a, b);
        break;
    case 'C':
    case 'c':
        Multiply(a, b);
        break;
    case 'D':
    case 'd':
        Divide(a, b);
        break;
    default:
        printf("Invalid choice. Try again.\n");
        break;
    }

    return 0;
}

