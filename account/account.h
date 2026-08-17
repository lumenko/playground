//
// Created by lumenko on 8/17/26.
//

#ifndef PLAYGROUND_ACCOUNT_H
#define PLAYGROUND_ACCOUNT_H
#include <stddef.h>

#endif //PLAYGROUND_ACCOUNT_H

/**
 *
 */
typedef struct {
    char *account_number;
    char *name;
    char *pin;
    double balance;
    int is_active;
} Account;

Account *createAccount(char *name, char pin[5], double balance, int is_active);

Account *findAccount(const char *accNum);

void printAccount(const Account *account);

int authenticate(const Account *account);

int validatePin(const char *pin);

char *createAccountNumber(char *buffer, size_t bufferSize, int nextId);

unsigned int getSecureRandomNumber(unsigned int max);