/*
WIP
Nao esquecam de apertar f5 para fazer a build e linkar tudo. Nao deem CompileRun na Main(triangulo acima)
resource_dir.h foi cortesia do template
Utilizando Paint.Net para descobrir as medidas das imagens do resource
*/

#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include "animation.h"
#include "bomberman.h"
#include "bomb.h"
#include "screens.h"

static float accumulatedTime_1 = 0.0f;
static float accumulatedTime_2 = 0.0f;

int main ()
{
	// Declaring a rectangle to hold the spcs of the screen
	Rectangle screen = {0,0, SCREEN_WIDTH, SCREEN_HEIGHT};

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Teste");

	// Initalizing audio device
	InitAudioDevice();

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");
	// Loading the textures
	Texture background = LoadTexture("Bomberman_Stage_3.png");
	LoadBombermanTextures();
	// Declaring the players
	Bomberman player_1 = 
	{
		.bombermanAnimation=
		{
			.first = 0,
			.last = 3,
			.curr = 0,
			.frameTimer = 0.1,
			.type = ONESHOT
		},
		.position = {0,0},
		.alive = true,
		.bombermanText = white_bomberman_texture_right		
	};

	Bomberman player_2 = 
	{
		.bombermanAnimation=
		{
			.first = 0,
			.last = 3,
			.curr = 0,
			.frameTimer = 0.1,
			.type = ONESHOT
		},
		.position = {0,0},
		.alive = true,
		.bombermanText = black_bomberman_texture_left	
	};

	// Load a Music from the resources directory
	Music battle_music = LoadMusicStream("Naruto_Main_Theme.mp3");
	// Play Music
	PlayMusicStream(battle_music);
	// Setting Frame rate
	SetTargetFPS(60);
	// game loop
	while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or presses the Close button on the window
	{ 	
		// update the Game
		UpdateMusicStream(battle_music);

		SpriteAnimationUpdate(&player_1.bombermanAnimation, &accumulatedTime_1);
		SpriteAnimationUpdate(&player_2.bombermanAnimation, &accumulatedTime_2);

		UpdateMovement_1(&player_1);
		UpdateMovement_2(&player_2);

		// drawing the Game
		BeginDrawing();
		ClearBackground(RAYWHITE);
		// drawing an background
		DrawTexturePro(background,(Rectangle){0,0,272,208}, screen, (Vector2){0,0}, 0, WHITE);
		// draw texture to the screen
		/*DrawTextureRec(player_1.bombermanText, AnimationFrame(&player_1.bombermanAnimation,
		 BOMBERMAN_MOVEMENT_SPRITE, BOMBERMAN_HEIGHT, BOMBERMAN_WIDTH),
		 player_1.position, WHITE);*/
		DrawGame(player_1, player_2);
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}
	// cleanup
	// unload our texture so it can be cleaned up
	UnloadBombermanTextures();
	UnloadTexture(background);
	// unload our sound
	UnloadMusicStream(battle_music);
	// destroy the window and cleanup the OpenGL context
	CloseAudioDevice();
	CloseWindow();
	return 0;
}
