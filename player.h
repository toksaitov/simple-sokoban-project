#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "levels.h"
#include "sounds.h"

#include <cstddef>

void spawn_player(size_t row, size_t column) {
    player_row = row;
    player_column = column;
}

void move_player(int dx, int dy) {
    int next_row    = static_cast<int>(player_row)    + dy;
    int next_column = static_cast<int>(player_column) + dx;
    if (!is_cell_inside_level(next_row, next_column)) {
        return;
    }

    char &cell = get_level_cell(static_cast<size_t>(next_row), static_cast<size_t>(next_column));
    if (cell == FLOOR || cell == GOAL) {
        player_row    = static_cast<size_t>(next_row);
        player_column = static_cast<size_t>(next_column);
    } else if (cell == BOX || cell == BOX_ON_GOAL) {
        int target_row    = next_row    + dy;
        int target_column = next_column + dx;
        if (!is_cell_inside_level(target_row, target_column)) {
            return;
        }
        char &target_cell = get_level_cell(static_cast<size_t>(target_row), static_cast<size_t>(target_column));
        if (target_cell == FLOOR || target_cell == GOAL) {
            cell = cell == BOX ? FLOOR : GOAL;
            if (target_cell == FLOOR) {
                target_cell = BOX;
            } else {
                target_cell = BOX_ON_GOAL;
                play_sound(goal_sound);
            }

            player_row    = static_cast<size_t>(next_row);
            player_column = static_cast<size_t>(next_column);

            bool level_solved = true;
            for (size_t row = 0; level_solved && row < level.rows; ++row) {
                for (size_t column = 0; level_solved && column < level.columns; ++column) {
                    char cell_to_test = get_level_cell(row, column);
                    if (cell_to_test == GOAL) {
                        level_solved = false;
                    }
                }
            }

            if (level_solved) {
                unload_level();
                load_next_level();
                play_sound(exit_sound);
            }
        }
    }
}

#endif // PLAYER_H
