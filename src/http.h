#ifndef _HTTP_H_
#define _HTTP_H_

/**
* Function to build and HTTP header.
*/
extern char* build_header(int status_code, char* status_msg, int status_msg_len, time_t* rawtime, int content_length, char* content_type, int content_type_len);
extern char* build_response(char* header, char* body, int body_size);

#endif

