#include <ncurses.h>
#include <unistd.h>

#include "singelton.h"
#include "editor.h"

#define SCREEN_WIDTH 32
#define SCREEN_HEIGHT 24

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
    //int xmax, ymax;
    unsigned int delay = 20000;
    unsigned char keymap[256];

    api_t api;
    api.events = queue_init();
    api.cursor = (cursor_t){0, 2};

    for (unsigned char i = 0; i < 255; i++) keymap[i] = '\0';
    keymap['q'] = TK_QUIT;
    keymap['k'] = TK_UP;
    keymap['j'] = TK_DOWN;
    keymap['l'] = TK_RIGHT;
    keymap['h'] = TK_LEFT;

    editor_singelton_init();
    active = &editor_singelton;

    WINDOW *track;


    initscr();
    noecho();
    cbreak();
    curs_set(TRUE);
    keypad(stdscr, TRUE);

    track = newwin(32, 10, 0, 0);
    nodelay(stdscr, TRUE);
    //getmaxyx(stdscr, ymax, xmax);

    while(1) {
        api.key = keymap[getch()];
        active->update(&api);

        //getmaxyx(stdscr, ymax, xmax);
        track_print(track, api.cursor.y, api.cursor.x);
        run_events(api.events, false);
        usleep(delay);
    }

    return 0;
}

