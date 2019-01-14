#include "FileIO/Serialization/BasicSerialization.h"
#include "FileIO/Serialization/ObjectSerialization.h"
#include "Objects/Actor.h"
#include "Objects/Movie.h"
#include "Objects/Role.h"
#include "Objects/Studio.h"

void serializeActor(DatabaseFile* file, const Actor* actor) {

    serializeString(file, actor->name);
    serializeString(file, actor->lastName);
    serializeInt32(file, actor->yearOfBirth);

}

void serializeMovie(DatabaseFile* file, const Movie* movie) {

    serializeString(file, movie->title);
    serializeString(file, movie->director);
    serializeInt32(file, movie->runningTime);
    serializeAddress(file, movie->studio);

}

void serializeRole(DatabaseFile* file, const Role* role) {

    serializeAddress(file, role->actor);
    serializeAddress(file, role->movie);

}

void serializeStudio(DatabaseFile* file, const Studio* studio) {

    serializeString(file, studio->name);
    serializeString(file, studio->address);
    serializeString(file, studio->contact);
    serializeInt32(file, studio->yearOfFounding);

}
