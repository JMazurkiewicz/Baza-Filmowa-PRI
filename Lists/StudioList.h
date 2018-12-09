#pragma once

#include "Lists/Declarations.h"
#include "Objects/Studio.h"
#include <stdbool.h>

struct StudioListNode {

    StudioListNode* next;
    Studio value;

};

struct StudioList {

    StudioListNode* head;

};

void initStudioList(StudioList* list);
void freeStudioList(StudioList* list);

bool isStudioListEmpty(const StudioList* list);

void addStudio(StudioList* list, const Studio* studio);
const Studio* findStudio(const StudioList* list, StringView studioName);
bool deleteStudio(StudioList* list, StringView studioName);

void printStudioList(const StudioList* list);
