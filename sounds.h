#ifndef SOUNDS_H
#define SOUNDS_H

#include "raylib.h"

#include "globals.h"

void load_sounds() {
    InitAudioDevice();

    goal_sound = LoadSound("data/sounds/goal.wav");
    exit_sound = LoadSound("data/sounds/exit.wav");
}

void unload_sounds() {
    UnloadSound(goal_sound);
    UnloadSound(exit_sound);

    CloseAudioDevice();
}

void play_sound(Sound sound) {
    PlaySound(sound);
}

#endif // SOUNDS_H
