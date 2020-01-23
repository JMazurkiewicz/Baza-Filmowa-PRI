#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef bool (*CompareFunction)(const void*, const void*);

bool listSort(void* list, size_t valueOffset, CompareFunction compare);
