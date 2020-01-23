#include "FileIO/Serialization/BasicSerialization.h"
#include "FileIO/Serialization/ListSerialization.h"
#include "FileIO/Serialization/ObjectSerialization.h"
#include "FileIO/Serialization/TagSerialization.h"
#include "Lists/ActorList.h"
#include "Lists/MovieList.h"
#include "Lists/RoleList.h"
#include "Lists/StudioList.h"

void serializeActorList(DatabaseFile* file, const ActorList* list) {

    for(ActorListNode* node = list->head; node != 0; node = node->next) {

        startObjectSerialization(file);
        serializeAddress(file, &node->value);
        serializeActor(file, &node->value);
        endObjectSerialization(file);

    }

}

void serializeMovieList(DatabaseFile* file, const MovieList* list) {

    for(MovieListNode* node = list->head; node != 0; node = node->next) {

        startObjectSerialization(file);
        serializeAddress(file, &node->value);
        serializeMovie(file, &node->value);
        endObjectSerialization(file);

    }

}

void serializeRoleList(DatabaseFile* file, const RoleList* list) {

    for(RoleListNode* node = list->head; node != 0; node = node->next) {

        startObjectSerialization(file);
        serializeRole(file, &node->value);
        endObjectSerialization(file);

    }

}

void serializeStudioList(DatabaseFile* file, const StudioList* list) {

    for(StudioListNode* node = list->head; node != 0; node = node->next) {

        startObjectSerialization(file);
        serializeAddress(file, &node->value);
        serializeStudio(file, &node->value);
        endObjectSerialization(file);

    }

}
