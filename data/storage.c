//
// Created by lumenko on 8/17/26.
//

#include "storage.h"
#include "../account/account.h"

#include <stdio.h>
#include <string.h>

#define ACCOUNTS_FILE "accounts.bin"

int save_account_to_file(const account *acc) {
    FILE *file = fopen(ACCOUNTS_FILE, "ab");
    if (file == NULL) {
        printf("Doslo je do greske pri otvaranju datoteke.\n");
        return 0;
    }

    const size_t written = fwrite(acc, sizeof(account), 1, file);
    fclose(file);

    return written == 1;
}

int load_account_from_file(const char *account_number, account *out_account) {
    if (account_number == NULL || out_account == NULL) {
        return 0;
    }

    FILE *file = fopen(ACCOUNTS_FILE, "rb");

    if (file == NULL) {
        return 0;
    }

    account tmp_account;
    while (fread(&tmp_account, sizeof(account), 1, file) == 1) {
        if (strcmp(tmp_account.account_number, account_number) == 0) {
            *out_account = tmp_account;
            fclose(file);

            return 1;
        }
    }

    fclose(file);
    return 0;
}

int update_account_in_file(account *acc) {
    return 1;
}

void load_all_accounts() {
}

void read_transaction_history(char *acc_num) {
}
