#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <ncurses.h>

#define ALTO 15
#define ANCHO 25

int main()
{
    initscr();
    raw();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    int start_y = (LINES - ALTO) / 2;
    int start_x = (COLS - ANCHO) / 2;

    WINDOW *win = newwin(ALTO, ANCHO, start_y, start_x);
    box(win, 0, 0);
    mvwprintw(win, 0, (ANCHO - 16) / 2, " MANUELBOT v0.1 ");
    refresh();
    wrefresh(win);

    // Opciones
    const char* opciones[] = {"Conectar", "Apagar"};

    // Menu
    int opcion = 0;
    bool fin = false;

    // Imprime las opciones
    for (int i = 0; i < 2; i++)
    {
        mvwprintw(win, 2*i+2, 2, opciones[i]);
    }
    wrefresh(win);
    int tecla = getch();

// Finaliza ncurses
endwin();
return 0;
}
