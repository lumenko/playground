//
// Created by lumenko on 8/17/26.
//

#ifndef PLAYGROUND_STORAGE_H
#define PLAYGROUND_STORAGE_H

#include "../account/account.h"

#endif //PLAYGROUND_STORAGE_H

int saveAccountToFile(const Account* acc);

int updateAccountInFile(const Account* acc);

void loadAllAccounts();

void readTransactionHistory(const char* accNum);
