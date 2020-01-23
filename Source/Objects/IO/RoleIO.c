#include "CommonIO/BasicIO.h"
#include "Lists/Database.h"
#include "Objects/Role.h"

bool scanRoleFromDatabase(Role* role, Database* database) {

    String name, lastName;
    scanActorsFullName(name, lastName);

    role->actor = findActor(&database->actors, name, lastName);

    if(role->actor == NULL) {

        puts("\aTaki aktor nie istnieje w bazie!");
        return false;

    } else {

        String title;
        scanMoviesTitle(title);

        role->movie = findMovie(&database->movies, title);

        if(role->movie == NULL) {

            puts("\aTaki film nie istnieje w bazie!");
            return false;

        }

    }

    return true;

}
