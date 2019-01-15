#pragma once

#include "Lists/Declarations.h"
#include <stdbool.h>

void newDatabase(Database* database);

bool saveDatabaseIfModified(Database* database, StringView message);
void saveDatabaseToFile(Database* database);
void saveDatabaseAs(Database* database);
