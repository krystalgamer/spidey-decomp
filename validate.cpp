#include "validate.h"
#include <cstdarg>

int FAIL_VALIDATION = 0;

void validate_class(int cur, int expected, const char *cls, const char *member){

	if (expected != cur){
		FAIL_VALIDATION = 1;
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
		FAIL_VALIDATION = 1;
		printf("[!] Expected %d but got %d, size of %s\n", expected, cur, name);
	}
	else{

#ifdef _VALIDATE_SUCCESS
		printf("[!] SUGG my dicgg\n");
#endif
	}

	fflush(stdout);
}

u32* get_thunk_address(void* first,...)
{
	va_list args;
	va_start(args, first);

	u32* res = va_arg(args, u32*);
	va_end(args);
	return res;
}

void validate_vtable_index(
		u32 expected_index,
		const u32* known_address,
		const char *cls,
		const char *name)
{

#ifdef _OLD_WINDOWS
	u32 bytes = *known_address;
	if (bytes != 0x60FF018B)
	{
		FAIL_VALIDATION = 1;
		printf("[!] Invalid bytes - %08X - at address - %08X - for %s->%s\n", bytes, known_address, cls, name);
	}
	else
	{
		u32 cur_index = reinterpret_cast<const u8*>(known_address)[4];
		cur_index /= 4;

		if (cur_index != expected_index)
		{
			FAIL_VALIDATION = 1;
			printf("[!] Invalid index for %s->%s, expected %u but got %u - %08X\n", cls, name, expected_index, cur_index, known_address);
		}
	}

	fflush(stdout);
#endif
}
