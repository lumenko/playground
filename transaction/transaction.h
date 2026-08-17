//
// Created by lumenko on 8/17/26.
//

#ifndef PLAYGROUND_TRANSACTION_H
#define PLAYGROUND_TRANSACTION_H

#endif //PLAYGROUND_TRANSACTION_H

typedef struct {
    int day, month, year;
} Date;

typedef enum {
    TRANSACTION_DEPOSIT,
    TRANSACTION_WITHDRAW,
    TRANSACTION_TRANSFER
} TransactionType;

typedef struct {
    int transaction_id;
    char account_sender[19];
    TransactionType type;
    double amount;
    Date date;
} Transaction;

int depositMoney(const char* accNum, double amount);

int withdrawMoney(const char* accNum, double amount);

int transferMoney(const char* senderAcc, const char* receiverAcc, double amount);

void logTransaction(const char* accNum, TransactionType type, double amount);