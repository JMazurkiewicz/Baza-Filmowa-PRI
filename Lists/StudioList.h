#pragma once

#include "Objects/Studio.h"
#include <stdbool.h>

typedef struct StudioListNode {

    struct StudioListNode* next;
    Studio value;

} StudioListNode;

bool addStudio(StudioListNode* head, Studio studio);
Studio* findStudio(StudioListNode* head, StringView studioName);
bool deleteStudio(StudioListNode* head, StringView studioName);

void freeStudioListMemory(StudioListNode* head);
