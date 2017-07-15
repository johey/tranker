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

TEST(Songdata, TrackFramePatternNotes) {
    songdata_t *songdata = songdata_init();
    track_t *track = track_init();
    frame_t *frame = frame_init();
    pattern_t *pattern = pattern_init();

    pattern_set_note_at(pattern, NOTE_A, 5);
    frame->pattern = pattern;
    list_push_back(track->frames, frame);

    free(list_get_at(track->frames, 0));
    pattern_destruct(pattern);
    frame_destruct(frame);
    track_destruct(track);
    songdata_destruct(songdata);
}

