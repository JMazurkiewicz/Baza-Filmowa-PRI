#pragma once

#include "Objects/Actor.h"
#include "Objects/Movie.h"
#include <stdbool.h>

typedef struct Role {

    const Actor* actor;
    const Movie* movie;

} Role;

bool hasRoleTheseParams(const Role* role, const Actor* actor, const Movie* movie);
