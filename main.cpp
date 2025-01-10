#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <ncurses.h>

#define ALTO 15
#define ANCHO 25
#include <cstdlib>  // Para system()
#include <ncurses.h> // Para endwin()

void actua(int opcion) {
    switch (opcion) {
        case 0:
            // algo
            break;
        case 1: {
            const char* comando = "sshpass -p \"x\" ssh -o StrictHostKeyChecking=no x@192.168.3.81 "
                                  "'echo x | sudo -S shutdown now'";
            int resultado = system(comando);
            if (resultado != 0) {
                printw("Error al ejecutar el comando.\n");
            }
            break;
        }
        case 2:
            endwin();
            exit(0);
            break;
        default:
            printw("Opción no válida.\n");
            break;
    }
}

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

    // Variables
    int opcion = 0;
    int tecla = 0;
    bool fin = false;

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
            case 10:
                actua(opcion);
                break;
        }

        // Imprime las opciones
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
