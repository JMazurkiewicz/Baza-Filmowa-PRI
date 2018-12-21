#pragma once

typedef enum MainMenuResult {

    MAIN_MENU_INSERT = 1,
    MAIN_MENU_DELETE,
    MAIN_MENU_QUERY,
    MAIN_MENU_SORT,
    MAIN_MENU_INSTRUCTIONS,

    MAIN_MENU_SAVE,
    MAIN_MENU_SAVE_AS,
    MAIN_MENU_LOAD,

    MAIN_MENU_EXIT

} MainMenuResult;

MainMenuResult mainMenu(void);
