#include "CommonIO/BasicIO.h"
#include "Lists/Database.h"
#include "Objects/Role.h"

bool scanRole(Role* role, Database* database) {

    String name, lastName;
    scanActorsFullName(name, lastName);

    role->actor = findActor(&database->actors, name, lastName);

    if(role->actor == NULL) {

        puts("Taki aktor nie istnieje w bazie!");
        return false;

    } else {

        String title;
        scanMoviesTitle(title);

        role->movie = findMovie(&database->movies, title);

        if(role->movie == NULL) {

            puts("Taki film nie istnieje w bazie!");
            return false;

        }

    }

    return true;

}
