#pragma once

#include "Utility/String.h"

typedef struct MenuData {

    StringView content;
    int maxOptionValue;

} MenuData;

int playMenu(const MenuData* menuData);
