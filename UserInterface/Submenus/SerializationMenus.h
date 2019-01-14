#pragma once

#include "Lists/Declarations.h"

void newDatabase(Database* database);
void saveDatabaseToFile(Database* database);
void saveDatabaseAs(Database* database);
void saveAtExit(Database* database);
void loadDatabaseFromFile(Database* database);
