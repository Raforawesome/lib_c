#if !defined(stdlib)
#include <stdlib.h>
#endif // stdlib
#if !defined(stdio)
#include <stdio.h>
#endif // stdio



#if !defined(STRING)
#define STRING


struct String {
	int length;
	char* start;
}
typedef struct String String;


#endif // STRING
