#include "../singelton.h"

void *singelton1(void *data) {
    return (void *)"singelton1";
}

void *singelton2(void *data) {
    return (void *)"singelton2";
}

TEST(Singelton, InitAndUpdate) {
    singelton_t s1, s2;
    char *c1, *c2;

    s1.update = singelton1;
    s2.update = singelton2;
    
    active = &s1;
    c1 = (char *)(active->update(NULL));

    active = &s2;
    c2 = (char *)(active->update(NULL));

    ASSERT_EQ("singelton1", c1);
    ASSERT_EQ("singelton2", c2);
}

