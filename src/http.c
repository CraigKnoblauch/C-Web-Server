#include <stdlib.h>
#include <time.h>


char* build_header(int status_code, char* status_msg, time_t* rawtime, int content_length, char* content_type) {
    // Build all components. Then you'll have total size so the right amount of memory can be allocated. Remember to use +1 for the null terminator
    char* header = malloc(1024); // Should be enough to capture header. Will realloc later if necessary

    // Get the current time
    struct tm *timeinfo;
    char date[80];

    // Format the date
    timeinfo = localtime(rawtime);
    strftime(date, sizeof(date), "%a %b %d %H:%M:%S %Z %Y", timeinfo);

    // Build the HTTP header
    snprintf(header, 1024, "HTTP/1.1 %d %s\r\n"
                           "Date: %s\r\n"
                           "Connection: close\r\n"
                           "Content-Length: %d\r\n"
                           "Content-Type: %s\r\n"
                           "\r\n",
             status_code, status_msg, date, content_length, content_type);

    // Reallocate to the actual size needed
    // char* resized_header = realloc(header, strlen(header)); 
    // free(header);

    // return resized_header;
    return header;
}

// Header should be null terminated.
char* build_response(char* header, char* body, int body_size) {
    char* response = malloc(strlen(header) + body_size + 1);
    strcpy(response, header);
    strncat(response, body, body_size);
    return response;
}