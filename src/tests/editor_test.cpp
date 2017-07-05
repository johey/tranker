#include "../editor.c"

api_t api;

TEST(Editor, Singelton) {
    editor_singelton_init();
    active = &editor_singelton;
    active->update(&api); 
}

