#pragma once

#include "Objects/Declarations.h"
#include "Utility/String.h"

void scanActorsFullName(String name, String lastName);

void scanActorsIdentifiers(Actor* actor);
void scanActorsData(Actor* actor);

void printActor(const Actor* actor);
