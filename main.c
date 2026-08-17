#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "account/account.h"
#include "data/storage.h"
#include "transaction/transaction.h"

#define TRUE 1

#define COLOR_RESET   "\033[0m"
#define COLOR_BOLD    "\033[1m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_RED     "\033[31m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_GRAY    "\033[90m"

static void clearScreen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

static void displayMenu(void) {
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

static int getMenuChoice(void) {
    char buffer[32];

    printf(COLOR_BOLD "\nUnesite Vas izbor [0-7]: " COLOR_RESET);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return -1;
    }

    char *endPtr;
    errno = 0;

    const long choice = strtol(buffer, &endPtr, 10);

    if (endPtr == buffer || errno == ERANGE) {
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
        clearScreen();
        displayMenu();

        const int choice = getMenuChoice();

        switch (choice) {
            case 1:
                printf(COLOR_BLUE "\n[PROVERA STANJA]\n" COLOR_RESET);
                // Poziv funkcije: showBalance();
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
                // Poziv funkcije: createNewAccount();
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

        if (running) {
            printf(COLOR_GRAY "\nPritisnite Enter za povratak u glavni meni..." COLOR_RESET);
            getchar();
        }
    }

    return 0;
}