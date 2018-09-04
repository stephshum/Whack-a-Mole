#include <string.h>
#include "MK64F12.h"

#define GAME_INIT 0
#define GAME_START 1
#define GAME_PAUSE 2
#define GAME_END 3

void game_init(void);
void game_run(void);

void game_update(void);
void game_update_beta(void);
void display_update(uint16_t buf[8]);

void clear_disp(void);