#include <ncurses.h>
#include <unistd.h>

#define SCREEN_WIDTH 32
#define SCREEN_HEIGHT 24

void track_print(WINDOW *track) {
    for (int i=0; i<16; i++) {
        mvwprintw(track, i, 0, "%x---", i);
    }
    wmove(track, 0, 1);
    wrefresh(track);
}

int main(int argc, char **argv) {
    int xmax, ymax;
    int key_pressed = 0, old_key_pressed = 0;

    WINDOW *track;


    initscr();
    noecho();
    curs_set(TRUE);

    track = newwin(16, 10, 0, 0);
    nodelay(track, TRUE);
    getmaxyx(stdscr, ymax, xmax);

    while(1) {
        track_print(track);

        key_pressed = 

        getmaxyx(stdscr, ymax, xmax);
        usleep(20000);
    }
    endwin();

    return 0;
}

