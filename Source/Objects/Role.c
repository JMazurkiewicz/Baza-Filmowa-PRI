#include "Objects/Movie.h"
#include "Objects/Role.h"

bool isThisRoleOfActor(const Role* role, const Actor* actor) {
    return role->actor == actor;
}

bool isThisRoleFromMovie(const Role* role, const Movie* movie) {
    return role->movie == movie;
}

bool isThisRoleFromMovieOfStudio(const Role* role, const Studio* studio) {
    return role->movie->studio == studio;
}

bool hasRoleTheseMembers(const Role* role, const Actor* actor, const Movie* movie) {
    return isThisRoleOfActor(role, actor) && isThisRoleFromMovie(role, movie);
}
