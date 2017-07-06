#include "../songdata.c"

TEST(Songdata, Init) {
    songdata_t *songdata = songdata_init();
    track_t *track = track_init();

    songdata_track_pushback(songdata, track);

    track_destruct(track);
    songdata_destruct(songdata);
}

