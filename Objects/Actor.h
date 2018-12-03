#pragma once

#include <stdbool.h>
#include "Utility/String.h"

extern const int MIN_ACTORS_YEAR_OF_BIRTH;
extern const int MAX_ACTORS_YEAR_OF_BIRTH;

typedef struct Actor {

    String name;
    String lastName;
    int yearOfBirth;

} Actor;

bool hasActorTheseNames(const Actor* actor, StringView name, StringView lastName);
void scanActor(Actor* actor);
