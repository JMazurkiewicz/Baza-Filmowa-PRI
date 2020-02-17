cmake_minimum_required(VERSION 3.10)
project(Movie-DB-PRI C)

set(COMMON_IO_DIR Source/CommonIO)

set(FILE_IO_DIR Source/FileIO)
set(DESERIALIZATION_DIR ${FILE_IO_DIR}/Deserialization)
set(SERIALIZATION_DIR ${FILE_IO_DIR}/Serialization)

set(LISTS_DIR Source/Lists)
set(OBJECTS_DIR Source/Objects)

set(UI_DIR Source/UserInterface)
set(SUBMENUS_DIR ${UI_DIR}/Submenus)
set(SORT_MENUS_DIR ${SUBMENUS_DIR}/SortMenu)

set(UTILITY_DIR Source/Utility)

set(SOURCES

    Source/Main.c

    ${COMMON_IO_DIR}/BasicIO.c
    ${COMMON_IO_DIR}/ConditionalInput.c
    ${COMMON_IO_DIR}/NameInput.c

    ${FILE_IO_DIR}/DatabaseFile.c
    ${FILE_IO_DIR}/Deserialization.c
    ${FILE_IO_DIR}/FileSystem.c
    ${FILE_IO_DIR}/Serialization.c

    ${DESERIALIZATION_DIR}/ActorListDeserialization.c
    ${DESERIALIZATION_DIR}/BasicDeserialization.c
    ${DESERIALIZATION_DIR}/MovieListDeserialization.c
    ${DESERIALIZATION_DIR}/ObjectDeserialization.c
    ${DESERIALIZATION_DIR}/RoleListDeserialization.c
    ${DESERIALIZATION_DIR}/StudioListDeserialization.c
    ${DESERIALIZATION_DIR}/TagDeserialization.c

    ${SERIALIZATION_DIR}/BasicSerialization.c
    ${SERIALIZATION_DIR}/ListSerialization.c
    ${SERIALIZATION_DIR}/ObjectSerialization.c
    ${SERIALIZATION_DIR}/TagSerialization.c

    ${LISTS_DIR}/Algo/Sort.c
    ${LISTS_DIR}/ActorList.c
    ${LISTS_DIR}/IO/ActorListIO.c
    ${LISTS_DIR}/Database.c
    ${LISTS_DIR}/MovieList.c
    ${LISTS_DIR}/IO/MovieListIO.c
    ${LISTS_DIR}/RoleList.c
    ${LISTS_DIR}/IO/RoleListIO.c
    ${LISTS_DIR}/StudioList.c
    ${LISTS_DIR}/IO/StudioListIO.c

    ${OBJECTS_DIR}/Actor.c
    ${OBJECTS_DIR}/IO/ActorIO.c
    ${OBJECTS_DIR}/Movie.c
    ${OBJECTS_DIR}/IO/MovieIO.c
    ${OBJECTS_DIR}/Role.c
    ${OBJECTS_DIR}/IO/RoleIO.c
    ${OBJECTS_DIR}/Studio.c
    ${OBJECTS_DIR}/IO/StudioIO.c

    ${UI_DIR}/Backup.c
    ${UI_DIR}/Logo.c
    ${UI_DIR}/MainMenu.c
    ${UI_DIR}/MenuPlayer.c
    ${UI_DIR}/Messages.c

    ${SUBMENUS_DIR}/DatabaseDeletionMenu.c
    ${SUBMENUS_DIR}/DeletionMenu.c
    ${SUBMENUS_DIR}/DeserializationMenu.c
    ${SUBMENUS_DIR}/InsertionMenu.c
    ${SUBMENUS_DIR}/Instructions.c
    ${SUBMENUS_DIR}/QueryMenu.c
    ${SUBMENUS_DIR}/SerializationMenus.c
    ${SUBMENUS_DIR}/SortMenu.c

    ${SORT_MENUS_DIR}/ActorListSortMenu.c
    ${SORT_MENUS_DIR}/MovieListSortMenu.c
    ${SORT_MENUS_DIR}/StudioListSortMenu.c

    ${UTILITY_DIR}/Date.c
    ${UTILITY_DIR}/String.c

)

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

add_executable(Movie-DB-PRI ${SOURCES})
include_directories(${CMAKE_SOURCE_DIR}/Source)
