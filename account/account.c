//
// Created by lumenko on 8/17/26.

#include "account.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ANSI Kodovi za boje u terminalu
#define COLOR_RESET   "\033[0m"
#define COLOR_BOLD    "\033[1m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_RED     "\033[31m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_GRAY    "\033[90m"

Account * createAccount(char *name, char *pin, const double balance, const int is_active)
{
    Account *account = NULL;

    char accNum[19];
    const int currentUserId = 42;

    account->name = name;
    account->balance = balance;
    account->is_active = is_active;
    account->pin = pin;
    account->account_number = createAccountNumber(accNum, sizeof(accNum), currentUserId);

    return account;
}

Account * findAccount(const char *accNum)
{
    Account *account = NULL;

    return account;
}

void printAccount(const Account *account)
{
    const char* statusStr = account->is_active ? "AKTIVAN" : "BLOKIRAN";
    const char* statusColor = account->is_active ? COLOR_GREEN : COLOR_RED;

    printf("\n" COLOR_CYAN "====================================================\n" COLOR_RESET);
    printf(" " COLOR_BOLD "DETALJI BANKARSKOG RACUNA" COLOR_RESET "\n");
    printf(COLOR_CYAN "====================================================\n" COLOR_RESET);
    printf("  Broj racuna : " COLOR_BOLD "%s" COLOR_RESET "\n", account->account_number);
    printf("  Vlasnik     : %s\n", account->name);
    printf("  Stanje      : " COLOR_YELLOW "%.2f RSD" COLOR_RESET "\n", account->balance);
    printf("  Status      : %s%s" COLOR_RESET "\n", statusColor, statusStr);
    printf(COLOR_CYAN "----------------------------------------------------\n" COLOR_RESET);
}

int authenticate(const Account *account)
{
    return 1;
}

int validatePin(const char *pin) {
    return 1;
}

char *createAccountNumber(char *buffer, const size_t bufferSize, const int nextId) {
    if (buffer == NULL || bufferSize < 19) {
        return NULL;
    }

    const unsigned int randomPart = getSecureRandomNumber(100);

    snprintf(buffer, bufferSize, "840-%06d%04d-01", nextId, randomPart);

    return buffer;
}

unsigned int getSecureRandomNumber(const unsigned int max) {
    unsigned int randVal = 0;
    FILE *urandom = fopen("/dev/urandom", "rb");

    if (urandom) {
        fread(&randVal, sizeof(randVal), 1, urandom);
        fclose(urandom);
    } else {
        randVal = (unsigned int)rand();
    }

    return randVal % max;
}
