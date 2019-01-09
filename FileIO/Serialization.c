#include "FileIO/Serialization.h"
#include "FileIO/Serialization/ListSerialization.h"
#include "FileIO/Serialization/TagSerialization.h"
#include "Lists/Database.h"

void serializeDatabase(DatabaseFile* file, const Database* database) {

    serializeHeader(file);

    startListSerialization(file);
    serializeActorList(file, &database->actors);
    endListSerialization(file);

    startListSerialization(file);
    serializeMovieList(file, &database->movies);
    endListSerialization(file);

    startListSerialization(file);
    serializeRoleList(file, &database->roles);
    endListSerialization(file);

    startListSerialization(file);
    serializeStudioList(file, &database->studios);
    endListSerialization(file);

}
