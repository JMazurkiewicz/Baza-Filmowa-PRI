#pragma once

#include <stdbool.h>
#include "Utility/String.h"

typedef bool(*InputValidator)(int);

typedef struct MenuData {

    StringView content;
    InputValidator inputValidator;

} MenuData;

int playMenu(const MenuData* data);
