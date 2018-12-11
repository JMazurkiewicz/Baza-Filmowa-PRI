#pragma once

#include "Lists/Declarations.h"
#include "Objects/Studio.h"
#include <stdbool.h>
#include "Utility/String.h"

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
Studio* findStudio(StudioList* list, StringView studioName);
bool deleteStudio(StudioList* list, StringView studioName);

const Studio* scanStudioOfMovie(StudioList* studios);

void printStudioList(const StudioList* studios);
