#include "CommonIO/BasicIO.h"
#include "Lists/ActorList.h"
#include "Lists/RoleList.h"
#include "Objects/Role.h"

static void printActorOnList(const Actor* actor);

void printActorList(const ActorList* list) {

    if(isActorListEmpty(list)) {

        puts("Lista aktorow jest pusta!");

    } else {

        puts("Lista aktorow:");
        for(const ActorListNode* node = list->head; node != NULL; node = node->next) {
            printActorOnList(&node->value);
        }

    }

}

void printActorsWorkingWithStudio(const ActorList* actors, const RoleList* roles, const Studio* studio) {

    bool noResults = true;

    for(const ActorListNode* actorNode = actors->head; actorNode != NULL; actorNode = actorNode->next) {

        for(const RoleListNode* roleNode = roles->head; roleNode != NULL; roleNode = roleNode->next) {

            if(isThisRoleOfActor(&roleNode->value, &actorNode->value) &&
                isThisRoleFromMovieOfStudio(&roleNode->value, studio)) {

                if(noResults) {
                    noResults = false;
                    puts("Lista aktorow wspolpracujacych ze studiem:");
                }

                printActorOnList(&actorNode->value);
                break;

            }

        }

    }

    if(noResults) {
        puts("Zaden aktor nie wspolpracowal z tym studiem.");
    }

}

void printActorOnList(const Actor* actor) {
    printString("- ");
    printActorsFullName(actor);
    newLine();
}
