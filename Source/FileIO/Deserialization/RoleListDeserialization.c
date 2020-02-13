#include "BasicDeserialization.h"
#include "FileIO/Tag.h"
#include "Lists/Database.h"
#include "ObjectDeserialization.h"
#include "RoleListDeserialization.h"
#include "TagDeserialization.h"


bool deserializeRoleList(DatabaseFile* file, Database* database) {

    if(startListDeserialization(file)) {

        Byte nextTag;

        while((nextTag = deserializeByte(file)) == START_OF_OBJECT) {

            Role newRole;
            deserializeRole(file, &newRole);
            addRole(&database->roles, newRole.actor, newRole.movie);

            endObjectDeserialization(file);

        }

        return nextTag == END_OF_LIST;

    }

    return false;

}
