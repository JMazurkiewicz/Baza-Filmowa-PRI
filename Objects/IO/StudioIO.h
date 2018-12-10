#pragma once

#include "Objects/Declarations.h"
#include "Utility/String.h"

void scanStudiosName(String name);

void scanStudiosIdentifier(Studio* studio);
void scanStudiosData(Studio* studio);

void printStudiosName(const Studio* studio);
void printStudio(const Studio* studio);
