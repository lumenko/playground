//
// Created by lumenko on 8/20/26.
//
#include "display.h"
#include <stdio.h>
#include <stdlib.h>

void clear_screen(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void display_menu(void) {
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