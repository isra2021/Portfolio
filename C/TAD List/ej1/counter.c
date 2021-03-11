#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter init(void) {
    counter c = (counter) malloc(sizeof(struct _counter));
    if(c == NULL) return NULL;
    c -> count = 0;
    return c;
}

void inc(counter c) {
    assert(c != NULL);
    c -> count += 1;
}

bool is_init(counter c) {
    assert(c != NULL);
    return c -> count == 0;
}

void dec(counter c) {
    assert(c != NULL && !is_init(c));
    c -> count -= 1;
}

counter copy_counter(counter c) {
    assert(c != NULL);
    counter copy = init();
    copy -> count = c -> count;
    return copy;
}

void destroy_counter(counter c) {
    assert(c != NULL);
    free(c);
    c = NULL;
}
