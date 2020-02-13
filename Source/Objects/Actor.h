#pragma once

#include "Declarations.h"
#include <stdbool.h>
#include "Utility/String.h"

struct Actor {
    String name;
    String lastName;
    int yearOfBirth;
};

#define MIN_ACTORS_YEAR_OF_BIRTH (1888)
#define MAX_ACTORS_YEAR_OF_BIRTH (2019)

bool hasActorTheseNames(const Actor* actor, StringView name, StringView lastName);

void scanActorsFullName(String name, String lastName);
void scanActorsIdentifiers(Actor* actor);
void scanActorsData(Actor* actor);

void printActorsFullName(const Actor* actor);
void printActor(const Actor* actor);
