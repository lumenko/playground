//
// Created by lumenko on 8/17/26.
//

#ifndef PLAYGROUND_TRANSACTION_H
#define PLAYGROUND_TRANSACTION_H

#endif //PLAYGROUND_TRANSACTION_H

typedef struct {
    int day, month, year;
} date;

typedef enum {
    transaction_deposit,
    transaction_withdraw,
    transaction_transfer
} transaction_type;

typedef struct {
    int transaction_id;
    char account_sender[19];
    transaction_type type;
    double amount;
    date date;
} transaction;

int deposit_money(const char* acc_num, double amount);

int withdraw_money(const char* acc_num, double amount);

int transfer_money(const char* sender_acc, const char* receiver_acc, double amount);

void log_transaction(const char* acc_num, transaction_type type, double amount);