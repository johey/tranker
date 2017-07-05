#include <ncurses.h>
#include <unistd.h>

#include "singelton.h"
#include "queue.h"
#include "editor.h"

#define SCREEN_WIDTH 32
#define SCREEN_HEIGHT 24

typedef struct {
    unsigned char key;
    void *event;
} key;

void *event_chordwindow(void *win) {
    mvwprintw((WINDOW *)win, 1, 1, "LOLLLLLLL");   
    wrefresh((WINDOW *)win);
    return NULL;
}

void track_print(WINDOW *track, int cursor_y, int cursor_x) {
    for (int i=0; i<32; i++) {
        mvwprintw(track, i, 0, "%02x---", i);
    }
    wmove(track, cursor_y, cursor_x);
    wrefresh(track);
}

void *event_quit(void *data) {
    endwin();
    exit(0);
}

int main(int argc, char **argv) {
    int xmax, ymax;
    int key_pressed = 0;
    cursor_t cursor = { 0, 2 };
    unsigned int delay = 20000;

    queue_t *events = queue_init();

    active = &editor_singelton;

    key keys[100];

    WINDOW *track;


    initscr();
    noecho();
    cbreak();
    curs_set(TRUE);
    keypad(stdscr, TRUE);

    track = newwin(32, 10, 0, 0);
    nodelay(stdscr, TRUE);
    getmaxyx(stdscr, ymax, xmax);

    while(1) {
        active->update(NULL);
        track_print(track, cursor.y, cursor.x);
        run_events(events, false);
        usleep(delay);
    }

    return 0;
}

