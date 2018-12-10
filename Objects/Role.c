#include "Objects/Role.h"

bool isThisRoleOfActor(const Role* role, const Actor* actor) {
    return role->actor == actor;
}

bool isThisRoleFromMovie(const Role* role, const Movie* movie) {
    return role->movie == movie;
}

bool hasRoleTheseMembers(const Role* role, const Actor* actor, const Movie* movie) {
    return isThisRoleOfActor(role, actor) && isThisRoleFromMovie(role, movie);
}
