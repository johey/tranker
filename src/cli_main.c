#include <ncurses.h>
#include <unistd.h>

#include "queue.h"
#include "editor.h"

#define SCREEN_WIDTH 32
#define SCREEN_HEIGHT 24

typedef struct {
    unsigned char key;
    void *event;
} key;

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
    cursor_t cursor = { 0, 1 };
    unsigned int delay = 20000;

    queue_t *events = queue_init();

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
        track_print(track, cursor.y, cursor.x);

        key_pressed = getch();
        switch(key_pressed) {
            case 'j': add_event(events, event_cursor_down, &cursor); break;
            case 'k': add_event(events, event_cursor_up, &cursor); /*cursor.y--;*/ break;
            case 'h': add_event(events, event_cursor_left, &cursor); break;
            case 'l': add_event(events, event_cursor_right, &cursor); break;
            case 'q': add_event(events, event_quit, NULL); break;
        }
        //add_event(events, event_cursor_down, &cursor);

        getmaxyx(stdscr, ymax, xmax);
        run_events(events);
        usleep(delay);
    }

    return 0;
}

