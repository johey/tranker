#include "../songdata.c"

TEST(Songdata, Init) {
    songdata_t *songdata = songdata_init();

    songdata_track_new_pushback(songdata);
    songdata_track_new_pushback(songdata);
    songdata_track_new_pushback(songdata);
    songdata_track_new_pushback(songdata);
    songdata_track_new_pushback(songdata);

    songdata_destruct(songdata);
}

