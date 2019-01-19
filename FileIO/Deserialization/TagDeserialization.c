#include "FileIO/Deserialization/BasicDeserialization.h"
#include "FileIO/Deserialization/TagDeserialization.h"
#include "FileIO/Tag.h"

void deserializeHeader(DatabaseFile* file) {
    deserializeInt64(file);
}

Date deserializeDate(StringView path) {

    DatabaseFile file;
    if(!openInputFile(&file, path)) {
        const Date empty = {0};
        return empty;
    }

    long long dateValue = deserializeInt64(&file);
    closeDatabaseFile(&file);

    Date result;
    longLongToDate(dateValue, &result);
    return result;

}

bool startListDeserialization(DatabaseFile* file) {
    return deserializeByte(file) == START_OF_LIST;
}

bool endObjectDeserialization(DatabaseFile* file) {
    return deserializeByte(file) == END_OF_OBJECT;
}
