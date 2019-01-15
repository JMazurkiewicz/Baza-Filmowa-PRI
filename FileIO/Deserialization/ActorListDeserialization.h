#pragma once

#include "FileIO/DatabaseFile.h"
#include "Lists/Declarations.h"
#include <stdbool.h>

bool deserializeActorList(DatabaseFile* file, Database* database);
