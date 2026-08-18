//
// Created by lumenko on 8/17/26.
//

#ifndef PLAYGROUND_STORAGE_H
#define PLAYGROUND_STORAGE_H

#include "../account/account.h"

int save_account_to_file(const account* acc);

int load_account_from_file(const char * account_number, account *out_account);

int update_account_in_file(account* acc);

void load_all_accounts();

void read_transaction_history(char* acc_num);

#endif //PLAYGROUND_STORAGE_H
