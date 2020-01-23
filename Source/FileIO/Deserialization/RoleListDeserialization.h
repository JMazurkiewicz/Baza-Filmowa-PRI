#pragma once

#include "FileIO/DatabaseFile.h"
#include "Lists/Declarations.h"
#include <stdbool.h>

bool deserializeRoleList(DatabaseFile* file, Database* database);
