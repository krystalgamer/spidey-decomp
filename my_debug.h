#ifndef MY_DEBUG_H
#define MY_DEBUG_H

#define DEBUG_LOG

#ifdef DEBUG_LOG
#define DEBUG_PRINT(x)  my_debug_print(x);
#define DEBUG_PRINT_ONE(x, y)  my_debug_print(x, y);
#define DEBUG_PRINT_TWO(x, y, z)  my_debug_print(x, y, z);
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINT_ONE(x, y)
#define DEBUG_PRINT_TWO(x, y, z)
#endif

#ifdef DEBUG_LOG
void my_debug_print(const char* message, ...);
#endif

#endif
