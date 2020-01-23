#include "FileIO/Deserialization/ActorListDeserialization.h"
#include "FileIO/Deserialization/BasicDeserialization.h"
#include "FileIO/Deserialization/ObjectDeserialization.h"
#include "FileIO/Deserialization/TagDeserialization.h"
#include "FileIO/Tag.h"
#include "Lists/Database.h"
#include <stdlib.h>

static void connectActorWithRoles(void* actorId, Actor* newActor, RoleList* roles);

bool deserializeActorList(DatabaseFile* file, Database* database) {

    if(startListDeserialization(file)) {

        Byte nextTag;
        ActorListNode* currentNode = (ActorListNode*)(&database->actors);

        while((nextTag = deserializeByte(file)) == START_OF_OBJECT) {

            void* actorId = deserializeAddress(file);

            currentNode->next = malloc(sizeof(ActorListNode));
            deserializeActor(file, &currentNode->next->value);
            connectActorWithRoles(actorId, &currentNode->next->value, &database->roles);

            currentNode = currentNode->next;
            endObjectDeserialization(file);

        }

        currentNode->next = 0;
        return nextTag == END_OF_LIST;

    }

    return false;

}

void connectActorWithRoles(void* actorId, Actor* newActor, RoleList* roles) {

    for(RoleListNode* node = roles->head; node != 0; node = node->next) {

        if(node->value.actor == actorId) {
            node->value.actor = newActor;
        }

    }

}
