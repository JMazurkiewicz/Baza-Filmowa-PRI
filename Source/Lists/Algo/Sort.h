#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef bool (*SortCompareFunction)(const void*, const void*);

bool listSort(void* list, size_t valueOffset, SortCompareFunction compare);
