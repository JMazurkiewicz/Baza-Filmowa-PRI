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
void scanActor(Actor* actor);

void printActor(const Actor* actor);
