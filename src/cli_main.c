#include <ncurses.h>
#include <unistd.h>

#include "singelton.h"
#include "editor.h"
#include "songdata.h"

#define SCREEN_WIDTH 32
#define SCREEN_HEIGHT 24

void track_print(WINDOW *track, int cursor_y, int cursor_x) {
    for (int i=0; i<32; i++) {
        mvwprintw(track, i, 0, "%02x---", i);
    }
    wmove(track, cursor_y, cursor_x);
    wrefresh(track);
}

void *event_add_track(void *data) {
    return NULL;
}

void generic_update(api_t *api) {
    switch(api->key) {
        case TK_F1: add_event(api->events, event_add_track, NULL); break;
    }
}

int main(int argc, char **argv) {
    //int xmax, ymax;
    unsigned int delay = 20000;
    unsigned char keymap[256];

    songdata_t *songdata = songdata_init();

    api_t api;
    api.events = list_init();
    api.cursor = (cursor_t){0, 2};
    api.mode = normal;

    for (unsigned char i = 0; i < 255; i++) keymap[i] = '\0';
    setenv("ESCDELAY", "10", 1);
    for (unsigned char c = 'a'; c < 'z'; c++) 
        keymap[c] = TK_a + c - 'a';
    keymap[27] = TK_ESC;
    keymap['k'] = TK_UP;
    keymap['j'] = TK_DOWN;
    keymap['l'] = TK_RIGHT;
    keymap['h'] = TK_LEFT;
    keymap['q'] = TK_QUIT;
    keymap[':'] = TK_EX;

    editor_singelton_init();
    active = &editor_singelton;

    WINDOW *track;


    initscr();
    noecho();
    cbreak();
    curs_set(TRUE);
    keypad(stdscr, TRUE);

    track = newwin(32, 10, 5, 10);
    nodelay(stdscr, TRUE);
    //getmaxyx(stdscr, ymax, xmax);

    while(api.key != TK_QUIT) {
        api.key = keymap[getch()];

        active->update(&api);
        generic_update(&api);

        //getmaxyx(stdscr, ymax, xmax);
        run_events(api.events, false);
        track_print(track, api.cursor.y, api.cursor.x);
        usleep(delay);
    }

    endwin();
    printf("See you soon!\n");
    return 0;
}

