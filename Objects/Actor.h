#pragma once

#include "Objects/Declarations.h"
#include <stdbool.h>
#include "Utility/String.h"

struct Actor {

    String name;
    String lastName;
    int yearOfBirth;

};

bool hasActorTheseNames(const Actor* actor, StringView name, StringView lastName);

void scanActorsFullName(String name, String lastName);

void scanActorsIdentifiers(Actor* actor);
void scanActorsData(Actor* actor);

void printActorsFullName(const Actor* actor);
void printActor(const Actor* actor);
