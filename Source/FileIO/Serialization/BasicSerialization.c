#include "BasicSerialization.h"

void serializeByte(DatabaseFile* file, Byte byte) {
    fputc(byte + file->key, file->handle);
}

void serializeInteger(DatabaseFile* file, const Byte* firstByte, size_t width) {

#if defined(LITTLE_ENDIAN)

    while(width--) {
        serializeByte(file, *firstByte++);
    }

#elif defined(BIG_ENDIAN)

    firstByte += width;
    while(width--) {
        serializeByte(file, *--firstByte);
    }

#endif

}

void serializeInt32(DatabaseFile* file, int32_t integer) {
    serializeInteger(file, (const Byte*)&integer, 4);
}

void serializeInt64(DatabaseFile* file, int64_t integer) {
    serializeInteger(file, (const Byte*)&integer, 8);
}

void serializeAddress(DatabaseFile* file, const void* address) {
    serializeInt64(file, (intptr_t)address);
}

void serializeString(DatabaseFile* file, StringView string) {

    serializeByte(file, (Byte)strlen(string));

    while(*string != '\0') {
        serializeByte(file, (Byte)*string);
        ++string;
    }

}
