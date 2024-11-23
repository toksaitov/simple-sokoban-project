#ifndef LEVELS_H
#define LEVELS_H

#include "globals.h"
#include "player.h"
#include "graphics.h"

#include <cstddef>

void load_next_level() {
    ++level_index;
    if (level_index >= LEVEL_COUNT) {
        level_index = 0;
        game_state = VICTORY_STATE;
        create_victory_menu_background();
    }

    level.rows    = LEVELS[level_index].rows;
    level.columns = LEVELS[level_index].columns;
    level.data = new char[level.rows * level.columns];

    for (size_t row = 0; row < level.rows; ++row) {
        for (size_t column = 0; column < level.columns; ++column) {
            char cell = LEVELS[level_index].data[row * level.columns + column];
            if (cell == PLAYER) {
                set_level_cell(row, column, FLOOR);
                spawn_player(row, column);
            } else if (cell == PLAYER_ON_GOAL) {
                set_level_cell(row, column, GOAL);
                spawn_player(row, column);
            } else {
                set_level_cell(row, column, cell);
            }
        }
    }

    derive_graphics_metrics_from_loaded_level();
}

void unload_level() {
    level.rows    = 0;
    level.columns = 0;

    delete[] level.data;
    level.data = nullptr;
}

bool is_cell_inside_level(int row, int column) {
    return row < level.rows && column < level.columns;
}

char& get_level_cell(size_t row, size_t column) {
    return level.data[row * level.columns + column];
}

void set_level_cell(size_t row, size_t column, char cell) {
    level.data[row * level.columns + column] = cell;
}

#endif // LEVELS_H
