#include <ncurses.h>
#include <unistd.h>

#include "queue.h"

#define SCREEN_WIDTH 32
#define SCREEN_HEIGHT 24

typedef struct {
    unsigned char key;
    void *event;
} key;

void track_print(WINDOW *track, int cursor_y, int cursor_x) {
    for (int i=0; i<16; i++) {
        mvwprintw(track, i, 0, "%x---", i);
    }
    wmove(track, cursor_y, cursor_x);
    wrefresh(track);
}

int main(int argc, char **argv) {
    int xmax, ymax;
    int key_pressed = 0;
    int cursor_y = 0, cursor_x = 2;
    unsigned int delay = 20000;

    key keys[100];

    WINDOW *track;


    initscr();
    noecho();
    cbreak();
    curs_set(TRUE);
    keypad(stdscr, TRUE);

    track = newwin(16, 10, 0, 0);
    nodelay(stdscr, TRUE);
    getmaxyx(stdscr, ymax, xmax);

    while(1) {
        track_print(track, cursor_y, cursor_x);

        key_pressed = getch();
        switch(key_pressed) {
            case 'j': cursor_y++; break;
            case 'k': cursor_y--; break;
            case 'h': cursor_x--; break;
            case 'l': cursor_x++; break;
        }

        getmaxyx(stdscr, ymax, xmax);
        usleep(delay);
    }
    endwin();

    return 0;
}

