#if !defined(stdlib)
#include <stdlib.h>
#endif // stdlib


#if !defined(DYNARRAY)
#define DYNARRAY


struct DynIntArr {
	int length;
	int filled;
	int* start;
};

typedef struct DynIntArr DynIntArr;


DynIntArr newintarr() {
	int* addr = (int*) malloc(sizeof(int));
	DynIntArr ret;
	ret.length = 1;
	ret.filled = 0;
	ret.start = addr;
	return ret;
}


#endif // DYNARRAY
