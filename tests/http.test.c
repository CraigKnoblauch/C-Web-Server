#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "http.h"

int main() {
    time_t rawtime = (time_t)1742088261; // Sat Mar 15 21:24:21 EDT 2025

    char* header = build_header(200, "OK", 2, &rawtime, 100, "text/plain", 10);
    assert(header != NULL);
    printf("Received header:\n\r%s\n", header);
    char expected_header[1000];


    snprintf(expected_header, 1000, "HTTP/1.1 200 OK\r\n"
                                   "Date: Sat Mar 15 21:24:21 EDT 2025\r\n"
                                   "Connection: close\r\n"
                                   "Content-Length: 100\r\n"
                                   "Content-Type: text/plain\r\n\r\n");
    
    assert(strcmp(header, expected_header) == 0);
    free(header);
    return 0;
}