cmake_minimum_required(VERSION 4.3)
project(playground C)

set(CMAKE_C_STANDARD 11)

add_executable(playground main.c
        account/account.h
        account/account.h
        account/account.c
        transaction/transaction.c
        transaction/transaction.h
        data/storage.c
        data/storage.h
        display.h)
