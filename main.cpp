#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <ncurses.h>

#define ALTO 15
#define ANCHO 25

int main()
{
    // Parametros de inicializacion
    initscr();
    raw();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    // Calcula el alto y el ancho
    int start_y = (LINES - ALTO) / 2;
    int start_x = (COLS - ANCHO) / 2;

    // Crea la ventana
    WINDOW *win = newwin(ALTO, ANCHO, start_y, start_x);
    box(win, 0, 0);
    mvwprintw(win, 0, (ANCHO - 16) / 2, " MANUELBOT v0.1 ");
    refresh();
    wrefresh(win);

    // Opciones
    const char* opciones[] = {"Conectar", "Apagar", "Salir"};

    // Menu
    int opcion = 0;
    bool fin = false;
    int tecla = 0;

    // Interaccion
    while (!fin) {
        switch (tecla) {
            case KEY_UP:
                opcion--;
                if (opcion < 0) {
                    opcion = 0;
                }
                break;
            case KEY_DOWN:
                opcion++;
                if (opcion > 2) {
                    opcion = 2;
                }
                break;
            case KEY_ENTER:
                fin = true;
                break;
        }

        for (int i = 0; i < 3; i++) {
            if (i == opcion) {
                wattron(win, A_REVERSE);
            }
            mvwprintw(win, 2*i+2, 2, "- %s", opciones[i]);
            if (i == opcion) {
                wattroff(win, A_REVERSE);
            }
        }
        wrefresh(win);
        tecla = getch();
    }

// Finaliza ncurses
endwin();
return 0;
}
