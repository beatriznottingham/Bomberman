#ifndef BOMB_H_
#define BOMB_H_

#include "raylib.h"

#include "animation.h"

#define BOMB_WIDTH 16
#define BOMB_HEIGHT 18

extern Texture bomb_texture;

typedef struct
{
    Vector2 position;      // Position of the bomb
    Texture2D bombTexture;    // Texture for the bomb
    float timer;          // Time elapsed since bomb was placed
    float lifeTime;       // Lifetime of the bomb in seconds
    bool isActive;          // Whether the bomb is still active (being drawn)
} Bomb;

Bomb placeBomb(Vector2 position);

void UpdateBomb(Bomb *bomb);

void DrawBomb(Bomb *bomb);

#endif