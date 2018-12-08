#pragma once

#include "Objects/Studio.h"
#include <stdbool.h>

typedef struct StudioListNode {

    struct StudioListNode* next;
    Studio value;

} StudioListNode;

typedef struct StudioList {

    StudioListNode* head;

} StudioList;

void initStudioList(StudioList* list);
void freeStudioList(StudioList* list);

bool addStudio(StudioList* list, const Studio* studio);
const Studio* findStudio(const StudioList* list, StringView studioName);
bool deleteStudio(StudioList* list, StringView studioName);
