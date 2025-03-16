#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "http.h"

int main() {
    // Test 1, test the header is properly constructed
    time_t rawtime = (time_t)1742088261; // Sat Mar 15 21:24:21 EDT 2025

    char* header = build_header(200, "OK", &rawtime, 100, "text/plain");
    assert(header != NULL);
    printf("Received header:\n\r%s\n", header);
    char expected_header[1000];


    snprintf(expected_header, 1000, "HTTP/1.1 200 OK\r\n"
                                   "Date: Sat Mar 15 21:24:21 EDT 2025\r\n"
                                   "Connection: close\r\n"
                                   "Content-Length: 100\r\n"
                                   "Content-Type: text/plain\r\n\r\n");
    
    assert(strcmp(header, expected_header) == 0);
    
    // Test 2, add a body to the header
    char* body = "This is my body";
    char* response = build_response(header, body, strlen(body));
    assert(response != NULL);
    printf("Received response: \n\r%s\n", response);

    char expected_response[1000];
    snprintf(expected_response, 1000, "HTTP/1.1 200 OK\r\n"
                                    "Date: Sat Mar 15 21:24:21 EDT 2025\r\n"
                                    "Connection: close\r\n"
                                    "Content-Length: 100\r\n"
                                    "Content-Type: text/plain\r\n"
                                    "\r\n"
                                    "This is my body"
                                    "\r\n");
    assert(strcmp(response, expected_response) == 0);

    return 0;
}