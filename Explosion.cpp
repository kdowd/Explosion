#include <iostream>
#include <vector>
#include <raylib.h>
#include <raylib-cpp-utils.hpp>


using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;

const int MAX_COLORS_COUNT = 21;

#define NUM_FRAMES_PER_LINE     5
#define NUM_LINES               4



int main()
{
	std::cout << "Hello World!\n";


	Color BackGroundColour = { 155,25,140,255 };
	SetTraceLogLevel(TraceLogLevel::LOG_NONE);

	InitWindow(screenWidth, screenHeight, "RAYGUNNED");
	SetTargetFPS(60);


	Texture2D egg = LoadTexture("pngegg.png");

	//192
	float frameWidth = (float)(egg.width / NUM_FRAMES_PER_LINE);
	//192
	float frameHeight = (float)(egg.height / NUM_LINES);
	int currentFrame = 0;
	int currentLine = 0;

	Rectangle frameRec = { 0, 0, frameWidth, frameHeight };
	Vector2 position = { 100.0f, 60.0f };

	bool active = false;
	int framesCounter = 0;
	Vector2 ballPosition = GetMousePosition();

	while (WindowShouldClose() == false) {
		ballPosition = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			cout << ballPosition.x;
		}

		if (IsKeyDown(KEY_SPACE)) {
			DrawText("Welcome To My Game, Suckers !!!!", 18, GetScreenHeight() - 30, 20, GOLD);
			DrawFPS(10, 10);
		}

		framesCounter++;

		if (framesCounter > 2)
		{
			currentFrame++;

			if (currentFrame >= NUM_FRAMES_PER_LINE)
			{
				currentFrame = 0;
				currentLine++;

				if (currentLine >= NUM_LINES)
				{
					currentLine = 0;
					active = false;
				}
			}

			framesCounter = 0;
		}

		BeginDrawing();
		//DrawTexture(egg, screenWidth / 2 - egg.width / 2, screenHeight / 2 - egg.height / 2, WHITE);
		DrawTextureRec(egg, frameRec, position, WHITE);

		frameRec.x = frameWidth * currentFrame;
		frameRec.y = frameHeight * currentLine;
		EndDrawing();

		ClearBackground(BackGroundColour);
	}

	CloseWindow();
}

