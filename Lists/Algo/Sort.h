#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef bool (*Compare)(const void*, const void*);

void listSort(void* list, size_t valueOffset, Compare compare);
