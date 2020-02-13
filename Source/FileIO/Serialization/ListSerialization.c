#include "BasicSerialization.h"
#include "Lists/ActorList.h"
#include "Lists/MovieList.h"
#include "Lists/RoleList.h"
#include "Lists/StudioList.h"
#include "ListSerialization.h"
#include "ObjectSerialization.h"
#include "TagSerialization.h"

void serializeActorList(DatabaseFile* file, const ActorList* list) {

    for(ActorListNode* node = list->head; node != NULL; node = node->next) {

        startObjectSerialization(file);
        serializeAddress(file, &node->value);
        serializeActor(file, &node->value);
        endObjectSerialization(file);

    }

}

void serializeMovieList(DatabaseFile* file, const MovieList* list) {

    for(MovieListNode* node = list->head; node != NULL; node = node->next) {

        startObjectSerialization(file);
        serializeAddress(file, &node->value);
        serializeMovie(file, &node->value);
        endObjectSerialization(file);

    }

}

void serializeRoleList(DatabaseFile* file, const RoleList* list) {

    for(RoleListNode* node = list->head; node != NULL; node = node->next) {

        startObjectSerialization(file);
        serializeRole(file, &node->value);
        endObjectSerialization(file);

    }

}

void serializeStudioList(DatabaseFile* file, const StudioList* list) {

    for(StudioListNode* node = list->head; node != NULL; node = node->next) {

        startObjectSerialization(file);
        serializeAddress(file, &node->value);
        serializeStudio(file, &node->value);
        endObjectSerialization(file);

    }

}
