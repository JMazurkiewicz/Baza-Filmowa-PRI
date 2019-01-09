#pragma once

#include "FileIO/DatabaseFile.h"
#include "Lists/Declarations.h"

void serializeActorList(DatabaseFile* file, const ActorList* list);
void serializeMovieList(DatabaseFile* file, const MovieList* list);
void serializeRoleList(DatabaseFile* file, const RoleList* list);
void serializeStudioList(DatabaseFile* file, const StudioList* list);
