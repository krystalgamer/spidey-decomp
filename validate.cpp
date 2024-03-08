#include "validate.h"


void validate_class(int cur, int expected, const char *cls, const char *member){

	if (expected != cur){
		printf("[!] Expected %X but got %X, for %s->%s\n", expected, cur, cls, member);
	}
	else{

#ifdef _VALIDATE_SUCCESS
		printf("Success: Expected %X  for %s->%s\n", expected, cls, member);
#endif
	}

	fflush(stdout);
}

void validate_size(int cur, int expected, const char *name){
	if (expected != cur){
		printf("[!] Expected %d but got %d, size of %s\n", expected, cur, name);
	}
	else{

#ifdef _VALIDATE_SUCCESS
		printf("[!] SUGG my dicgg\n");
#endif
	}

	fflush(stdout);
}