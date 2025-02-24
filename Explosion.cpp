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

void debugMousePos() {

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 ballPosition = GetMousePosition();
		ballPosition = GetMousePosition();
		cout << ballPosition.x << " -- " << ballPosition.y << endl;
	}

};

void showMessage() {
	if (IsKeyDown(KEY_SPACE)) {
		DrawText("All your base are belong to us, Suckers !!!!", 18, GetScreenHeight() - 30, 20, GOLD);
		DrawFPS(10, 10);
	}
}

int main()
{
	Color BackGroundColour = { 155,25,140,255 };
	SetTraceLogLevel(TraceLogLevel::LOG_NONE);

	InitWindow(screenWidth, screenHeight, "RAYGUNNED");
	SetTargetFPS(60);


	Texture2D egg = LoadTexture("pngegg.png");

	//192 for this image
	float frameWidth = (float)(egg.width / NUM_FRAMES_PER_LINE);
	//192
	float frameHeight = (float)(egg.height / NUM_LINES);
	int currentFrame = 0;
	int currentLine = 0;

	Rectangle frameRec = { 0, 0, frameWidth, frameHeight };
	Vector2 position = { 100.0f, 60.0f };

	bool active = false;
	int framesCounter = 0;


	while (WindowShouldClose() == false) {
		debugMousePos();
		showMessage();

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

		DrawTextureRec(egg, frameRec, position, WHITE);
		frameRec.x = frameWidth * currentFrame;
		frameRec.y = frameHeight * currentLine;

		EndDrawing();

		// clear game area and draw background colour
		ClearBackground(BackGroundColour);
	}

	CloseWindow();
}

