#include "../songdata.c"

TEST(Songdata, Init) {
    songdata_t *songdata = songdata_init();

    ASSERT_EQ(0, list_count(songdata->tracks));

    list_push_back(songdata->tracks, track_init());
    list_push_back(songdata->tracks, track_init());
    list_push_back(songdata->tracks, track_init());
    list_push_back(songdata->tracks, track_init());
    list_push_back(songdata->tracks, track_init());

    ASSERT_EQ(5, list_count(songdata->tracks));

    songdata_destruct(songdata);
}

