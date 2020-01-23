#pragma once

#include "FileIO/DatabaseFile.h"
#include "Objects/Declarations.h"

void deserializeActor(DatabaseFile* file, Actor* actor);
void deserializeMovie(DatabaseFile* file, Movie* movie);
void deserializeRole(DatabaseFile* file, Role* role);
void deserializeStudio(DatabaseFile* file, Studio* studio);
