#pragma once

#include "Lists/Declarations.h"

void newDatabase(Database* database);

void saveDatabaseIfModified(Database* database, StringView message);
void saveDatabaseToFile(Database* database);
void saveDatabaseAs(Database* database);
