#pragma once

#include "Objects/Declarations.h"
#include "Objects/IO/ActorIO.h"
#include <stdbool.h>
#include "Utility/String.h"

struct Actor {

    String name;
    String lastName;
    int yearOfBirth;

};

bool hasActorTheseNames(const Actor* actor, StringView name, StringView lastName);
