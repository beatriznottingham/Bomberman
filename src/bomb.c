#include "bomb.h"

Texture bomb_texture;

Bomb placeBomb(Vector2 Position)
{
    // Creates a bomb at the position parameter
    Bomb bomb =
    {
        .position = Position,
        .isActive = true,
        .bombTexture = bomb_texture,
        .lifeTime = 3.0f,
        .timer = 0.0f,
    };
 return bomb;
}

void UpdateBomb(Bomb *bomb) 
{
    if (bomb->isActive) 
    {
        bomb->timer += GetFrameTime(); // Increment timer by elapsed time
        // Check if the bomb has reached its timer limit
        if (bomb->timer >= bomb->lifeTime) 
            bomb->isActive = false; // Deactivate the bomb after lifeTime
    }
}

void DrawBomb(Bomb *bomb) 
{
    if (bomb->isActive) 
    {
        DrawTexture(bomb->bombTexture, bomb->position.x, bomb->position.y, WHITE); // Draw bomb
    }
}


