#pragma once

#include "Objects/Actor.h"
#include <stdbool.h>
#include "Utility/String.h"

typedef struct ActorListNode {

    struct ActorListNode* next;
    Actor value;

} ActorListNode;

bool addActor(ActorListNode* head, Actor actor);
Actor* findActor(ActorListNode* head, StringView name, StringView lastName);
bool deleteActor(ActorListNode* head, StringView name, StringView lastName);

void freeActorListMemory(ActorListNode* head);
