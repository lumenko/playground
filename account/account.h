//
// Created by lumenko on 8/17/26.
//

#ifndef PLAYGROUND_ACCOUNT_H
#define PLAYGROUND_ACCOUNT_H

#endif //PLAYGROUND_ACCOUNT_H

/**
 *
 */
typedef struct {
    char account_number[19];
    char *name;
    char pin[5];
    double balance;
    int is_active;
} Account;

Account *createAccount(const char *name, const char *pin, double balance, int is_active, double initial_balance);

Account *findAccount(const char *accNum);

void printAccount(const Account *account);

int authenticate(const Account *account);
