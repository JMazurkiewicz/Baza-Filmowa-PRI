#pragma once

#include "Lists/Declarations.h"
#include "Objects/Actor.h"
#include <stdbool.h>
#include "Utility/String.h"

struct ActorListNode {

    ActorListNode* next;
    Actor value;

};

struct ActorList {

    ActorListNode* head;

};

void initActorList(ActorList* list);
void freeActorList(ActorList* list);

bool isActorListEmpty(const ActorList* list);

void addActor(ActorList* list, const Actor* actor);
const Actor* findActor(const ActorList* list, StringView name, StringView lastName);
bool deleteActor(ActorList* list, StringView name, StringView lastName);

void printActorList(const ActorList* list);
