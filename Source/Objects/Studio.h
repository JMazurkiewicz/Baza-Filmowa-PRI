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

#define MIN_STUDIOS_YEAR_OF_FOUNDING (1888)
#define MAX_STUDIOS_YEAR_OF_FOUNDING (2019)

bool hasStudioThisName(const Studio* studio, StringView name);

void scanStudiosName(String name);
void scanStudiosIdentifier(Studio* studio);
void scanStudiosData(Studio* studio);

void printStudiosName(const Studio* studio);
void printStudio(const Studio* studio);
