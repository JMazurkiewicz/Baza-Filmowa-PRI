#pragma once

#include "FileIO/DatabaseFile.h"
#include "Lists/Declarations.h"

void serializeDatabase(DatabaseFile* file, const Database* database);
