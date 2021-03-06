typedef unsigned char bool;
#define false 0
#define true 1

#define NUMARGS(type, ...) (sizeof((type[]){0.0f, ##__VA_ARGS__}) / sizeof(type) - 1)

void swap(int *a, int *b);

void swapFloat(float *a, float *b);