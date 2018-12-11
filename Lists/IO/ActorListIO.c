#include "CommonIO/BasicIO.h"
#include "Lists/ActorList.h"
#include "Lists/RoleList.h"
#include "Objects/Role.h"

void printActorList(const ActorList* list) {

    if(isActorListEmpty(list)) {

        puts("Lista aktorow jest pusta!");

    } else {

        puts("Lista aktorow:");

        for(const ActorListNode* node = list->head; node != NULL; node = node->next) {

            printString("- ");
            printActorsFullName(&node->value);
            newLine();

        }

    }

}

void printActorsWorkingWithStudio(const ActorList* actors, const RoleList* roles, const Studio* studio) {

    bool noResults = true;

    for(const ActorListNode* actorNode = actors->head; actorNode != NULL; actorNode = actorNode->next) {

        for(const RoleListNode* roleNode = roles->head; roleNode != NULL; roleNode = roleNode->next)

            if(isThisRoleFromMovieOfStudio(&roleNode->value, studio)) {

                if(noResults) {
                    noResults = false;
                    puts("Lista aktorow wspolpracujacych ze studiem:");
                }

                printString("- ");
                printActorsFullName(&actorNode->value);
                newLine();
                break;

            }

    }

    if(noResults) {
        puts("Studio nie wspolpracowalo z zadnymi aktorami.");
    }

}
