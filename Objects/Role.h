#pragma once

#include "Objects/Declarations.h"
#include <stdbool.h>

struct Role {

    const Actor* actor;
    const Movie* movie;

};

bool isThisRoleOfActor(const Role* role, const Actor* actor);
bool isThisRoleFromMovie(const Role* role, const Movie* movie);
bool hasRoleTheseMembers(const Role* role, const Actor* actor, const Movie* movie);
