#include <stdlib.h>
#include <assert.h>
#include "cache.h"

int main() {
    // Test cache_create returns a struct cache pointer
    struct cache* ptr = cache_create(3, 4);
    assert(ptr != NULL);
    free(ptr);
    return 0;
}