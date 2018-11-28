#pragma once

typedef enum MainMenuResult {

    OPTION_ADD = '1',
    OPTION_DELETE,
    OPTION_QUERY,
    OPTION_SORT,
    OPTION_SAVE_TO_FILE,
    OPTION_LOAD_FROM_FILE,
    OPTION_EXIT

} MainMenuResult;

MainMenuResult MainMenu(void);
