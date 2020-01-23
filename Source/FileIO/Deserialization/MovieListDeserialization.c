#include "FileIO/Deserialization/BasicDeserialization.h"
#include "FileIO/Deserialization/MovieListDeserialization.h"
#include "FileIO/Deserialization/ObjectDeserialization.h"
#include "FileIO/Deserialization/TagDeserialization.h"
#include "FileIO/Tag.h"
#include "Lists/Database.h"
#include <stdlib.h>

static void connectMovieWithRoles(void* movieId, Movie* newMovie, RoleList* roles);

bool deserializeMovieList(DatabaseFile* file, Database* database) {

    if(startListDeserialization(file)) {

        Byte nextTag;
        MovieListNode* currentNode = (MovieListNode*)(&database->movies);

        while((nextTag = deserializeByte(file)) == START_OF_OBJECT) {

            void* movieId = deserializeAddress(file);

            currentNode->next = malloc(sizeof(MovieListNode));
            deserializeMovie(file, &currentNode->next->value);
            connectMovieWithRoles(movieId, &currentNode->next->value, &database->roles);

            currentNode = currentNode->next;
            endObjectDeserialization(file);

        }

        currentNode->next = 0;
        return nextTag == END_OF_LIST;

    }

    return false;

}

void connectMovieWithRoles(void* movieId, Movie* newMovie, RoleList* roles) {

    for(RoleListNode* node = roles->head; node != 0; node = node->next) {

        if(node->value.movie == movieId) {
            node->value.movie = newMovie;
        }

    }

}
