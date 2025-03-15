#include <stdlib.h>
#include <assert.h>
#include "llist.h"

int main() {
    // Test llist_create returns a struct llist pointer
    struct llist* ptr = llist_create();
    assert(ptr != NULL);
    free(ptr);
    return 0;
}