#pragma once

#include "FileIO/DatabaseFile.h"
#include "Lists/Declarations.h"
#include <stdbool.h>

bool deserializeStudioList(DatabaseFile* file, Database* database);
