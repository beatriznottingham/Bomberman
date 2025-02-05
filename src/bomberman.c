#include "raylib.h"

#include "screens.h"
#include "bomberman.h"
#include "bomb.h"
//declaring the textures
Texture white_bomberman_texture_right;
Texture white_bomberman_texture_left;
Texture white_bomberman_texture_front;
Texture white_bomberman_texture_back;

Texture black_bomberman_texture_right;
Texture black_bomberman_texture_left;
Texture black_bomberman_texture_front;
Texture black_bomberman_texture_back;

// Loading textures from the resources directory
void LoadBombermanTextures(void)
{
    white_bomberman_texture_right = LoadTexture("bomberman_branco_direita.png");
    white_bomberman_texture_left = LoadTexture("bomberman_branco_esquerda.png");
    white_bomberman_texture_front = LoadTexture("bomberman_branco_frente.png");
    white_bomberman_texture_back = LoadTexture("bomberman_branco_costas.png");

	black_bomberman_texture_right = LoadTexture("bomberman_preto_direita.png");
    black_bomberman_texture_left = LoadTexture("bomberman_preto_esquerda.png");
    black_bomberman_texture_front = LoadTexture("bomberman_preto_frente.png");
    black_bomberman_texture_back = LoadTexture("bomberman_preto_costas.png");

	bomb_texture = LoadTexture("bomb.png");
}

void UnloadBombermanTextures(void)
{
    UnloadTexture(white_bomberman_texture_back);
    UnloadTexture(white_bomberman_texture_front);
    UnloadTexture(white_bomberman_texture_left);
    UnloadTexture(white_bomberman_texture_right);

	UnloadTexture(black_bomberman_texture_back);
    UnloadTexture(black_bomberman_texture_front);
    UnloadTexture(black_bomberman_texture_left);
    UnloadTexture(black_bomberman_texture_right);

	UnloadTexture(bomb_texture);
}

void UpdateMovement_1(Bomberman *player)
{
    if(IsKeyDown(KEY_RIGHT))
		{
			player->bombermanText = white_bomberman_texture_right;
			player->position.x += 2;
			SpriteAnimationShouldRepeat(&player->bombermanAnimation);		
		}
			if (player->position.x + (SCALE*BOMBERMAN_WIDTH/2)>= SCREEN_WIDTH)
				player->position.x = SCREEN_WIDTH - (SCALE*BOMBERMAN_WIDTH/2);

		if(IsKeyDown(KEY_LEFT))
		{
			player->bombermanText = white_bomberman_texture_left;
			player->position.x -= 2;
			SpriteAnimationShouldRepeat(&player->bombermanAnimation);
		}
			if ((player->position.x - BOMBERMAN_WIDTH) <= 0)
				player->position.x = BOMBERMAN_WIDTH;

		if(IsKeyDown(KEY_DOWN))
		{
			player->bombermanText = white_bomberman_texture_front;
			player->position.y += 2;
			SpriteAnimationShouldRepeat(&player->bombermanAnimation);
		}
			if (player->position.y + (SCALE*BOMBERMAN_HEIGHT/2)>= SCREEN_HEIGHT)
				player->position.y = SCREEN_HEIGHT - (SCALE*BOMBERMAN_HEIGHT/2);

		if(IsKeyDown(KEY_UP))
		{
			player->bombermanText = white_bomberman_texture_back;
			player->position.y -= 2;
			SpriteAnimationShouldRepeat(&player->bombermanAnimation);
		}
			if (player->position.y - BOMBERMAN_HEIGHT <= 0)
				player->position.y = BOMBERMAN_HEIGHT;
}

void UpdateMovement_2(Bomberman *player)
{
    if(IsKeyDown(KEY_D))
		{
			player->bombermanText = black_bomberman_texture_right;
			player->position.x += 2;
			SpriteAnimationShouldRepeat(&player->bombermanAnimation);		
		}
			if (player->position.x + (SCALE*BOMBERMAN_WIDTH/2)>= SCREEN_WIDTH)
				player->position.x = SCREEN_WIDTH - (SCALE*BOMBERMAN_WIDTH/2);

		if(IsKeyDown(KEY_A))
		{
			player->bombermanText = black_bomberman_texture_left;
			player->position.x -= 2;
			SpriteAnimationShouldRepeat(&player->bombermanAnimation);
		}
			if ((player->position.x - BOMBERMAN_WIDTH) <= 0)
				player->position.x = BOMBERMAN_WIDTH;

		if(IsKeyDown(KEY_S))
		{
			player->bombermanText = black_bomberman_texture_front;
			player->position.y += 2;
			SpriteAnimationShouldRepeat(&player->bombermanAnimation);
		}
			if (player->position.y + (SCALE*BOMBERMAN_HEIGHT/2)>= SCREEN_HEIGHT)
				player->position.y = SCREEN_HEIGHT - (SCALE*BOMBERMAN_HEIGHT/2);

		if(IsKeyDown(KEY_W))
		{
			player->bombermanText = black_bomberman_texture_back;
			player->position.y -= 2;
			SpriteAnimationShouldRepeat(&player->bombermanAnimation);
		}
			if (player->position.y - BOMBERMAN_HEIGHT <= 0)
				player->position.y = BOMBERMAN_HEIGHT;
}

void DrawGame(Bomberman player_1, Bomberman player_2)
{
	Rectangle Source_1 = SpriteAnimationFrame(&player_1.bombermanAnimation, BOMBERMAN_MOVEMENT_SPRITE,
	 BOMBERMAN_HEIGHT, BOMBERMAN_WIDTH);
	
	DrawTexturePro(player_1.bombermanText, Source_1,
	 (Rectangle){(player_1.position.x - (BOMBERMAN_WIDTH/2)),(player_1.position.y - (BOMBERMAN_HEIGHT/2)),
	 SCALE*BOMBERMAN_WIDTH, SCALE*BOMBERMAN_HEIGHT},
	 (Vector2){(BOMBERMAN_WIDTH/2),(BOMBERMAN_HEIGHT/2)},0, WHITE);

	 Rectangle Source_2 = SpriteAnimationFrame(&player_2.bombermanAnimation, BOMBERMAN_MOVEMENT_SPRITE,
	 BOMBERMAN_HEIGHT, BOMBERMAN_WIDTH);

	 DrawTexturePro(player_2.bombermanText, Source_2,
	 (Rectangle){(player_2.position.x - (BOMBERMAN_WIDTH/2)),(player_2.position.y - (BOMBERMAN_HEIGHT/2)),
	 SCALE*BOMBERMAN_WIDTH, SCALE*BOMBERMAN_HEIGHT},
	 (Vector2){(BOMBERMAN_WIDTH/2),(BOMBERMAN_HEIGHT/2)},0, WHITE);
}