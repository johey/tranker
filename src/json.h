#ifndef __JSON_H
#define __JSON_H

typedef enum { j_string, j_int, j_boolean, j_list, j_dict } datatype_t;

void json_encode(char *name, char *value, datatype_t datatype);


#endif //__JSON_H

