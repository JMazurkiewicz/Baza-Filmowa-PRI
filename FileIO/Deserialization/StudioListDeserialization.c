#include "FileIO/Deserialization/BasicDeserialization.h"
#include "FileIO/Deserialization/ObjectDeserialization.h"
#include "FileIO/Deserialization/StudioListDeserialization.h"
#include "FileIO/Deserialization/TagDeserialization.h"
#include "FileIO/Tag.h"
#include "Lists/Database.h"
#include <stdlib.h>

static void connectStudioWithMovies(void* studioId, Studio* newStudio, MovieList* movies);

bool deserializeStudioList(DatabaseFile* file, Database* database) {

    if(startListDeserialization(file)) {

        Byte nextTag;
        StudioListNode* currentNode = (StudioListNode*)(&database->studios);

        while((nextTag = deserializeByte(file)) == START_OF_OBJECT) {

            void* studioId = deserializeAddress(file);

            currentNode->next = malloc(sizeof(StudioListNode));
            deserializeStudio(file, &currentNode->next->value);
            connectStudioWithMovies(studioId, &currentNode->next->value, &database->movies);

            currentNode = currentNode->next;
            endObjectDeserialization(file);

        }

        currentNode->next = 0;
        return nextTag == END_OF_LIST;

    }

    return false;

}

void connectStudioWithMovies(void* studioId, Studio* newStudio, MovieList* movies) {

    for(MovieListNode* node = movies->head; node != 0; node = node->next) {

        if(node->value.studio == studioId) {
            node->value.studio = newStudio;
        }

    }

}
