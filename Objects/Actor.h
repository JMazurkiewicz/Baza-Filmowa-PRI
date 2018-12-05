#pragma once

#include <stdbool.h>
#include "Utility/String.h"

typedef struct Actor {

    String name;
    String lastName;
    int yearOfBirth;

} Actor;

bool hasActorTheseNames(const Actor* actor, StringView name, StringView lastName);

void scanActor(Actor* actor);
void printActor(const Actor* actor);
