//
// Created by lumenko on 8/17/26.
//

#ifndef PLAYGROUND_ACCOUNT_H
#define PLAYGROUND_ACCOUNT_H


#include <stddef.h>

typedef struct account {
    char account_number[19];
    char name[50];
    char pin[5];
    double balance;
    int is_active;
} account;


account *create_account(const char *name, char pin[5], double balance, int is_active);

void print_account(const account *acc);

int authenticate(const account *account);

int validate_pin(const char *pin);

char *create_account_number(char *buffer, size_t buffer_size, int next_id);

unsigned int get_secure_random_number(unsigned int max);

#endif //PLAYGROUND_ACCOUNT_H