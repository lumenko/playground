//
// Created by lumenko on 8/17/26.

#ifndef PLAYGROUND_ACCOUNT_H
#define PLAYGROUND_ACCOUNT_H

/**
 *
 */
#include <stdint.h>

/*
 * Optimized account layout:
 * - balance_cents: int64_t (store money as integer cents to avoid floating precision)
 * - account_number: 20 bytes (19 digits + '\0')
 * - pin: uint16_t (numeric PIN up to 4 digits) instead of string
 * - is_active: uint8_t (boolean flag)
 * Ordering places the widest/aligned fields first to reduce padding.
 */
typedef struct account {
    int64_t balance_cents; /* balance in cents */
    char account_number[20]; /* 19 chars + NUL */
    char name[50];
    uint16_t pin; /* numeric PIN (0-9999) */
    uint8_t is_active; /* 0 = inactive, 1 = active */
} account;


/**
 *
 */
account * create_account(const char *name, uint16_t pin, int64_t balance_cents, uint8_t is_active);

/**
 *
 */
void print_account(const account *acc);

/**
 *
 */
char *create_account_number(char *buffer, size_t buffer_size, int next_id);

/**
 *
 */
unsigned int get_secure_random_number(unsigned int max);

#endif //PLAYGROUND_ACCOUNT_H