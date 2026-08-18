//
// Created by lumenko on 8/17/26.

#include "account.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../display.h"
#include "../data/storage.h"

account * create_account(const char *name, char pin[5], const double balance, const int is_active)
{
    account *acc = malloc(sizeof(account));
    if (acc == NULL) {
        return NULL;
    }
    memset(acc, 0, sizeof(account));

    const int current_user_id = 42;

    strcpy(acc->name, name);
    strcpy(acc->pin, pin);

    acc->balance = balance;
    acc->is_active = is_active;

    create_account_number(acc->account_number, sizeof(acc->account_number), current_user_id);

    const int saved = save_account_to_file(acc);
    if (!saved) {
        printf("Doslo je do problema pri cuvanju racuna.\nRacun nije sacuvan!\n");
        getchar();
    }

    return acc;
}

void print_account(const account *acc)
{
    const char* status_str = acc->is_active ? "AKTIVAN" : "BLOKIRAN";
    const char* status_color = acc->is_active ? COLOR_GREEN : COLOR_RED;

    printf("\n" COLOR_CYAN "====================================================\n" COLOR_RESET);
    printf(" " COLOR_BOLD "DETALJI BANKARSKOG RACUNA" COLOR_RESET "\n");
    printf(COLOR_CYAN "====================================================\n" COLOR_RESET);
    printf("  Broj racuna : " COLOR_BOLD "%s" COLOR_RESET "\n", acc->account_number);
    printf("  Vlasnik     : %s\n", acc->name);
    printf("  Stanje      : " COLOR_YELLOW "%.2f RSD" COLOR_RESET "\n", acc->balance);
    printf("  Status      : %s%s" COLOR_RESET "\n", status_color, status_str);
    printf(COLOR_CYAN "----------------------------------------------------\n" COLOR_RESET);
}

int authenticate(const account *account)
{
    return 1;
}

int validate_pin(const char *pin) {
    return 1;
}

char *create_account_number(char *buffer, const size_t buffer_size, const int next_id) {
    if (buffer == NULL || buffer_size < 19) {
        return NULL;
    }

    const unsigned int random_part = get_secure_random_number(100);

    snprintf(buffer, buffer_size, "840-%06d%04d-01", next_id, random_part);

    return buffer;
}

unsigned int get_secure_random_number(const unsigned int max) {
    unsigned int rand_val = 0;
    FILE *urandom = fopen("/dev/urandom", "rb");

    if (urandom) {
        fread(&rand_val, sizeof(rand_val), 1, urandom);
        fclose(urandom);
    }

    return rand_val % max;
}
