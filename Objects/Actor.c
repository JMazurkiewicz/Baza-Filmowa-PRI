#include "Objects/Actor.h"

bool hasActorTheseNames(const Actor* actor, StringView name, StringView lastName) {
    return strcmp(actor->name, name) == 0 && strcmp(actor->lastName, lastName);
}
