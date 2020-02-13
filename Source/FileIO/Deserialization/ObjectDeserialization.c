#include "BasicDeserialization.h"
#include "ObjectDeserialization.h"
#include "Objects/Actor.h"
#include "Objects/Movie.h"
#include "Objects/Role.h"
#include "Objects/Studio.h"

void deserializeActor(DatabaseFile* file, Actor* actor) {
    deserializeString(file, actor->name);
    deserializeString(file, actor->lastName);
    actor->yearOfBirth = deserializeInt32(file);
}

void deserializeMovie(DatabaseFile* file, Movie* movie) {
    deserializeString(file, movie->title);
    deserializeString(file, movie->director);
    movie->runningTime = deserializeInt32(file);
    movie->studio = deserializeAddress(file);
}

void deserializeRole(DatabaseFile* file, Role* role) {
    role->actor = deserializeAddress(file);
    role->movie = deserializeAddress(file);
}

void deserializeStudio(DatabaseFile* file, Studio* studio) {
    deserializeString(file, studio->name);
    deserializeString(file, studio->address);
    deserializeString(file, studio->contact);
    studio->yearOfFounding = deserializeInt32(file);
}
