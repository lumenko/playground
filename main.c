#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "account/account.h"
#include "display.h"
#include "data/storage.h"

#define TRUE 1
#define MAX_NAME_LEN 50
#define MAX_ACCOUNT_LEN 20

static void clear_screen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

static void display_menu(void) {
    printf(COLOR_CYAN COLOR_BOLD);
    printf("====================================================\n");
    printf("            BANKARSKI UPRAVLJACKI SISTEM            \n");
    printf("====================================================\n" COLOR_RESET);

    printf("  " COLOR_GREEN "[1]" COLOR_RESET " Provera stanja i detalji racuna\n");
    printf("  " COLOR_GREEN "[2]" COLOR_RESET " Uplata novca (Deposit)\n");
    printf("  " COLOR_GREEN "[3]" COLOR_RESET " Isplata novca (Withdrawal)\n");
    printf("  " COLOR_GREEN "[4]" COLOR_RESET " Prenos sredstava (Transfer)\n");
    printf("  " COLOR_GREEN "[5]" COLOR_RESET " Istorija transakcija\n");
    printf(COLOR_CYAN "----------------------------------------------------\n" COLOR_RESET);
    printf("  " COLOR_YELLOW "[6]" COLOR_RESET " Registracija novog racuna\n");
    printf("  " COLOR_YELLOW "[7]" COLOR_RESET " Pregled svih racuna (Admin)\n");
    printf(COLOR_CYAN "----------------------------------------------------\n" COLOR_RESET);
    printf("  " COLOR_RED "[0]" COLOR_RESET " Izlaz iz aplikacije\n");
    printf(COLOR_CYAN "====================================================\n" COLOR_RESET);
}

static void show_balance_menu(void) {
    char *account_number = malloc(MAX_NAME_LEN * sizeof(char));
    if (account_number == NULL) {
        printf("Nema dovoljno memorije.\n");
        return;
    }
    memset(account_number, 0, MAX_ACCOUNT_LEN);

    printf("Unesite broj racuna:\n");
    if (fgets(account_number, MAX_ACCOUNT_LEN, stdin) != NULL) {
        account_number[strcspn(account_number, "\n")] = '\0';
    }

    account *acc = malloc(sizeof(account));
    if (load_account_from_file(account_number, acc) != 1) {
        printf("Nesto je poslo po zlu!\n");
        return;
    }

    print_account(acc);

    free(acc);
    free(account_number);
    acc = NULL;
    account_number = NULL;
}

static void create_account_menu(void) {
    char *name = malloc(MAX_NAME_LEN * sizeof(char)), *pin = "1234";
    if (name == NULL) {
        printf("Nema dovoljno memorije.\n");
        return;
    }
    memset(name, 0, MAX_NAME_LEN);

    printf("Ime i prezime:\n");
    if (fgets(name, MAX_NAME_LEN, stdin) != NULL) {
        name[strcspn(name, "\n")] = '\0';
    }

    const account *account = create_account(name, pin, 0.0, 1);
    if (account == NULL) {
        printf("Doslo je do greske.\n");
        free(name);
        name = NULL;
        free((void*)account);
        return;
    }
    free(name);
    name = NULL;

    print_account(account);

    free((void *)account);
}

static int get_menu_choice(void) {
    char buffer[32];

    printf(COLOR_BOLD "\nUnesite Vas izbor [0-7]: " COLOR_RESET);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return -1;
    }

    char *end_ptr;
    errno = 0;

    const long choice = strtol(buffer, &end_ptr, 10);

    if (end_ptr == buffer || errno == ERANGE) {
        return -1;
    }

    if (choice < INT_MIN || choice > INT_MAX) {
        return -1;
    }

    return (int)choice;
}

int main(void) {
    int running = 1;

    while (running) {
        clear_screen();
        display_menu();

        const int choice = get_menu_choice();

        switch (choice) {
            case 1:
                printf(COLOR_BLUE "\n[PROVERA STANJA]\n" COLOR_RESET);
                show_balance_menu();
                break;
            case 2:
                printf(COLOR_BLUE "\n[UPLATA NOVCA]\n" COLOR_RESET);
                // Poziv funkcije: depositMoney();
                break;
            case 3:
                printf(COLOR_BLUE "\n[ISPLATA NOVCA]\n" COLOR_RESET);
                // Poziv funkcije: withdrawMoney();
                break;
            case 4:
                printf(COLOR_BLUE "\n[PRENOS SREDSTAVA]\n" COLOR_RESET);
                // Poziv funkcije: transferMoney();
                break;
            case 5:
                printf(COLOR_BLUE "\n[ISTORIJA TRANSAKCIJA]\n" COLOR_RESET);
                // Poziv funkcije: showTransactionHistory();
                break;
            case 6:
                printf(COLOR_BLUE "\n[REGISTRACIJA RACUNA]\n" COLOR_RESET);
                create_account_menu();
                break;
            case 7:
                printf(COLOR_BLUE "\n[ADMIN: PREGLED SVIH RACUNA]\n" COLOR_RESET);
                // Poziv funkcije: printAccountTable();
                break;
            case 0:
                printf(COLOR_GREEN "\nHvala Vam sto ste koristili nasu banku. Dovidjenja!\n" COLOR_RESET);
                running = 0;
                continue;
            default:
                printf(COLOR_RED "\nNepostojeca opcija! Pritisnite Enter za nastavak..." COLOR_RESET);
                getchar();
                continue;
        }


        printf(COLOR_GRAY "\nPritisnite Enter za povratak u glavni meni..." COLOR_RESET);
        getchar();

    }

    return 0;
}