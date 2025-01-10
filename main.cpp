#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#define ALTO 15
#define ANCHO 25

int main() {
    initscr();
    raw();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    // Imprimir el tamaño detectado de la terminal
    printf("LINES: %d, COLS: %d\n", LINES, COLS);
    refresh();

    // Calcula las coordenadas para centrar la ventana
    int start_y = (LINES - ALTO) / 2;        // Coordenada y centrada
    int start_x = (COLS - ANCHO) / 2;    // Coordenada x centrada

    // Crear la ventana
    WINDOW *win = newwin(ALTO, ANCHO, start_y, start_x);
    box(win, 0, 0);  // Dibuja un cuadro en la ventana
    mvwprintw(win, 0, (ANCHO-16)/2, " MANUELBOT v0.1 ");
    wrefresh(win); // Actualiza la ventana

    // Opciones
    char* opciones[] = { "Conectar", "Apagar" };

    // Menu
    int opcion = 0;
    bool fin = false;
    while (!fin) {
        wclear(win);
        box(win, 0, 0);
        mvwprintw(win, 0, (ANCHO-16)/2, " MANUELBOT v0.1 ");
        wrefresh(win);
        wrefresh(win);
        int c = wgetch(win);
        if (c == KEY_UP) {
            if (opcion > 0) {
                opcion--;
            }
        } else if (c == KEY_DOWN) {
            if (opcion < 1) {
                opcion++;
            }
        } else if (c == KEY_ENTER) {
            break;
        }
    }

    getch();

    // Finaliza ncurses
    endwin();
    return 0;
}
