#include "../cli_functions.c"

//void *event_add_track(void *data);
//void *event_sync_track_windows(void *data);
//void generic_update(songdata_t *songdata, api_t *api);
//void track_print(WINDOW *track, int cursor_y, int cursor_x);
//void draw(songdata_t *songdata, api_t *api);

TEST(CLI, AddAndRemoveTracks) {
    songdata_t *songdata = songdata_init();
    api_t *api = (api_t *)malloc(sizeof(api_t));

    api->key = TK_F1;
    api->events = list_init();
    api->mode = normal;
    api->songdata = songdata;


    generic_update(api);
    generic_update(api);
    generic_update(api);
    generic_update(api);

    //initscr();
    run_events(api->events, false);
    //endwin();

    ASSERT_EQ(4, songdata->tracks->count);

    list_destruct(api->events);
    songdata_destruct(songdata);
    free(api);
}

TEST(CLI, MoveCursorInTrack) {
    songdata_t *songdata = songdata_init();
    api_t *api = (api_t *)malloc(sizeof(api_t));

    api->events = list_init();
    api->mode = normal;
    api->songdata = songdata;


    api->key = TK_F1;
    generic_update(api);
    run_events(api->events, false);

    api->key = TK_DOWN;
    generic_update(api);
    run_events(api->events, false);

    list_destruct(api->events);
    songdata_destruct(songdata);
    free(api);
}

