#include "cli_functions.h"

int main(int argc, char **argv) {
    //int xmax, ymax;
    unsigned int delay = 20000;
    unsigned char keymap[512];

    songdata_t *songdata = songdata_init();

    api_t *api = (api_t *)malloc(sizeof(api_t));
    api->events = list_init();
    api->cursor = (cursor_t){0, 2};
    api->mode = normal;
    api->key = ' ';

    for (uint16_t i = 0; i < 512; i++) keymap[i] = '\0';
    setenv("ESCDELAY", "10", 1);
    for (unsigned char c = 'a'; c < 'z'; c++) 
        keymap[c] = TK_a + c - 'a';
    keymap[27]       = TK_ESC;
    keymap['k']      = TK_UP;
    keymap['j']      = TK_DOWN;
    keymap['l']      = TK_RIGHT;
    keymap['h']      = TK_LEFT;
    keymap['q']      = TK_QUIT;
    keymap[':']      = TK_EX;
    keymap[KEY_F(1)] = TK_F1;

    editor_singelton_init();
    active = &editor_singelton;



    initscr();
    noecho();
    cbreak();
    curs_set(TRUE);
    keypad(stdscr, TRUE);

    nodelay(stdscr, TRUE);
    //getmaxyx(stdscr, ymax, xmax);

    while(api->key != TK_QUIT) {
        int hej = getch();
        api->key = keymap[hej];

        if (api->key != 0) mvprintw(0, 0, "key: %d\n", hej);
        active->update(api);
        generic_update(songdata, api);

        refresh();
        //getmaxyx(stdscr, ymax, xmax);
        run_events(api->events, false);
        //tracks_print(songdata, api);
        usleep(delay);
    }

    list_destruct(api->events);
    free(api);
    songdata_destruct(songdata);
    endwin();
    printf("See you soon!\n");
    return 0;
}

