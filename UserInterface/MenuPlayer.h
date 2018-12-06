#pragma once

#include <stdbool.h>
#include "Utility/String.h"

typedef struct MenuData {

    StringView content;
    int maxOptionValue;

} MenuData;

int playMenu(const MenuData* data);
