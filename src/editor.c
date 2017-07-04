#include "editor.h"

void *event_cursor_up(void *cursor) {
    ((cursor_t *)cursor)->y--;
    return (void *)NULL;
}

void *event_cursor_down(void *cursor) {
    ((cursor_t *)cursor)->y++;
    return (void *)NULL;
}

void *event_cursor_left(void *cursor) {
    ((cursor_t *)cursor)->x--;
    return (void *)NULL;
}

void *event_cursor_right(void *cursor) {
    ((cursor_t *)cursor)->x++;
    return (void *)NULL;
}

void *editor_update(void *data) {
    printf("hej\n");
        /*
        key_pressed = getch();
        switch(key_pressed) {
            case 'j': add_event(events, event_cursor_down, &cursor); break;
            case 'k': add_event(events, event_cursor_up, &cursor); break;
            case 'h': add_event(events, event_cursor_left, &cursor); break;
            case 'l': add_event(events, event_cursor_right, &cursor); break;
            case 'q': add_event(events, event_quit, NULL); break;
            case KEY_F(6): add_event(events, event_chordwindow, track); break;
        }

        getmaxyx(stdscr, ymax, xmax);
        */
    return NULL;
}

void editor_singelton_init() {
    editor_singelton.update = editor_update;
}

