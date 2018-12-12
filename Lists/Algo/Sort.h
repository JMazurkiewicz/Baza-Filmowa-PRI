#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef bool (*SortCompare)(const void*, const void*);

void listSort(void* list, size_t valueOffset, SortCompare compare);
