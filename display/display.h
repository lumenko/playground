//
// Created by lumenko on 8/17/26.
//

#ifndef PLAYGROUND_DISPLAY_H
#define PLAYGROUND_DISPLAY_H

#define COLOR_RESET   "\033[0m"
#define COLOR_BOLD    "\033[1m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_RED     "\033[31m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_GRAY    "\033[90m"

void clear_screen(void);

void display_menu(void);

#endif //PLAYGROUND_DISPLAY_H

