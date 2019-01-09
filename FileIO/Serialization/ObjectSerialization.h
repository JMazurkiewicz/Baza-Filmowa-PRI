#pragma once

#include "FileIO/DatabaseFile.h"
#include "Objects/Declarations.h"

void serializeActor(DatabaseFile* file, const Actor* actor);
void serializeMovie(DatabaseFile* file, const Movie* movie);
void serializeRole(DatabaseFile* file, const Role* role);
void serializeStudio(DatabaseFile* file, const Studio* studio);
