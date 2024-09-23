#include <stdio.h>
#include <stdbool.h>

// Function declarations
void checkBalance(float balance);
float deposit(float balance);
float withdraw(float balance);
bool verifyPin();

int main() {
    int choice;
    float balance = 1000.0; // Initial balance
    int attempts = 0, max_attempts = 3;

    // PIN verification
    while (attempts < max_attempts) {
        if (verifyPin()) {
            printf("PIN verified successfully!\n");
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. You have %d attempt(s) remaining.\n", max_attempts - attempts);
        }
    }

    if (attempts == max_attempts) {
        printf("Too many incorrect attempts. Exiting...\n");
        return 0;
    }

    // ATM menu after successful PIN verification
    while (1) {
        printf("\n********** ATM Menu **********\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("******************************\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                printf("Thank you for using the ATM! Goodbye.\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

// Function to verify the PIN
bool verifyPin() {
    int correctPin = 1234; // Set a default PIN (you can modify this)
    int enteredPin;

    printf("Please enter your PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin == correctPin) {
        return true;
    } else {
        return false;
    }
}

// Function to check balance
void checkBalance(float balance) {
    printf("\nYour current balance is: $%.2f\n", balance);
}

// Function to deposit money
float deposit(float balance) {
    float amount;
    printf("\nEnter the amount to deposit: $");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("Successfully deposited $%.2f\n", amount);
        printf("Your new balance is: $%.2f\n", balance);
    } else {
        printf("Invalid deposit amount!\n");
    }
    return balance;
}

// Function to withdraw money
float withdraw(float balance) {
    float amount;
    printf("\nEnter the amount to withdraw: $");
    scanf("%f", &amount);

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("Successfully withdrawn $%.2f\n", amount);
        printf("Your remaining balance is: $%.2f\n", balance);
    } else if (amount > balance) {
        printf("Insufficient balance!\n");
    } else {
        printf("Invalid withdrawal amount!\n");
    }
    return balance;
}
