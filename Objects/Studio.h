#pragma once

#include "Objects/Declarations.h"
#include <stdbool.h>
#include "Utility/String.h"

struct Studio {

    String name;
    String address;
    String contact;
    int yearOfFounding;

};

bool hasStudioThisName(const Studio* studio, StringView name);

void scanStudiosName(String name);
void scanStudio(Studio* studio);

void printStudio(const Studio* studio);
