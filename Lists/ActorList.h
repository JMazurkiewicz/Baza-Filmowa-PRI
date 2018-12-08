#pragma once

#include "Objects/Actor.h"
#include <stdbool.h>
#include "Utility/String.h"

typedef struct ActorListNode {

    struct ActorListNode* next;
    Actor value;

} ActorListNode;

typedef struct ActorList {

    ActorListNode* head;

} ActorList;

void initActorList(ActorList* list);
void freeActorList(ActorList* list);

bool addActor(ActorList* list, const Actor* actor);
const Actor* findActor(const ActorList* list, StringView name, StringView lastName);
bool deleteActor(ActorList* list, StringView name, StringView lastName);
