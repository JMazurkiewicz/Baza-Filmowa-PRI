#pragma once

#include "FileIO/DatabaseFile.h"
#include "Lists/Declarations.h"
#include <stdbool.h>

bool deserializeMovieList(DatabaseFile* file, Database* database);
